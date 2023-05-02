#include <sstream>

#include "Help.h"

Help::Help() = default;

const std::string Help::query = "help";

std::string Help::checkAndAssemble(Parser &parser) {
    return ""; // always correct
}

std::string Help::run() {
    return helpMessage;
}

std::string Help::help() {
    return helpMessage;
}
