#include <algorithm>
#include <fstream>
#include <limits>
#include <cassert>

#include "utilFunctions.h"

bool isWhitespace(char symbol) {
    static constexpr char whitespaces[] = { ' ', '\t', '\0' };
    return std::any_of(std::begin(whitespaces), std::end(whitespaces), [symbol](char wp) -> bool {
        return symbol == wp;
    });
}

/**
 * Local function, skips line
 */
void skipLine(std::ifstream &hstr){
    hstr.ignore(std::numeric_limits<std::streamsize>::max(), hstr.widen('\n'));
}

/**
 * Local function, skips lines in help file
 */
void skipComments(std::ifstream &hstr){
    while(hstr.peek() == '#'){
        hstr.ignore(std::numeric_limits<std::streamsize>::max(), hstr.widen('\n'));
    }
}

/**
 * Local function, read line from help file
 */
void readHelp(std::ifstream &hstr, std::string &result){
    if(!std::getline(hstr, result)){
        assert(false && "help file is incorrect");
    }
}

std::ostream &showHelp(std::ostream &ostream, int index) {
    std::ifstream hstr(HELPFILENAME);
    assert(hstr.is_open() && "help file can't be found");

    skipComments(hstr); // skip comments

    while(index-- > 0){ // find our block of messages
        while(hstr.peek() != '/') {
            skipLine(hstr);
        }
        skipLine(hstr);
    }

    std::string line;
    while(hstr.peek() != '/') {
        readHelp(hstr, line);
        ostream << line << std::endl;
    }

    return ostream;
}

void toLower(std::string &text) {
    std::for_each(std::begin(text), std::end(text), [](char &symbol) -> void{
        symbol = static_cast<char>(std::tolower(symbol));
    }); // cast to lower case
}

std::string toLower(std::string &&text) {
    std::for_each(std::begin(text), std::end(text), [](char &symbol) -> void{
        symbol = static_cast<char>(std::tolower(symbol));
    }); // cast to lower case
    return text;
}

bool isASCII(const std::string &str){
    return !std::any_of(std::begin(str), std::end(str), [](const char character) -> bool {
        return character < 0;
    });
}
