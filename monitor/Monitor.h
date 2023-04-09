#ifndef MONITOR_MONITOR_H
#define MONITOR_MONITOR_H

#include <iostream>
#include <memory>

#include "CommandFactory.h"

/**
 * Класс реализует монитор, принимает строки запросов из входного потока, передает выходную информацию в выходной поток
 * Для автоматизированного запуска можно использовать метод run,
 * для ручного управления - методом processInput для принятие строки и ее обработки,
 * showPrompt чтобы показать готовность к принятию ввода
 */
class Monitor {
private:
    /**
     * Входной поток
     */
    std::istream &istream;
    /**
     * Выходной поток
     */
    std::ostream &ostream;
    /**
     * Необходимо ли дублировать входной поток в выходной
     */
    bool echoing;

    /**
     * Выводимое предложение ввода
     */
    static constexpr char PROMPT[] = "->";
    /**
     * Функция выводит предложение ввода
     */
    void showPrompt();

    /**
     * Выводит в сохраненный поток вывода информацию о работе монитора (результат loadHelp)
     * @return Сохраненный поток вывода
     */
    std::ostream &help();
    /**
     * Метод выводит сообщение об ошибке в выходной поток
     * @param message сообщение об ошибке
     * @return выходной поток
     */
    std::ostream &printError(const std::string &message);
    void getInput(std::string &query);
    std::shared_ptr<Parser> getParser(const std::string &query);
public:
    Monitor(std::istream &istream_, std::ostream &ostream_, bool echoing_);

    /**
     * Метод принимает запрос из входного потока и обрабатывает его
     * Для окончания ввода подходит команда EXIT или символ EOF
     * @return false если пользователь ввел команду окончания ввода, true otherwise
     */
    bool processInput();
    /**
     * Метод сам управляет принятием ввода из консоли, выводит предложение на ввод
     */
    void run();
};


#endif //MONITOR_MONITOR_H
