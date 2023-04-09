#ifndef MAIN_HELP_H
#define MAIN_HELP_H

#include "BaseCommand.h"

class Help : public BaseCommand {
private:
    static constexpr char helpMessage[] = "monitor help";
public:
    Help();

    static const std::string query;

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;
};

#endif //MAIN_HELP_H
