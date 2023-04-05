#include <fstream>

#include "CommandFactory.h"
#include "utilFunctions.h"
#include "ParserException.h"
#include "BaseCommand.h"
#include "CommandHelp.h"

BaseCommand::BaseCommand(CommandsList commandType_, std::ostream &ostream_):
ostream(ostream_) , commandType(commandType_) {}

std::ostream &BaseCommand::help() {
    return ostream << CommandHelp::getMessage(commandType) << std::endl;
}

const char *BaseCommand::processQuery(Parser &parser) {
    auto poss = parser.getPosArgs();
    const char *errorMessage = nullptr;

    if(std::find(std::begin(poss), std::end(poss), "help") == std::begin(poss)){
        help();
    } else if((errorMessage = checkAndAssemble(parser)) == nullptr) { // parser becomes invalid here, if no error
        run();
    }

    return errorMessage;
}

void BaseCommand::printAssemblyError(const char *info) {
    ostream << "Error generated while processing input: " << info << std::endl;
    help();
}

CommandsList BaseCommand::getCommandType() const{
    return commandType;
}
