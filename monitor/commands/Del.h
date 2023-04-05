#ifndef MAIN_DEL_H
#define MAIN_DEL_H

#include "BaseCommand.h"

class Del : public BaseCommand {
private:
    std::string filename;

    static constexpr char WRONGPOSSAMOUNT[] = "invalid positional values amount";
    static constexpr char INCORRECTFILENAME[] = "file name value is incorrect";

    const char *checkAmount(const Parser &parser);

    const char *setFilename(posArgs_t &poss);
public:
    explicit Del(std::ostream &ostream_);

    const char *checkAndAssemble(Parser &parser) final;
    int run() final;
};

#endif //MAIN_DEL_H
