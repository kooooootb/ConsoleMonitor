#include "Enter.h"
#include "utilFunctions.h"

Enter::Enter(std::ostream &ostream_) : BaseCommand(CommandsList::ENTER, ostream_) {}

const char *Enter::checkAndAssemble(Parser &parser) {
    const char *errorMessage;

    if((errorMessage = checkAmount(parser)) != nullptr) return errorMessage;

    if((errorMessage = setLength(parser.getKeyArgs())) != nullptr) return errorMessage;
    if((errorMessage = setFilename(parser.getPosArgs())) != nullptr) return errorMessage;

    return errorMessage;
}

const char *Enter::checkAmount(const Parser &parser) {
    if(parser.getKeyArgs().size() != 1){
        return "invalid key values amount";
    }
    if(parser.getPosArgs().size() != 1){
        return "invalid positional values amount";
    }

    return nullptr;
}

const char *Enter::setLength(const keyArgs_t &keys) {
    const char *errorMessage = nullptr;

    if(auto it = keys.find("length"); it != keys.end() || ((it = keys.find("l")) != keys.end())) {
        // convert to int
        if(convertToNumber(it->second, length)) return "length incorrect value";

        // check restrictions
        if(length < 1 || 65535 < length){
            return "length incorrect value";
        }
    } else {
        return "no blocks key value";
    }

    return nullptr;
}

const char *Enter::setFilename(posArgs_t &poss) {
    if(poss.empty()){
        return "no file name was provided";
    }

    filename = std::move(poss.back());
    if(filename.size() > 10 || !isASCII(filename)){
        return "label value is incorrect";
    }

    return nullptr;
}

int Enter::run() {
    // return fs_init(blocks, segments, label);
    ostream << "enter command executed, length: \"" << length <<
            "\", filename: \"" << filename << "\"" << std::endl;
    return 0;
}
