#ifndef MAIN_COMMANDFACTORY_H
#define MAIN_COMMANDFACTORY_H

#include "BaseCommand.h"

template<typename CommandClasses>
class CommandFactory {
protected:
    template<std::size_t index = 0, typename Tuple, class ...Args>
    static typename std::enable_if<index == std::tuple_size_v<Tuple>, std::shared_ptr<BaseCommand>>::type
    construct(const std::string &query, [[maybe_unused]] Args... args){
        (void) query; // unused

        return nullptr;
    }

    template<std::size_t index = 0, typename Tuple, class ...Args>
    static typename std::enable_if<index < std::tuple_size_v<Tuple>, std::shared_ptr<BaseCommand>>::type
    construct(const std::string &query, Args... args){
        using CommandClass = std::tuple_element_t<index, Tuple>;
        if(query == CommandClass::getQuery()){
            return std::make_shared<CommandClass>(args...);
        }

        return construct<index + 1, Tuple>(query, args...);
    }

public:
    CommandFactory() = default;
    CommandFactory(const CommandFactory &) = default;
    CommandFactory(CommandFactory &&) noexcept = default;
    virtual ~CommandFactory() noexcept = default;

    /**
     * Фабричный метод создает объект команды из строки запроса
     * @param commandQuery строка запроса, целиком состоящая из символов команды
     * @param ostream поток вывода для создания объекта команды
     * @return указатель на объект команды
     */
    virtual std::shared_ptr<BaseCommand> getCommand(const std::string &commandString){
        (void) commandString; // unused
        return nullptr;
    }
};

#endif //MAIN_COMMANDFACTORY_H
