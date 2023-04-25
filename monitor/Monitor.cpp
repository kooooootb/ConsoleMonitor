#include <fstream>
#include <iostream>

#include "Monitor.h"
#include "MonitorHelp.h"
#include "utilFunctions.h"
#include "CommandFactory.h"
#include "ParserException.h"

Monitor::Monitor(std::istream &istream_, std::ostream &ostream_, bool echoing_) {
    // init in out objs
    if(echoing_){
        outputer = std::make_unique<MonitorOutput>(ostream_, std::cout);
        inputer = std::make_unique<MonitorInput>(istream_, std::vector{ &std::cout, &ostream_});
    } else{
        outputer = std::make_unique<MonitorOutput>(ostream_);
        inputer = std::make_unique<MonitorInput>(istream_);
    }
}

bool Monitor::processInput() {
    std::string query = inputer->getline();

    if(query.empty() && inputer->eof()){
        return false;
    } else{
        std::shared_ptr<Parser> parser = getParser(query);
        if(parser == nullptr) return true;

        std::string &commandString = parser->getCommand();

        if(commandString == "exit"){ // check if exiting
            return false;
        } else { // do command thing
            // make command object
            std::shared_ptr<BaseCommand> command = CommandFactory::getCommand(commandString);

            if (command == nullptr) { // if command doesn't exist
                *outputer << "Command " + commandString + " doesn't exist" << "\n";
                printHelp();
            } else { // run command
                std::string message = command->processQuery(*parser);
                *outputer << message << "\n";
            }
        }

        return true;
    }
}

void Monitor::printHelp() const {
    *outputer << MonitorHelp::getMessage() << "\n";
}

void Monitor::showPrompt() const {
    *outputer << PROMPT;
}

void Monitor::run() {
    do{
        showPrompt();
    }while(processInput());

    *outputer << MONITOR_EXIT_MESSAGE;
}

std::shared_ptr<Parser> Monitor::getParser(const std::string &query) const {
    try{
        return std::make_shared<Parser>(Parser(query));
    } catch(ParserException &ex){
        *outputer << ex.what() << "\n";
        printHelp();
        return nullptr;
    }
}
