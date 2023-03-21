#include <fstream>

#include "CommandHeaders.h"
#include "utilFunctions.h"
#include "ParserException.h"

BaseCommand::BaseCommand(Commands commandType_, std::ostream &ostream_):
ostream(ostream_) , commandType(commandType_) {}

std::ostream &BaseCommand::help() {
    return showHelp(ostream, (int) commandType);
}

void BaseCommand::processQuery(const std::string &query) {
    Parser *parser;

    try{
        parser = new Parser(query);
    } catch(ParserException &ex){
        ostream << ex.what() << std::endl;
        return;
    }

    if(parser->getKeyArgs().contains("help")){
        help();
    } else if(checkAndAssemble(*parser)) { // parser becomes invalid here
        run();
    }

    delete parser;
}

void BaseCommand::printAssemblyError(const char *info) {
    ostream << "Error generated while processing input: " << info << std::endl;
    help();
}

std::shared_ptr<BaseCommand> BaseCommand::parseCommand(std::string &commandQuery, std::ostream &ostream) {
    if(commandQuery == "init"){
        return std::make_shared<Init>(ostream);
//    } else if(commandQuery == "full"){
//        return std::make_shared<Full>(ostream);
    } else {
        return nullptr; // can't find appropriate command
    }
}

BaseCommand::Commands BaseCommand::getCommand() const {
    return commandType;
}
