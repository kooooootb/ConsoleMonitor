#include <sstream>

#include "Help.h"

Help::Help(std::string string) : inner(string) {}

std::string Help::getQuery(){
    return "help";
}

std::string Help::checkAndAssemble(Parser &parser) {
    return ""; // always correct
}

std::string Help::run() {
    return helpMessage;
}

std::string Help::help() {
    return helpMessage;
}
