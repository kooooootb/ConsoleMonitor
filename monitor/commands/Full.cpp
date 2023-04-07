#include "Full.h"
#include "utilFunctions.h"

Full::Full(std::ostream &ostream_) : BaseCommand(CommandsList::FULL, ostream_) {}

const std::string Full::query = "full";

const char *Full::checkAndAssemble(Parser &parser) {
    const char *errorMessage;

    if((errorMessage = checkAmount(parser)) != nullptr) return errorMessage;

    setEmpty(parser.getBoolArgs());
    setHeader(parser.getBoolArgs());
    setHeaderonly(parser.getBoolArgs());

    return errorMessage;
}

const char *Full::checkAmount(const Parser &parser) {
    if(parser.getBoolArgs().size() > 3){
        return WRONGBOOLSAMOUNT;
    }

    return nullptr;
}

void Full::setEmpty(const boolArgs_t &bools) {
    findAndSetBoolArg(bools, empty, "empty", "e");
}

void Full::setHeader(const boolArgs_t &bools) {
    findAndSetBoolArg(bools, header, "header", "h");
}

void Full::setHeaderonly(const boolArgs_t &bools) {
    findAndSetBoolArg(bools, headeronly, "headeronly", "o");
}

int Full::run() {
    // return fs_full(empty, header, headeronly);
    ostream << "full command executed, empty: \"" << empty <<
            "\", header: \"" << header << "\", headeronly: \"" << headeronly << "\"" << std::endl;
    return 0;
}
