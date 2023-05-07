#include <iostream>
#include <fstream>

#include "Monitor.h"

//#define MONITOR_WITHFILE

#include "mycommands/Init.h"
#include "mycommands/Help.h"
#include "mycommands/MyCommandFactory.hpp"

int main() {
    auto commandFactory = FSCommandFactory<std::tuple<
        Init,
        Help
        >>("Test string");

#ifdef MONITOR_WITHFILE
    std::ifstream istream("input.txt");
    if(!istream.is_open()){
        throw std::runtime_error("can't find input file");
    }

    std::ofstream ostream("output.txt");
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
