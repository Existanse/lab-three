//
// Created by Michael on 07/11/2020.
//

#ifndef LABTHREECPP_ILOGGABLE_H
#define LABTHREECPP_ILOGGABLE_H


#include <string>

class ILoggable {
    public:
        virtual void logToScreen() = 0;
        virtual void logToFile(const std::string& filename) = 0;
        virtual ~ILoggable(){}
};


#endif //LABTHREECPP_ILOGGABLE_H
