#ifndef MAIN_ENTER_H
#define MAIN_ENTER_H

#include "BaseCommand.h"

class Enter : public BaseCommand {
private:
    int length = 0;
    std::string filename;

    static constexpr char WRONGKEYSAMOUNT[] = "invalid key values amount";
    static constexpr char WRONGPOSSAMOUNT[] = "invalid positional values amount";
    static constexpr char LENGTHCANTCONVERT[] = "length incorrect value";
    static constexpr char LENGTHRESTRICTED[] = "length incorrect value";
    static constexpr char NOLENGTHVALUE[] = "no length key value";
    static constexpr char INCORRECTFILENAME[] = "label value is incorrect";

    const char *checkAmount(const Parser &parser);

    const char *setLength(const keyArgs_t &keys);
    const char *setFilename(posArgs_t &poss);
public:
    explicit Enter(std::ostream &ostream_);

    static const std::string query;

    const char *checkAndAssemble(Parser &parser) final;
    int run() final;
};

#endif //MAIN_ENTER_H
