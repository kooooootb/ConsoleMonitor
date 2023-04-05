#include <map>

#include "CommandHelp.h"

const std::map<CommandsList, const char *> CommandHelp::messages = {
    {CommandsList::INIT, "init help\ninit help second line"},
    {CommandsList::FULL, "full help"},
    {CommandsList::BLACKHOLE, "blackhole help"},
    {CommandsList::ENTER, "enter help"}
};