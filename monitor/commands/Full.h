#ifndef MAIN_FULL_H
#define MAIN_FULL_H

#include "BaseCommand.h"

class Full : public BaseCommand {
private:
    bool empty;
    bool header;
    bool headeronly;

    static constexpr char WRONGBOOLSAMOUNT[] = "invalid boolean values amount";

    const char *checkAmount(const Parser &parser);

    void setEmpty(const boolArgs_t &bools);
    void setHeader(const boolArgs_t &bools);
    void setHeaderonly(const boolArgs_t &bools);
public:
    explicit Full(std::ostream& ostream_);

    const char *checkAndAssemble(Parser &parser) final;
    int run() final;
};


#endif //MAIN_FULL_H
