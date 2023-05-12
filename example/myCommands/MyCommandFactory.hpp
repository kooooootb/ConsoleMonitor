#ifndef MONITOR_MYCOMMANDFACTORY_HPP
#define MONITOR_MYCOMMANDFACTORY_HPP

#include <utility>

#include <CommandFactory.hpp>

#include "Init.h"
#include "Help.h"

template<typename CommandClasses>
class MyCommandFactory : public CommandFactory<CommandClasses> {
private:
    std::string string;
public:
    explicit MyCommandFactory(std::string string_);

    std::shared_ptr<BaseCommand> getCommand(const std::string &commandString) override {
        return CommandFactory<CommandClasses>().template construct(commandString, string);
    }
};

template<typename CommandClasses>
MyCommandFactory<CommandClasses>::MyCommandFactory(std::string string_) : string(std::move(string_)) {}

#endif //MONITOR_MYCOMMANDFACTORY_HPP
