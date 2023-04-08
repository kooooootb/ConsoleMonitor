#include "Help.h"

Help::Help(std::ostream &ostream_) : BaseCommand(CommandsList::HELP, ostream_) {}

const std::string Help::query = "help";

const char *Help::checkAndAssemble(Parser &parser) {
    return nullptr; // always correct
}

int Help::run() {
    ostream << helpMessage << std::endl;
    return 0;
}
