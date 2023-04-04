#ifndef MAIN_FULL_H
#define MAIN_FULL_H

#include "BaseCommand.h"

class Full : public BaseCommand {
private:
    bool empty;
    bool header;
    bool headeronly;

    bool checkAmount(const Parser &parser);

    void setEmpty(const boolArgs_t &bools);
    void setHeader(const boolArgs_t &bools);
    void setHeaderonly(const boolArgs_t &bools);
public:
    explicit Full(std::ostream& ostream_);

    bool checkAndAssemble(Parser &parser) final;
    int run() final;
};


#endif //MAIN_FULL_H
