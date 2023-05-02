#include <iostream>
#include <fstream>

#include "Monitor.h"

#define MONITOR_WITHFILE

int main() {
#ifdef MONITOR_WITHFILE
    std::ifstream istream("input.txt");
    if(!istream.is_open()){
        throw std::runtime_error("can't find input file");
    }

    std::ofstream ostream("output.txt");
    if(!ostream.is_open()){
        throw std::runtime_error("can't find output file");
    }
    
    Monitor monitor(istream, ostream, true);
#else //MONITOR_WITHFILE
    Monitor monitor(std::cin, std::cout, false);
#endif //MONITOR_WITHFILE

    monitor.run<std::tuple<Init, Full, Empty, Enter, Copy, Move, Del, Squeeze, Help>>();

    return 0;
}
