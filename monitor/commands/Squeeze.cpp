#include <sstream>

#include "Squeeze.h"

Squeeze::Squeeze() = default;

const std::string Squeeze::query = "squeeze";

std::string Squeeze::checkAndAssemble(Parser &parser) {
    return ""; // always correct
}

std::string Squeeze::run() {
    // return fs_squeeze();
    std::stringstream stream;
    stream << "squeeze command executed";
    return stream.str();
}

std::string Squeeze::help() {
    return "squeeze help";
}
