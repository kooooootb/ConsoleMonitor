#ifndef MONITOR_MYCOMMANDFACTORY_HPP
#define MONITOR_MYCOMMANDFACTORY_HPP

#include <utility>

#include <CommandFactory.hpp>

#include "Init.h"
#include "Help.h"

class MyCommandFactory : public CommandFactory<std::tuple<Init, Help>> {};

#endif //MONITOR_MYCOMMANDFACTORY_HPP
