#include <fstream>

#include "Monitor.h"
#include "MonitorHelp.h"
#include "utilFunctions.h"
#include "CommandFactory.h"
#include "ParserException.h"

Monitor::Monitor(std::istream &istream_, std::ostream &ostream_) : istream(istream_) , ostream(ostream_) {}

bool Monitor::processInput() {
    std::string query;
    std::getline(istream, query); // get line from stream
    if(istream.eof()){
        return false;
    } else{
        std::shared_ptr<Parser> parser;
        try{
            parser = std::make_shared<Parser>(Parser(query));
        } catch(ParserException &ex){
            ostream << ex.what() << std::endl;
            return true;
        }

        bool continuing = true;
        std::string &commandString = parser->getCommand();
        if(commandString == "exit"){ // check if exiting
            continuing = false;
        } else if(commandString == "help"){ // check if requesting help
            help();
        } else { // do command thing
            std::shared_ptr<BaseCommand> command = CommandFactory::getCommand(commandString, std::ref(ostream));
            if (command == nullptr) { // if command doesn't exist
                printError("Command " + commandString + " doesn't exist");
                help();
            } else { // run command
                command->processQuery(*parser);
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
