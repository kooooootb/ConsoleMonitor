#ifndef MAIN_MONITORHELP_H
#define MAIN_MONITORHELP_H

#include <map>

class MonitorHelp {
private:
    static constexpr char messages[] = "monitor help";
public:
    static const char *getMessage(){
        return messages;
    }
};

#endif //MAIN_MONITORHELP_H
