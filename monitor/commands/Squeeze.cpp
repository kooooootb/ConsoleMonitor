#include "Squeeze.h"

Squeeze::Squeeze(std::ostream &ostream_) : BaseCommand(CommandsList::SQUEZZE, ostream_) {}

const std::string Squeeze::query = "squeeze";

const char *Squeeze::checkAndAssemble(Parser &parser) {
    return nullptr; // always correct
}

int Squeeze::run() {
    // return fs_squeeze();
    ostream << "squeeze command executed" << std::endl;
    return 0;
}
