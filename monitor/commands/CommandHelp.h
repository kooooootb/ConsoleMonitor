#ifndef MAIN_COMMANDHELP_H // me
#define MAIN_COMMANDHELP_H

#include "CommandFactory.h"

class CommandHelp {
private:
    static const std::map<CommandsList, const char *> messages;
public:
    static const char *getMessage(CommandsList command){
        return messages.at(command);
    }
};

#endif //MAIN_COMMANDHELP_H
