#include <fstream>
#include <iostream>

#include "Monitor.h"
#include "MonitorHelp.h"
#include "utilFunctions.h"
#include "CommandFactory.h"
#include "ParserException.h"

Monitor::Monitor(std::istream &istream_, std::ostream &ostream_, bool echoing_) :
istream(istream_) , ostream(ostream_) , echoing(echoing_) {}

bool Monitor::processInput() {
    std::string query;
    getInput(query);

    if(istream.eof()){
        return false;
    } else{
        std::shared_ptr<Parser> parser = getParser(query);
        if(parser == nullptr) return true;

        bool continuing = true;
        std::string &commandString = parser->getCommand();

        if(commandString == "exit"){ // check if exiting
            continuing = false;
        } else { // do command thing
            // make command object
            std::shared_ptr<BaseCommand> command = CommandFactory::getCommand(commandString);
            if (command == nullptr) { // if command doesn't exist
                printError("Command " + commandString + " doesn't exist");
                help();
            } else { // run command
                std::string errorMessage = command->processQuery(*parser);
                if(errorMessage.empty()) ostream << errorMessage << std::endl;
            }
        }

        return continuing;
    }
}

std::ostream &Monitor::help() {
    return ostream << MonitorHelp::getMessage() << std::endl;
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

void Monitor::getInput(std::string &query) {
    std::getline(istream, query);
    if(echoing){
        std::cout << query << std::endl;
    }
}

std::shared_ptr<Parser> Monitor::getParser(const std::string &query) {
    try{
        return std::make_shared<Parser>(Parser(query));
    } catch(ParserException &ex){
        ostream << ex.what() << std::endl;
        help();
        return nullptr;
    }
}
