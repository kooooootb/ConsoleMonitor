#include "Empty.h"
#include "utilFunctions.h"

Empty::Empty(std::ostream &ostream_) : BaseCommand(CommandsList::EMPTY, ostream_) {}

const std::string Empty::query = "empty";

const char *Empty::checkAndAssemble(Parser &parser) {
    return nullptr; // always correct
}

int Empty::run() {
    // return fs_blackhole();
    ostream << "empty command executed" << std::endl;
    return 0;
}
