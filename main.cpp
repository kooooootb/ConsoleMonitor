#include <iostream>

#include "Monitor.h"

//#define NDEBUG // to disable asserts

int main() {
    Monitor monitor(std::cin, std::cout);
    monitor.run();

    return 0;
}
