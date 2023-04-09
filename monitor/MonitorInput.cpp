#include "MonitorInput.h"

MonitorInput::MonitorInput(std::istream &istream_) : istream(istream_) , echo(nullptr) {}

MonitorInput::MonitorInput(std::istream &istream_, std::ostream &echo_) : istream(istream_) , echo(&echo_) {}

std::string MonitorInput::getline(){
    std::string result;
    std::getline(istream, result);
    if(echo != nullptr){
        *echo << result << std::endl;
    }
    return result;
}

bool MonitorInput::eof() const{
    return istream.eof();
}

bool MonitorInput::good() const{
    return istream.good();
}
