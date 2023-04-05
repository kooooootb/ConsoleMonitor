#include "Full.h"
#include "utilFunctions.h"

Full::Full(std::ostream &ostream_) : BaseCommand(CommandsList::FULL, ostream_) {}

const char *Full::checkAndAssemble(Parser &parser) {
    const char *errorMessage;

    if((errorMessage = checkAmount(parser)) != nullptr) return errorMessage;

    setEmpty(parser.getPosArgs());
    setHeader(parser.getPosArgs());
    setHeaderonly(parser.getPosArgs());

    return errorMessage;
}

const char *Full::checkAmount(const Parser &parser) {
    if(parser.getPosArgs().size() > 3){
        return "invalid boolean values amount";
    }

    return nullptr;
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
