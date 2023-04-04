#include <stdexcept>
#include <functional>

#include "Parser.h"
#include "utilFunctions.h"
#include "ParserException.h"

Parser::Parser(const std::string &query){
    parseInput(query);

}

void Parser::parseInput(const std::string &input){
    int index = 0;
    while(index < input.size() && isWhitespace(input[index])){
        index += 1;
    }

    int divideIndex = index;
    while(divideIndex < input.size() && !isWhitespace(input[divideIndex])){
        divideIndex += 1;
    }

    parseCommand(toLower(input.substr(index, divideIndex)));
    parseArguments(toLower(input.substr(divideIndex, input.size())));
}

void Parser::parseCommand(std::string input){
    command = std::move(input);
}

void Parser::parseArguments(std::string input) {
    size_t index = 0;
    bool gotKey = false;
    std::string key;

    while(index < input.size()) { // key values
        if (isWhitespace(input[index])) {
            index += 1;
        } else if (gotKey) {
            if (input[index] == '-') { // key is bool arg
                posArgs.push_back(key);
            } else { // got value for a key
                int value = parseKeyValue(input, index);
                keyArgs[key] = value;
            }
            gotKey = false;
        } else if (input[index] == '-') { // if key
            key = std::move(parseKey(input, index));
            gotKey = true;
        } else {
            posArgs.push_back(std::move(parseWord(input, index)));
        }
    }

    if(gotKey){ // postprocess boolean value
        posArgs.push_back(key);
    }
}

std::string Parser::parseWord(const std::string &input, size_t &index){
    bool withQuotes = input[index] == '\"';
    if(withQuotes) {
        index += 1;
    }
    size_t end = index;

    while(end < input.size() && (!withQuotes && !isWhitespace(input[end]) || withQuotes && input[end] != '\"')){
        end += 1;
    }

    if(end == index){ // if letter after end or i dunno, it works and i wont touch it. UPD if quote is the last character
        throw ParserException("empty word");
    }
    if(withQuotes && input.size() <= end){ // if we got to the end and there is no second quote
        throw ParserException("missed pairing quote");
    }

    std::string result = input.substr(index, end - index);
    index = end + (withQuotes ? 1 : 0);
    return result;
}

keyArgs_t::key_type Parser::parseKey(const std::string &input, size_t &index){
    // we are at the first dash symbol
    index += 1;
    if(index >= input.size() || isWhitespace(input[index])) throw ParserException("key syntax error (got standalone dash)");
    if(input[index] == '-'){ // long key
        index += 1;
        return std::move(parseWord(input, index));
    } else{ // symbol key
        index += 1;
        if(!isWhitespace(input[index])) throw ParserException("key syntax error (got single dash on long key)");
        return { input[index-1] };
    }
}

keyArgs_t::mapped_type Parser::parseKeyValue(const std::string &input, size_t &index){
    std::string strValue = parseWord(input, index);
    try{
        keyArgs_t::mapped_type value = std::stoi(strValue);
        return value;
    } catch(std::out_of_range const &ex){
        throw ParserException("wrong key value");
    } catch(std::invalid_argument const &ex){
        throw ParserException("wrong key value");
    }
}
