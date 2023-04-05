#ifndef MAIN_INIT_H
#define MAIN_INIT_H

#include "BaseCommand.h"

class Init : public BaseCommand {
private:
    int blocks = 0;
    int segments = 0;
    std::string label;

    static constexpr char DEFAULTLABEL[] = "DEFAULT";

    static constexpr char WRONGKEYSAMOUNT[] = "invalid key values amount";
    static constexpr char WRONGPOSSAMOUNT[] = "invalid positional values amount";
    static constexpr char BLOCKSCANTCONVERT[] = "blocks incorrect value";
    static constexpr char BLOCKSRESTRICTED[] = "blocks incorrect value";
    static constexpr char NOBLOCKSVALUE[] = "no blocks key value";
    static constexpr char SEGMENTSCANTCONVERT[] = "segments incorrect value";
    static constexpr char SEGMENTSRESTRICTED[] = "segments incorrect value";
    static constexpr char NOSEGMENTSVALUE[] = "no segments key value";
    static constexpr char LABELINCORRECT[] = "label value is incorrect";

    const char *checkAmount(const Parser &parser);

    const char *setBlocks(const keyArgs_t &keys);
    const char *setSegments(const keyArgs_t &keys);
    const char *setLabel(posArgs_t &poss);
public:
    explicit Init(std::ostream &ostream_);

    const char *checkAndAssemble(Parser &parser) final;
    int run() final;
};


#endif //MAIN_INIT_H
