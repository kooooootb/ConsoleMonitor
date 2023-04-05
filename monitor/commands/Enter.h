#ifndef MAIN_ENTER_H
#define MAIN_ENTER_H

#include "BaseCommand.h"

class Enter : public BaseCommand {
private:
    int length = 0;
    std::string filename;

    const char *checkAmount(const Parser &parser);

    const char *setLength(const keyArgs_t &keys);
    const char *setFilename(posArgs_t &poss);
public:
    explicit Enter(std::ostream &ostream_);

    const char *checkAndAssemble(Parser &parser) final;
    int run() final;
};

#endif //MAIN_ENTER_H
