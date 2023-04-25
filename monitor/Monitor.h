#ifndef MONITOR_MONITOR_H
#define MONITOR_MONITOR_H

#include <iostream>
#include <memory>

#include "CommandFactory.h"
#include "MonitorInput.h"
#include "MonitorOutput.h"

/**
 * Класс реализует монитор, принимает строки запросов из входного потока, передает выходную информацию в выходной поток
 * Для автоматизированного запуска можно использовать метод run,
 * для ручного управления - методом processInput для принятие строки и ее обработки,
 * showPrompt чтобы показать готовность к принятию ввода
 */
class Monitor {
private:
    std::unique_ptr<MonitorOutput> outputer;
    std::unique_ptr<MonitorInput> inputer;
    static constexpr const char MONITOR_EXIT_MESSAGE[] = "Exit message";

    /**
     * Выводимое предложение ввода
     */
    static constexpr char PROMPT[] = "->";
    /**
     * Функция выводит предложение ввода
     */
    void showPrompt() const;

    /**
     * Выводит в сохраненный поток вывода информацию о работе монитора (результат loadHelp)
     * @return Сохраненный поток вывода
     */
    void printHelp() const;
    std::shared_ptr<Parser> getParser(const std::string &query) const;
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
