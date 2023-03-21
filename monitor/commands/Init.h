#ifndef MAIN_INIT_H
#define MAIN_INIT_H

#include "BaseCommand.h"

class Init : public BaseCommand {
private:
    int blocks = 0;
    int segments = 0;
    std::string label;

    static constexpr int KEYS = 2;
    static constexpr int BOOLS = 0;
    static constexpr int VALUES = 1;
    static constexpr char DEFAULTLABEL[] = "DEFAULT";

   bool checkAmount(const Parser &parser);

   bool setBlocks(const keyArgs_t &keys);
   bool setSegments(const keyArgs_t &keys);
   bool setLabel(posArgs_t &poss);
public:
    explicit Init(std::ostream &ostream_);

    bool checkAndAssemble(Parser &parser) final;
    int run() final;
};


#endif //MAIN_INIT_H
