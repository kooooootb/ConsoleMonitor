#include <sstream>

#include "Help.h"

Help::Help() : BaseCommand(CommandsList::HELP) {}

const std::string Help::query = "help";

std::string Help::checkAndAssemble(Parser &parser) {
    return ""; // always correct
}

std::string Help::run() {
    return helpMessage;
}
