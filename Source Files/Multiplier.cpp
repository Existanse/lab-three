//
// Created by Michael on 07/11/2020.
//

#include <iostream>
#include <fstream>
#include "../Header Files/Multiplier.h"

Multiplier::Multiplier(): ExpressionEvaluator(){

}

Multiplier::Multiplier(int n) : ExpressionEvaluator(n) {

}
double Multiplier::calculate() {
    double output;
    for(int i = 0;i<n;++i){
        i == 0 ? (output = ops[i]) : (output *= ops[i]);
    }
    return output;
}
void Multiplier::logToScreen() {
    for(int i = 0; i<n;++i){
        (ops[i] >= 0 ?
         std::cout << ops[i]:
         std::cout << '(' << ops[i] << ')') //add parenthesis when operand is negative
                << (i != n - 1 ? (" times "): " equals ");
    }
    std::cout<<calculate()<<std::endl;
}

void Multiplier::logToFile(const std::string &filename) {
    std::ofstream myfile;
    myfile.open (filename);
    for(int i = 0; i<n;++i){
        (ops[i] >= 0 ?
         std::cout << ops[i]:
         std::cout << '(' << ops[i] << ')') //add parenthesis when operand is negative
                << (i != n - 1 ? (" times "): " equals ");
    }
    myfile<<calculate()<<std::endl;

}

std::string Multiplier::getName() {
    return name;
}
