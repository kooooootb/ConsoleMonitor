#ifndef MONITOR_BASECOMMAND_H
#define MONITOR_BASECOMMAND_H

#include <vector>
#include <string>
#include <map>
#include <ostream>
#include <memory>
#include <algorithm>

#include "Parser.h"
#include "CommandList.h"

/**
 * Класс образует базу для дальнейших классов-команд, хранит общие методы обработки введенной строки
 */
class BaseCommand {
private:
    /**
     * Тип данной команды из перенумерования
     */
    CommandsList commandType;
protected:
    /**
     * Поток для вывода сообщений
     */
    std::ostream& ostream;

    /**
     * Метод проверяет аргументы из объекта парсера и собирает их в соответствующие команде переменные
     * @param parser объект парсера, содержащий массивы полученных аргументов
     * @return сообщение об ошибке (при ошибке)
     */
    virtual const char *checkAndAssemble(Parser &parser) = 0;

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
    /**
     * Выводит в сохраненный поток вывода информацию о команде
     * @return Сохраненный поток вывода
     */
    std::ostream &help();
public:
    explicit BaseCommand(CommandsList commandType_, std::ostream &ostream_);

    virtual ~BaseCommand() = default;

    /**
     * Метод обрабатывает, устанавливает аргументы команды из строки запроса и исполняет команду
     * @param parser объект парсера обработавший запрос
     * @return сообщение об ошибке (при ошибке)
     */
    const char *processQuery(Parser &parser);

    /**
     * Возвращает тип команды
     * @return тип команды
     */
    CommandsList getCommandType() const;
};

#endif //MONITOR_BASECOMMAND_H
