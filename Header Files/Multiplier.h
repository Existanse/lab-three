//
// Created by Michael on 07/11/2020.
//

#ifndef LABTHREECPP_MULTIPLIER_H
#define LABTHREECPP_MULTIPLIER_H


#include "ExpressionEvaluator.h"

class Multiplier: public ExpressionEvaluator{
    public:
        Multiplier();
        Multiplier(int n);
        double calculate();
        void logToScreen();
        void logToFile(const std::string &filename);
        std::string getName();
    private:
        std::string name = "Multiplier";
};


#endif //LABTHREECPP_MULTIPLIER_H
