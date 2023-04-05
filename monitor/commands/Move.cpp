#include "Move.h"
#include "utilFunctions.h"

Move::Move(std::ostream &ostream_) : BaseCommand(CommandsList::MOVE, ostream_) {}

const char *Move::checkAndAssemble(Parser &parser) {
    const char *errorMessage;

    if((errorMessage = checkAmount(parser)) != nullptr) return errorMessage;

    if((errorMessage = setOldFile(parser.getPosArgs())) != nullptr) return errorMessage;
    if((errorMessage = setNewFile(parser.getPosArgs())) != nullptr) return errorMessage;

    return errorMessage;
}

const char *Move::checkAmount(const Parser &parser) {
    if(parser.getPosArgs().size() != 2){
        return WRONGPOSSAMOUNT;
    }

    return nullptr;
}

const char *Move::setOldFile(posArgs_t &poss) {
    oldFile = std::move(poss.back());
    poss.pop_back();

    if(oldFile.empty()){
        return INCORRECTOLDFILE;
    }

    return nullptr;
}

const char *Move::setNewFile(posArgs_t &poss) {
    newFile = std::move(poss.back());
    poss.pop_back();

    if(newFile.empty()){
        return INCORRECTNEWFILE;
    }

    return nullptr;
}

int Move::run() {
    // return fs_init(blocks, segments, label);
    ostream << "move command executed, old file: \"" << oldFile <<
            "\", new file: \"" << newFile << "\"" << std::endl;
    return 0;
}
