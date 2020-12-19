//
// Created by Michael on 07/11/2020.
//

#include "../Header Files/ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator(){
    n = 20;
    ops = new double[n];
    for (int i = 0; i < n; ++i) {
        ops[i] = 0;
    }
}
ExpressionEvaluator::ExpressionEvaluator(int _n){
    n = _n;
    ops = new double[n];
    for (int i = 0; i < n; ++i) {
        ops[i] = 0;
    }
}
ExpressionEvaluator::~ExpressionEvaluator(){
    delete[] ops;
}
void ExpressionEvaluator::setOperand(size_t pos, double value){
    ops[pos] = value;
}
void ExpressionEvaluator::setOperands(double _ops[], size_t _n){
    for(int i = 0; i<_n; ++i){
        ops[i] = _ops[i];
    }
}
int ExpressionEvaluator::getN(){
    return n;
}
