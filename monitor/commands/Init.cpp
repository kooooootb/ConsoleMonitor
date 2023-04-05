#include "Init.h"
#include "utilFunctions.h"

Init::Init(std::ostream &ostream_) : BaseCommand(CommandsList::INIT, ostream_) {}

const char *Init::checkAndAssemble(Parser &parser) {
    const char *errorMessage;

    if((errorMessage = checkAmount(parser)) != nullptr) return errorMessage;

    if((errorMessage = setBlocks(parser.getKeyArgs())) != nullptr) return errorMessage;
    if((errorMessage = setSegments(parser.getKeyArgs())) != nullptr) return errorMessage;
    if((errorMessage = setLabel(parser.getPosArgs())) != nullptr) return errorMessage;

    return errorMessage;
}

const char *Init::checkAmount(const Parser &parser) {
    if(parser.getKeyArgs().size() != 2){
        return "invalid key values amount";
    }
    if(parser.getPosArgs().size() > 1){
        return "invalid positional values amount";
    }

    return nullptr;
}

const char *Init::setBlocks(const keyArgs_t &keys) {
    if(auto it = keys.find("blocks"); it != keys.end() || ((it = keys.find("b")) != keys.end())) {
        // convert to int
        if(convertToNumber(it->second, blocks)) return "blocks incorrect value";

        // check restrictions
        if (blocks < 1 || 65535 < blocks) {
            return "blocks incorrect value";
        }
    } else {
        return "no blocks key value";
    }

    return nullptr;
}

const char *Init::setSegments(const keyArgs_t &keys) {
    if(auto it = keys.find("segments"); it != keys.end() || ((it = keys.find("s")) != keys.end())){
        // convert to int
        if (convertToNumber(it->second, segments)) return "segments incorrect value";

        // check restrictions
        if(segments < 1 || 31 < segments){
            return "segments incorrect value";
        }
    } else {
        return "no segments key value";
    }

    return nullptr;
}

const char *Init::setLabel(posArgs_t &poss) {
    label = poss.empty() ? DEFAULTLABEL : std::move(poss.front()); // label is optional
    if(label.size() > 10 || !isASCII(label)){
        return "label value is incorrect";
    }

    return nullptr;
}

int Init::run() {
    // return fs_init(blocks, segments, label);
    ostream << "init command executed, blocks: \"" << blocks <<
        "\", segments: \"" << segments << "\", label: \"" << label << "\"" << std::endl;
    return 0;
}
