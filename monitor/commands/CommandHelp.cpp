#include <map>

#include "CommandHelp.h"

const std::map<CommandsList, const char *> CommandHelp::messages = {
    {CommandsList::INIT, "init help\ninit help second line"},
    {CommandsList::FULL, "full help"},
    {CommandsList::EMPTY, "blackhole help"},
    {CommandsList::ENTER, "enter help"},
    {CommandsList::COPY, "copy help"},
    {CommandsList::MOVE, "move help"},
    {CommandsList::DEL, "del help"},
    {CommandsList::SQUEZZE, "squeeze help"}
};