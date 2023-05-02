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

void Monitor::printHelp() const {
    *outputer << MonitorHelp::getMessage() << "\n";
}

void Monitor::showPrompt() const {
    *outputer << PROMPT;
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
