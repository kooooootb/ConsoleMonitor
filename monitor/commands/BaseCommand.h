#ifndef MONITOR_BASECOMMAND_H
#define MONITOR_BASECOMMAND_H

#include <vector>
#include <string>
#include <map>
#include <ostream>
#include <memory>
#include <algorithm>

#include "Parser.h"

/**
 * Класс образует базу для дальнейших классов-команд, хранит общие методы обработки введенной строки
 */
class BaseCommand {
public:
    enum class Commands{
        INIT = 0, FULL, BLACKHOLE, ENTER, COPYPASTE, MOVEFILE, DELETE, SQUEZZE, COMMANDSAMOUNT
    };
private:
    /**
     * Тип команды, используется для вывода помощи
     */
    const Commands commandType;

    /**
     * Выводит в сохраненный поток вывода информацию о команде (результат loadHelp)
     * @return Сохраненный поток вывода
     */
    std::ostream &help();
protected:
    /**
     * Поток для вывода сообщений
     */
    std::ostream& ostream;

    /**
     * Метод проверяет аргументы из объекта парсера и собирает их в соответствующие команде переменные
     * @param parser объект парсера, содержащий массивы полученных аргументов
     * @return false если входные данные неверные, true otherwise
     */
    virtual bool checkAndAssemble(Parser &parser) = 0;

    /**
     * Метод запускает соответствующую команде функцию ФС
     * @return Код ошибки или void в зависимости от команды
     */
    virtual int run() = 0;
    /**
     * Выводит сообщение об ошибке при сборке объекта команды
     * @param info дополнительное сообщение
     */
    void printAssemblyError(const char *info);
public:
    explicit BaseCommand(Commands commandType_, std::ostream &ostream_);

    virtual ~BaseCommand() = default;

    /**
     * Возвращает тип команды
     * @return элемент перечисляемого типа
     */
    Commands getCommand() const;
    /**
     * Метод обрабатывает, устанавливает аргументы команды из строки запроса и исполняет команду
     * @param query строка запроса
     * @param keyAmount количество ключевых аргументов в команде
     */
    void processQuery(const std::string &query);

    /**
     * Фабричный метод создает объект команды из строки запроса
     * @param commandQuery строка запроса, целиком состоящая из символов команды
     * @param ostream поток вывода для создания объекта команды
     * @return указатель на объект команды
     */
    static std::shared_ptr<BaseCommand> parseCommand(std::string &commandQuery, std::ostream &ostream);
};

#endif //MONITOR_BASECOMMAND_H
