#ifndef MAIN_SQUEEZE_H
#define MAIN_SQUEEZE_H

#include "BaseCommand.h"

class Squeeze : public BaseCommand {
public:
    Squeeze();

    static const std::string query;

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;
};

#endif //MAIN_SQUEEZE_H
