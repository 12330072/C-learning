//
//  SimpleCalculator.cpp
//  SimpleCalculator
//
//  Created by 邱兆丰 on 16/2/29.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "SimpleCalculator.h"
#include <iostream>


SimpleCalculator::SimpleCalculator() {
    answer = 0;
}

void SimpleCalculator::add(double a, double b) {
    answer = a + b;
}

void SimpleCalculator::subtract(double a, double b) {
    answer = a - b;
}

void SimpleCalculator::multiply(double a, double b) {
    answer = a * b;
}

void SimpleCalculator::divide(double a, double b) {
    answer = a / b;
}

double SimpleCalculator::getAnswer() const{
    return answer;
}