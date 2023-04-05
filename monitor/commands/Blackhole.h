#ifndef MAIN_BLACKHOLE_H
#define MAIN_BLACKHOLE_H

#include "BaseCommand.h"

class Blackhole : public BaseCommand {
public:
    explicit Blackhole(std::ostream& ostream_);

    const char *checkAndAssemble(Parser &parser) final;
    int run() final;
};


#endif //MAIN_BLACKHOLE_H
