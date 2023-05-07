#ifndef MONITOR_MONITOR_H
#define MONITOR_MONITOR_H

#include <iostream>
#include <memory>

#include "CommandFactory.h"
#include "MonitorInput.h"
#include "MonitorOutput.h"
#include "ParserException.h"
#include "MonitorHelp.h"

/**
 * Класс реализует монитор, принимает строки запросов из входного потока, передает выходную информацию в выходной поток
 * Для автоматизированного запуска можно использовать метод run,
 * для ручного управления - методом processInput для принятие строки и ее обработки,
 * showPrompt чтобы показать готовность к принятию ввода
 */
template<typename CommandClasses>
class Monitor {
private:
    std::unique_ptr<MonitorOutput> outputer;
    std::unique_ptr<MonitorInput> inputer;
    CommandFactory<CommandClasses> &commandFactory;
    static constexpr const char MONITOR_EXIT_MESSAGE[] = "Exit message";

    /**
     * Выводимое предложение ввода
     */
    static constexpr char PROMPT[] = "-> ";
    /**
     * Функция выводит предложение ввода
     */
    void showPrompt() const{
        *outputer << PROMPT;
    }

    /**
     * Выводит в сохраненный поток вывода информацию о работе монитора (результат loadHelp)
     * @return Сохраненный поток вывода
     */
    void printHelp() const{
        *outputer << MonitorHelp::getMessage() << "\n";
    }

    std::shared_ptr<Parser> getParser(const std::string &query) const{
        try{
            return std::make_shared<Parser>(Parser(query));
        } catch(ParserException &ex){
            *outputer << ex.what() << "\n";
            printHelp();
            return nullptr;
        }
    }

public:
    Monitor(CommandFactory<CommandClasses> &commandFactory_, std::istream &istream_, std::ostream &ostream_, bool echoing_)
    : outputer(), inputer(), commandFactory(commandFactory_)
    {
        // init in out objs
        if(echoing_){
            outputer = std::make_unique<MonitorOutput>(ostream_, std::cout);
            inputer = std::make_unique<MonitorInput>(istream_, std::vector{ &std::cout, &ostream_});
        } else{
            outputer = std::make_unique<MonitorOutput>(ostream_);
            inputer = std::make_unique<MonitorInput>(istream_);
        }
    }

    /**
     * Метод принимает запрос из входного потока и обрабатывает его
     * Для окончания ввода подходит команда EXIT или символ EOF
     * @return false если пользователь ввел команду окончания ввода, true otherwise
     * @tparam Tuple Кортеж из классов команд, обрабатываемых монитором
     */
    bool processInput(){
        std::string query = inputer->getline();

        if(query.empty() && inputer->eof()){
            return false;
        } else{
            std::shared_ptr<Parser> parser = getParser(query);
            if(parser == nullptr) return true;

            std::string &commandString = parser->getCommand();

            if(commandString == "exit"){ // check if exiting
                return false;
            } else { // do command thing
                // make command object
                std::shared_ptr<BaseCommand> command = commandFactory.getCommand(commandString);

                if (command == nullptr) { // if command doesn't exist
                    *outputer << "Command " + commandString + " doesn't exist" << "\n";
                    printHelp();
                } else { // run command
                    std::string message = command->processQuery(*parser);
                    *outputer << message << "\n";
                }
            }

            return true;
        }
    }
    /**
     * Метод сам управляет принятием ввода из консоли, выводит предложение на ввод
     * @tparam Tuple Кортеж из классов команд, обрабатываемых монитором
     */
    void run(){
        do{
            showPrompt();
        }while(processInput());

        *outputer << MONITOR_EXIT_MESSAGE;
    }
};

#endif //MONITOR_MONITOR_H
