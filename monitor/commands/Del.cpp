#include "Del.h"
#include "utilFunctions.h"

Del::Del(std::ostream &ostream_) : BaseCommand(CommandsList::DEL, ostream_) {}

const std::string Del::query = "del";

const char *Del::checkAndAssemble(Parser &parser) {
    const char *errorMessage;

    if((errorMessage = checkAmount(parser)) != nullptr) return errorMessage;

    if((errorMessage = setFilename(parser.getPosArgs())) != nullptr) return errorMessage;

    return errorMessage;
}

const char *Del::checkAmount(const Parser &parser) {
    if(parser.getPosArgs().size() != 1){
        return WRONGPOSSAMOUNT;
    }

    return nullptr;
}

const char *Del::setFilename(posArgs_t &poss) {
    filename = std::move(poss.back());
    poss.pop_back();

    if(filename.empty()){
        return INCORRECTFILENAME;
    }

    return nullptr;
}

int Del::run() {
    // return fs_init(blocks, segments, label);
    ostream << "del command executed, file name: \"" << filename << "\"" << std::endl;
    return 0;
}
