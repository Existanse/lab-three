//
// Created by Michael on 07/11/2020.
//

#ifndef LABTHREECPP_CUSTOMEXPRESSIONEVALUATOR_H
#define LABTHREECPP_CUSTOMEXPRESSIONEVALUATOR_H
#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class CustomExpressionEvaluator: public ExpressionEvaluator, public IShuffle{
    public:
        CustomExpressionEvaluator();
        CustomExpressionEvaluator(int n);
        double calculate();
        void logToScreen();
        void logToFile(const std::string &filename);
        std::string getName();
        void shuffle() const override;
        void shuffle(size_t i, size_t j) const override;
    private:
        std::string name = "Custom Expression Evaluator";
};


#endif //LABTHREECPP_CUSTOMEXPRESSIONEVALUATOR_H
