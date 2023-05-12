#include <iostream>
#include <fstream>

#include <Monitor.h>

#include "MyCommandFactory.hpp"

#define MONITOR_WITHFILE // Флаг отвечает за ввод команд из текстового файла

int main() {
    MyCommandFactory<std::tuple<Init, Help>> commandFactory("Example");

#ifdef MONITOR_WITHFILE
    std::ifstream istream("exampleInput.txt");
    if(!istream.is_open()){
        throw std::runtime_error("can't find input file");
    }

    std::ofstream ostream("exampleOutput.txt");
    if(!ostream.is_open()){
        throw std::runtime_error("can't find output file");
    }

    Monitor monitor(commandFactory, istream, ostream, true);
#else //MONITOR_WITHFILE
    Monitor monitor(commandFactory, std::cin, std::cout, false);
#endif //MONITOR_WITHFILE

    monitor.run();

    return 0;
}
