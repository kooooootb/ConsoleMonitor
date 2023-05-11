#ifndef MAIN_HELP_H
#define MAIN_HELP_H

#include <utility>

#include "BaseCommand.h"

class Help : public BaseCommand {
private:
    static constexpr char helpMessage[] = "monitor help";
protected:
    std::string help() override;
public:
    Help() = default;

    static std::string getQuery();

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;
};

#endif //MAIN_HELP_H
