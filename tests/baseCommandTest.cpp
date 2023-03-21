#include <gtest/gtest.h>

#include "CommandHeaders.h"

namespace{
    TEST(parseCommand, init){
        std::ostream &ostream = std::cout;
        std::string query = "init";
        EXPECT_EQ(BaseCommand::parseCommand(query, ostream)->getCommand(), BaseCommand::Commands::INIT);
    }
}
