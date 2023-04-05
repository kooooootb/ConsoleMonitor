#ifndef MAIN_SQUEEZE_H
#define MAIN_SQUEEZE_H

#include "BaseCommand.h"

class Squeeze : public BaseCommand {
public:
    explicit Squeeze(std::ostream& ostream_);

    const char *checkAndAssemble(Parser &parser) final;
    int run() final;
};

#endif //MAIN_SQUEEZE_H
