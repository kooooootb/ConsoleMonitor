#ifndef MAIN_MOVE_H
#define MAIN_MOVE_H

#include "BaseCommand.h"

class Move : public BaseCommand {
private:
    std::string oldFile;
    std::string newFile;

    static constexpr char WRONGPOSSAMOUNT[] = "invalid positional values amount";
    static constexpr char INCORRECTOLDFILE[] = "old file name value is incorrect";
    static constexpr char INCORRECTNEWFILE[] = "new file name value is incorrect";

    const char *checkAmount(const Parser &parser);

    const char *setOldFile(posArgs_t &poss);
    const char *setNewFile(posArgs_t &poss);
public:
    explicit Move(std::ostream &ostream_);

    const char *checkAndAssemble(Parser &parser) final;
    int run() final;
};

#endif //MAIN_MOVE_H
