//
// Created by Michael on 07/11/2020.
//

#ifndef LABTHREECPP_EXPRESSIONEVALUATOR_H
#define LABTHREECPP_EXPRESSIONEVALUATOR_H
#include "ILoggable.h"


class ExpressionEvaluator : public ILoggable{
    public:
        ExpressionEvaluator();
        ExpressionEvaluator(int n);
        void setOperand(size_t pos, double value);
        void setOperands(double ops[], size_t n);
        virtual std::string getName() = 0;
        virtual double calculate() = 0;
        virtual ~ExpressionEvaluator();
        int getN();
    protected:
        size_t n;
        double* ops;
};


#endif //LABTHREECPP_EXPRESSIONEVALUATOR_H
