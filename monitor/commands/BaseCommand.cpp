#include "utilFunctions.h"
#include "ParserException.h"
#include "BaseCommand.h"
#include "CommandHelp.h"

BaseCommand::BaseCommand(CommandsList commandType_):
commandType(commandType_) {}

std::string BaseCommand::help() {
    return CommandHelp::getMessage(commandType);
}

std::string BaseCommand::processQuery(Parser &parser) {
    auto poss = parser.getBoolArgs();
    std::string resultMessage;

    if(std::find(std::begin(poss), std::end(poss), "help") != std::end(poss)){
        help();
    } else if(resultMessage = checkAndAssemble(parser); resultMessage.empty()) { // parser becomes invalid here, if no error
        resultMessage = run();
    }

    return resultMessage;
}

CommandsList BaseCommand::getCommandType() const{
    return commandType;
}
