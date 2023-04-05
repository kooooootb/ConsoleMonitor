#ifndef MAIN_COMMANDFACTORY_H
#define MAIN_COMMANDFACTORY_H

#include <memory>

#include "BaseCommand.h"
#include "Init.h"
#include "Full.h"
#include "Blackhole.h"
#include "Enter.h"

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
    } else if(commandString == "blackhole"){
        return std::make_shared<Blackhole>(args...);
    } else if(commandString == "enter"){
        return std::make_shared<Enter>(args...);
    } else {
        return nullptr; // can't find appropriate command
    }
}


#endif //MAIN_COMMANDFACTORY_H
