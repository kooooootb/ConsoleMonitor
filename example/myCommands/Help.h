#ifndef MAIN_HELP_H
#define MAIN_HELP_H

#include <utility>

#include "BaseCommand.h"

class Help : public BaseCommand {
private:
    std::string inner;

    static constexpr char helpMessage[] = "monitor help";
protected:
    std::string help() override;
public:
    explicit Help(std::string string);

    static std::string getQuery();

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;
};

#endif //MAIN_HELP_H
