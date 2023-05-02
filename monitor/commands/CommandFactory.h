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
#include "Help.h"

class CommandFactory {
private:
    template<std::size_t index = 0, typename T, class ...Args>
    static typename std::enable_if<index == std::tuple_size_v<T>, std::shared_ptr<BaseCommand>>::type
    construct(const std::string &query, Args... args){
        return nullptr;
    }

    template<std::size_t index = 0, typename T, class ...Args>
    static typename std::enable_if<index < std::tuple_size_v<T>, std::shared_ptr<BaseCommand>>::type
    construct(const std::string &query, Args... args){
        using CommandClass = std::tuple_element_t<index, T>;
        if(query == CommandClass::getQuery()){
            return std::make_shared<CommandClass>(args...);
        }

        return construct<index + 1, T>(query, args...);
    }

public:
    CommandFactory() = delete;
    CommandFactory(const CommandFactory &) = delete;
    CommandFactory(CommandFactory &&) = delete;

    using CommandClasses = std::tuple<Init, Full, Empty, Enter, Copy, Move, Del, Squeeze, Help>;

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
    return construct<0, CommandClasses>(commandString, args...);
}


#endif //MAIN_COMMANDFACTORY_H
