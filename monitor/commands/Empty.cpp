#include "Empty.h"
#include "utilFunctions.h"

Empty::Empty(std::ostream &ostream_) : BaseCommand(CommandsList::EMPTY, ostream_) {}

const char *Empty::checkAndAssemble(Parser &parser) {
    return nullptr; // always correct
}

int Empty::run() {
    // return fs_blackhole();
    ostream << "blackhole command executed" << std::endl;
    return 0;
}
