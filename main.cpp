#include <iostream>
#include <fstream>

#include "Monitor.h"

int main() {
    std::ifstream istream("input.txt");
    if(!istream.is_open()){
        throw std::runtime_error("can't find input file");
    }

    std::ofstream ostream("output.txt");
    if(!ostream.is_open()){
        throw std::runtime_error("can't find output file");
    }

    Monitor monitor(istream, ostream, true);
    monitor.run();

    return 0;
}
