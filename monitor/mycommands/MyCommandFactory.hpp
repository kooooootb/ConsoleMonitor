//
// Created by evezers on 07/05/23.
//

#ifndef MONITOR_MYCOMMANDFACTORY_HPP
#define MONITOR_MYCOMMANDFACTORY_HPP

#include "CommandFactory.h"

#include <utility>

template<typename CommandClasses>
class FSCommandFactory : public CommandFactory<CommandClasses> {
private:
    std::string s;

public:
    explicit FSCommandFactory(std::string string) : CommandFactory<CommandClasses>(), s(std::move(string)){ }

    std::shared_ptr<BaseCommand> getCommand(const std::string &commandString) override {
        return CommandFactory<CommandClasses>().template construct<0, CommandClasses>(commandString, s);
    }
};


#endif //MONITOR_MYCOMMANDFACTORY_HPP
