#include <sstream>

#include "Squeeze.h"

Squeeze::Squeeze() : BaseCommand(CommandsList::SQUEZZE) {}

const std::string Squeeze::query = "squeeze";

std::string Squeeze::checkAndAssemble(Parser &parser) {
    return ""; // always correct
}

std::string Squeeze::run() {
    // return fs_squeeze();
    std::stringstream stream;
    stream << "squeeze command executed" << std::endl;
    return stream.str();
}
