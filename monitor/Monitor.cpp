#include <fstream>

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
        std::shared_ptr<Parser> parser;
        try{
            parser = std::make_shared<Parser>(Parser(query));
        } catch(ParserException &ex){
            ostream << ex.what() << std::endl;
            help();
            return true;
        }

        bool continuing = true;
        std::string &commandString = parser->getCommand();
        if(commandString == "exit"){ // check if exiting
            continuing = false;
        } else { // do command thing
            std::shared_ptr<BaseCommand> command = CommandFactory::getCommand(commandString, std::ref(ostream));
            if (command == nullptr) { // if command doesn't exist
                printError("Command " + commandString + " doesn't exist");
                help();
            } else { // run command
                const char *errorMessage = command->processQuery(*parser);
                if(errorMessage != nullptr) ostream << errorMessage << std::endl;
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
        ostream << query << std::endl;
    }
}
