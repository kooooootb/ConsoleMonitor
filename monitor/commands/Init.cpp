#include "Init.h"

Init::Init(std::ostream &ostream_) : BaseCommand(CommandsList::INIT, ostream_) {}

bool Init::checkAndAssemble(Parser &parser) {
    if(!checkAmount(parser)) return false;

    if(!setBlocks(parser.getKeyArgs())) return false;
    if(!setSegments(parser.getKeyArgs())) return false;
    if(!setLabel(parser.getPosArgs())) return false;

    return true;
}

bool Init::checkAmount(const Parser &parser) {
    if(parser.getKeyArgs().size() != 2){
        printAssemblyError("invalid key values amount");
        return false;
    }
    if(parser.getPosArgs().size() > 1){
        printAssemblyError("invalid positional values amount");
        return false;
    }

    return true;
}

bool Init::setBlocks(const keyArgs_t &keys) {
    if(auto it = keys.find("blocks"); it != keys.end() || ((it = keys.find("b")) != keys.end())){
        blocks = it->second;
        if(blocks < 1 || 65535 < blocks){
            printAssemblyError("blocks incorrect value");
            return false;
        }
    } else {
        printAssemblyError("no blocks key value");
        return false;
    }

    return true;
}

bool Init::setSegments(const keyArgs_t &keys) {
    if(auto it = keys.find("segments"); it != keys.end() || ((it = keys.find("s")) != keys.end())){
        segments = it->second;
        if(segments < 1 || 31 < segments){
            printAssemblyError("segments incorrect value");
            return false;
        }
    } else {
        printAssemblyError("no segments key value");
        return false;
    }

    return true;
}

bool Init::setLabel(posArgs_t &poss) {
    label = poss.empty() ? DEFAULTLABEL : std::move(poss.front()); // label is optional
    if(label.size() > 10 || std::any_of(std::begin(label), std::end(label), [](const char character) -> bool {
        return character < 0;
    })){

        printAssemblyError("label value is incorrect");
        return false;
    }

    return true;
}

int Init::run() {
    // return fs_init(blocks, segments, label);
    ostream << "init command executed, blocks: \"" << blocks <<
        "\", segments: \"" << segments << "\", label: \"" << label << "\"" << std::endl;
    return 0;
}
