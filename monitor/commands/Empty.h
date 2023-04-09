#ifndef MAIN_EMPTY_H
#define MAIN_EMPTY_H

#include "BaseCommand.h"

class Empty : public BaseCommand {
public:
    Empty();

    static const std::string query;

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;
};

#endif //MAIN_EMPTY_H
