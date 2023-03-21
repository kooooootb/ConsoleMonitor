#include <fstream>

#include "Monitor.h"
#include "utilFunctions.h"

Monitor::Monitor(std::istream &istream_, std::ostream &ostream_) : istream(istream_) , ostream(ostream_) {}

bool Monitor::processInput() {
    std::string query;
    std::getline(istream, query);
    if(istream.eof()){
        return false;
    } else{
        std::pair<std::string, std::string> divided = std::move(divideQuery(query));
        toLower(divided.first);

        if(divided.first == "exit"){
            return false;
        } else if(divided.first == "help"){
            help();
            return true;
        } else {
            std::shared_ptr<BaseCommand> command = BaseCommand::parseCommand(divided.first, ostream);
            if (command == nullptr) {
                printError("Command " + divided.first + " doesn't exist");
                help();
                return true;
            } else {
                command->processQuery(divided.second);
                return true;
            }
        }
    }
}

std::pair<std::string, std::string> Monitor::divideQuery(const std::string &query){
    int index = 0;
    while(index < query.size() && isWhitespace(query[index])){
        index += 1;
    }

    int divideIndex = index;
    while(divideIndex < query.size() && !isWhitespace(query[divideIndex])){
        divideIndex += 1;
    }

    return { query.substr(index, divideIndex), query.substr(divideIndex, query.size()) };
}

std::ostream &Monitor::help() {
    return showHelp(ostream, (int) BaseCommand::Commands::COMMANDSAMOUNT);
}

void Monitor::showPrompt() {
    ostream << PROMPT << std::flush;
}

void Monitor::run() {
    do{
        showPrompt();
    }while(processInput());
}

std::ostream &Monitor::printError(const std::string &message) {
    return ostream << message << std::endl;
}
