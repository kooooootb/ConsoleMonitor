#include <gtest/gtest.h>

#include "CommandFactory.hpp"
#include "Init.h"
#include "Full.h"

namespace{
    TEST(parseCommand, inittype){
        std::ostream &ostream = std::cout;
        std::string query = "init";
        EXPECT_EQ(CommandFactory::getCommand(query)->getCommandType(), CommandsList::INIT);
    }
}
