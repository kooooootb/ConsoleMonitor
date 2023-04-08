#ifndef MAIN_HELP_H
#define MAIN_HELP_H

#include "BaseCommand.h"

class Help : public BaseCommand {
private:
    static constexpr char helpMessage[] = "monitor help";
public:
    explicit Help(std::ostream& ostream_);

    static const std::string query;

    const char *checkAndAssemble(Parser &parser) final;
    int run() final;
};

#endif //MAIN_HELP_H
