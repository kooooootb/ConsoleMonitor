#ifndef MAIN_CP_H
#define MAIN_CP_H

#include "BaseCommand.h"

class Cp : public BaseCommand {
private:
    int length = 0;
    std::string filename;

    static constexpr char WRONGKEYSAMOUNT[] = "invalid key values amount";
    static constexpr char WRONGPOSSAMOUNT[] = "invalid positional values amount";
    static constexpr char LENGTHCANTCONVERT[] = "length incorrect value";
    static constexpr char LENGTHRESTRICTED[] = "length incorrect value";
    static constexpr char NOLENGTHVALUE[] = "no length key value";
    static constexpr char NOFILENAMEVALUE[] = "no file name was provided";
    static constexpr char INCORRECTFILENAME[] = "label value is incorrect";

    const char *checkAmount(const Parser &parser);

    const char *setLength(const keyArgs_t &keys);
    const char *setFilename(posArgs_t &poss);
public:
    explicit Cp(std::ostream &ostream_);

    const char *checkAndAssemble(Parser &parser) final;
    int run() final;
};


#endif //MAIN_CP_H
