//
// Created by Michael on 07/11/2020.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include "../Header Files/CustomExpressionEvaluator.h"
/*Вариант 8
Вид выражения CustomExpression: result = x1 * x2 / x3 * x4 / x5 * ...
Порядок создания и инициализации объектов подклассов:
CustomExpressionEvaluator: 5 операндов, присвоить группой 5, 10, -2.5, -40, -2.
Subtractor: 9 операндов, присвоить группой 120,-12, 83.2, -1.5, 5, 7, 2, 18.5, 76.
Multiplier: 2 операнда, присвоить поэлементно -1.5, 80.
Метод shuffle() – поменять местами первый и последний операнды, имеющие
дробную часть. Метод shuffle(size_t i, size_t j) – если хотя бы один из i-ого и jого операндов имеет дробную часть, поменять их местами, иначе – не менять.
Формат вывода:
<4>
5 times 10 divided by (-2.5) times (-40) divided by (-2)
<Result: -400>*/
CustomExpressionEvaluator::CustomExpressionEvaluator(): ExpressionEvaluator(){

}

CustomExpressionEvaluator::CustomExpressionEvaluator(int n) : ExpressionEvaluator(n) {

}
double CustomExpressionEvaluator::calculate() {
    double output;
    for(int i = 0;i<n;++i){
        if(i == 0){
            output = ops[i];
        } else{
            i % 2 != 0 ? (output *= ops[i]) : (output /= ops[i]);
        }
    }
    return output;
}
void CustomExpressionEvaluator::logToScreen() {
    for(int i = 0; i<n;++i){
        (ops[i] >= 0 ?
        std::cout << ops[i]:
        std::cout << '(' << ops[i] << ')') //add parenthesis when operand is negative
        << (i != n - 1 ?
        (i % 2 == 0?" time ":" divided by "):
        " equals"); // change the symbol to the equals sign if its the last one
    }
    std::cout<<calculate()<<std::endl;
}

void CustomExpressionEvaluator::logToFile(const std::string &filename) {
    std::ofstream myfile;
    myfile.open (filename);
    for(int i = 0; i<n;++i){
        (ops[i] >= 0 ?
         myfile << ops[i]:
         myfile << '(' << ops[i] << ')') //add parenthesis when operand is negative
                << (i != n - 1 ?
                    (i % 2 == 0?" times ":" divided by "):
                    " equals "); // change the symbol to the equals sign if its the last one
    }
    myfile<<calculate()<<std::endl;

}
void CustomExpressionEvaluator::shuffle() const{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, n-1);
    for(int i=0; i<n; ++i)
        shuffle(distr(gen), distr(gen));
}
void CustomExpressionEvaluator::shuffle(size_t i, size_t j) const{
    std::swap(ops[i], ops[j]);
};
std::string CustomExpressionEvaluator::getName() {
    return name;
}
