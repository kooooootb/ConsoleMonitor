#ifndef MAIN_EMPTY_H
#define MAIN_EMPTY_H

#include "BaseCommand.h"

class Empty : public BaseCommand {
public:
    explicit Empty(std::ostream& ostream_);

    static const std::string query;

    const char *checkAndAssemble(Parser &parser) final;
    int run() final;
};

#endif //MAIN_EMPTY_H
