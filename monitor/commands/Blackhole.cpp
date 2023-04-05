#include "Blackhole.h"
#include "utilFunctions.h"

Blackhole::Blackhole(std::ostream &ostream_) : BaseCommand(CommandsList::BLACKHOLE, ostream_) {}

const char *Blackhole::checkAndAssemble(Parser &parser) {
    return nullptr; // always correct
}

int Blackhole::run() {
    // return fs_blackhole();
    ostream << "blackhole command executed" << std::endl;
    return 0;
}
