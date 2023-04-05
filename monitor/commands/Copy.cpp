#include "Copy.h"
#include "utilFunctions.h"

Copy::Copy(std::ostream &ostream_) : BaseCommand(CommandsList::COPY, ostream_) {}

const char *Copy::checkAndAssemble(Parser &parser) {
    const char *errorMessage;

    if((errorMessage = checkAmount(parser)) != nullptr) return errorMessage;

    if((errorMessage = setNewFile(parser.getPosArgs())) != nullptr) return errorMessage;
    if((errorMessage = setOldFile(parser.getPosArgs())) != nullptr) return errorMessage;

    return errorMessage;
}

const char *Copy::checkAmount(const Parser &parser) {
    if(parser.getPosArgs().size() != 2){
        return WRONGPOSSAMOUNT;
    }

    return nullptr;
}

const char *Copy::setOldFile(posArgs_t &poss) {
    oldFile = std::move(poss.back());
    poss.pop_back();

    if(oldFile.empty()){
        return INCORRECTOLDFILE;
    }

    return nullptr;
}

const char *Copy::setNewFile(posArgs_t &poss) {
    newFile = std::move(poss.back());
    poss.pop_back();

    if(newFile.empty()){
        return INCORRECTNEWFILE;
    }

    return nullptr;
}

int Copy::run() {
    // return fs_init(blocks, segments, label);
    ostream << "copy command executed, old file: \"" << oldFile <<
            "\", new file: \"" << newFile << "\"" << std::endl;
    return 0;
}
