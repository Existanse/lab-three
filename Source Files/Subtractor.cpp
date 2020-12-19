//
// Created by Michael on 07/11/2020.
//
#include <iostream>
#include <fstream>
#include <random>
#include "../Header Files/Subtractor.h"

Subtractor::Subtractor(): ExpressionEvaluator(){

}

Subtractor::Subtractor(int n) : ExpressionEvaluator(n) {

}
double Subtractor::calculate() {
    double output;
    for(int i = 0;i<n;++i){
        i == 0 ? (output = ops[i]) : (output -= ops[i]);
    }
    return output;
}
void Subtractor::logToScreen() {
    for(int i = 0; i<n;++i){
        (ops[i] >= 0 ?
         std::cout << ops[i]:
         std::cout << '(' << ops[i] << ')') //add parenthesis when operand is negative
                << (i != n - 1 ? (" minus "): " equals ");
    }
    std::cout<<calculate()<<std::endl;
}

void Subtractor::logToFile(const std::string &filename) {
    std::ofstream myfile;
    myfile.open (filename);
    for(int i = 0; i<n;++i){
        (ops[i] >= 0 ?
         std::cout << ops[i]:
         std::cout << '(' << ops[i] << ')') //add parenthesis when operand is negative
                << (i != n - 1 ? (" minus "): " equals ");
    }
    myfile<<calculate()<<std::endl;
}
void Subtractor::shuffle() const{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, n-1);
    for(int i=0; i<n; ++i)
        shuffle(distr(gen), distr(gen));
}
void Subtractor::shuffle(size_t i, size_t j) const {
    std::swap(ops[i], ops[j]);
}
std::string Subtractor::getName() {
    return name;
}