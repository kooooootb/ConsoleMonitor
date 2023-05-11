#include <sstream>

#include "Init.h"
#include "utils/utilFunctions.h"

//Init::Init() = default;

std::string Init::getQuery(){
    return "init";
}

std::string Init::checkAndAssemble(Parser &parser) {
    std::string errorMessage;

    if(errorMessage = checkAmount(parser); !errorMessage.empty()) return errorMessage;

    if(errorMessage = setBlocks(parser.getKeyArgs()); !errorMessage.empty()) return errorMessage;
    if(errorMessage = setSegments(parser.getKeyArgs()); !errorMessage.empty()) return errorMessage;
    if(errorMessage = setLabel(parser.getPosArgs()); !errorMessage.empty()) return errorMessage;

    return errorMessage;
}

std::string Init::checkAmount(const Parser &parser) {
    if(parser.getKeyArgs().size() != 2){
        return WRONGKEYSAMOUNT;
    }
    if(parser.getPosArgs().size() > 1){
        return WRONGPOSSAMOUNT;
    }

    return "";
}

std::string Init::setBlocks(const keyArgs_t &keys) {
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

    return "";
}

std::string Init::setSegments(const keyArgs_t &keys) {
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

    return "";
}

std::string Init::setLabel(posArgs_t &poss) {
    label = poss.empty() ? DEFAULTLABEL : std::move(poss.back()); // label is optional
    poss.pop_back();

    if(label.size() > 10 || !isASCII(label)){
        return LABELINCORRECT;
    }

    return "";
}

std::string Init::run() {
    // return fs_init(blocks, segments, label);
    std::stringstream str;
    str << "init command executed, blocks: \"" << blocks <<
        "\", segments: \"" << segments << "\", label: \"" << label << "\", s: \"" << s << "\"";
    return str.str();
}

std::string Init::help() {
    return "init help\ninit help second line";
}
