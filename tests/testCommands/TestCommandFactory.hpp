#ifndef MONITOR_TESTCOMMANDFACTORY_HPP
#define MONITOR_TESTCOMMANDFACTORY_HPP

#include <utility>

#include <CommandFactory.hpp>

#include "Init.h"
#include "Help.h"

class TestCommandFactory : public CommandFactory<std::tuple<Init, Help>> {};

#endif //MONITOR_TESTCOMMANDFACTORY_HPP
