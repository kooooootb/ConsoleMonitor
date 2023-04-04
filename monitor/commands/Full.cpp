#include "Full.h"
#include "utilFunctions.h"

Full::Full(std::ostream &ostream_) : BaseCommand(CommandsList::FULL, ostream_) {}

bool Full::checkAndAssemble(Parser &parser) {
    if(!checkAmount(parser)) return false;

    setEmpty(parser.getPosArgs());
    setHeader(parser.getPosArgs());
    setHeaderonly(parser.getPosArgs());

    return true;
}

bool Full::checkAmount(const Parser &parser) {
    if(parser.getPosArgs().size() > 3){
        printAssemblyError("invalid boolean values amount");
        return false;
    }

    return true;
}

void Full::setEmpty(const posArgs_t &bools) {
    findAndSetBoolArg(bools, empty, "empty", "e");
}

void Full::setHeader(const posArgs_t &bools) {
    findAndSetBoolArg(bools, header, "header", "h");
}

void Full::setHeaderonly(const posArgs_t &bools) {
    findAndSetBoolArg(bools, headeronly, "headeronly", "o");
}

int Full::run() {
    // return fs_full(empty, header, headeronly);
    ostream << "full command executed, empty: \"" << empty <<
            "\", header: \"" << header << "\", headeronly: \"" << headeronly << "\"" << std::endl;
    return 0;
}
