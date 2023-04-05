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
        return WRONGKEYSAMOUNT;
    }
    if(parser.getPosArgs().size() > 1){
        return WRONGPOSSAMOUNT;
    }

    return nullptr;
}

const char *Init::setBlocks(const keyArgs_t &keys) {
    if(auto it = keys.find("blocks"); it != keys.end() || ((it = keys.find("b")) != keys.end())) {
        // convert to int
        if(convertToNumber(it->second, blocks)) return BLOCKSCANTCONVERT;

        // check restrictions
        if (blocks < 1 || 65535 < blocks) {
            return BLOCKSRESTRICTED;
        }
    } else {
        return NOBLOCKSVALUE;
    }

    return nullptr;
}

const char *Init::setSegments(const keyArgs_t &keys) {
    if(auto it = keys.find("segments"); it != keys.end() || ((it = keys.find("s")) != keys.end())){
        // convert to int
        if (convertToNumber(it->second, segments)) return SEGMENTSCANTCONVERT;

        // check restrictions
        if(segments < 1 || 31 < segments){
            return SEGMENTSRESTRICTED;
        }
    } else {
        return NOSEGMENTSVALUE;
    }

    return nullptr;
}

const char *Init::setLabel(posArgs_t &poss) {
    label = poss.empty() ? DEFAULTLABEL : std::move(poss.back()); // label is optional
    poss.pop_back();

    if(label.size() > 10 || !isASCII(label)){
        return LABELINCORRECT;
    }

    return nullptr;
}

int Init::run() {
    // return fs_init(blocks, segments, label);
    ostream << "init command executed, blocks: \"" << blocks <<
        "\", segments: \"" << segments << "\", label: \"" << label << "\"" << std::endl;
    return 0;
}
