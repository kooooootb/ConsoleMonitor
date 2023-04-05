#ifndef MAIN_COMMANDFACTORY_H
#define MAIN_COMMANDFACTORY_H

#include <memory>

#include "BaseCommand.h"
#include "Init.h"
#include "Full.h"
#include "Empty.h"
#include "Enter.h"
#include "Copy.h"
#include "Move.h"
#include "Del.h"
#include "Squeeze.h"

class CommandFactory {
public:
    CommandFactory() = delete;
    CommandFactory(const CommandFactory &) = delete;
    CommandFactory(CommandFactory &&) = delete;

    /**
     * Фабричный метод создает объект команды из строки запроса
     * @param commandQuery строка запроса, целиком состоящая из символов команды
     * @param ostream поток вывода для создания объекта команды
     * @return указатель на объект команды
     */
    template<class ...Args>
    static std::shared_ptr<BaseCommand> getCommand(const std::string &commandString, Args... args);
};

template<class ...Args>
std::shared_ptr<BaseCommand> CommandFactory::getCommand(const std::string &commandString, Args ...args) {
    if (commandString == "init") {
        return std::make_shared<Init>(args...);
    } else if(commandString == "full"){
        return std::make_shared<Full>(args...);
    } else if(commandString == "empty"){
        return std::make_shared<Empty>(args...);
    } else if(commandString == "enter"){
        return std::make_shared<Enter>(args...);
    } else if(commandString == "copy"){
        return std::make_shared<Copy>(args...);
    } else if(commandString == "move"){
        return std::make_shared<Move>(args...);
    } else if(commandString == "del"){
        return std::make_shared<Del>(args...);
    } else if(commandString == "squeeze"){
        return std::make_shared<Squeeze>(args...);
    } else {
        return nullptr; // can't find appropriate command
    }
}


#endif //MAIN_COMMANDFACTORY_H
