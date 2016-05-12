//
//  Calculator.hpp
//  Simple Calculator with Exeption Handling
//
//  Created by 邱兆丰 on 16/4/29.
//  Copyright © 2016年 菇生. All rights reserved.
//

#ifndef Calculator_h
#define Calculator_h
#include <iostream>
#include <string>
using std::string;

class calculator {
public:
    int calculate(string & str) {
        if (str == "") {
            throw EmptyExpressionException();
        }
        for (int i = 0; i < str.length(); i+= 2) {
            if ((str[i] < 48 || str[i] > 57) && (str[i] != '+' && str[i] != '-')) {
                throw IllegalSymbolException(i);
            }
            else if (str[i] == '+' || str[i] == '-') {
                throw MissingOperandException(i);
            }
            if (i < str.length() - 1) {
                if ((str[i + 1] < 48 || str[i + 1] > 57) && (str[i + 1] != '+' && str[i + 1] != '-')) {
                    throw IllegalSymbolException(i + 1);
                }
                else if (str[i + 1] >= 48 && str[i + 1] < 58) {
                    throw MissingOperatorException(i + 1);
                }
            }
        }
        if (str.length() % 2 != 1) {
            throw MissingOperandException(str.length());
        }
        int sum = str[0] - '0';
        int temp;
        for (int i = 1; i < str.length(); i += 2) {
            if (str[i] == '+') {
                temp = str[i + 1] - '0';
                sum += temp;
            }
            else if (str[i] == '-') {
                temp = str[i + 1] - '0';
                sum -= temp;
            }
        }
        return sum;
    }
};

#endif /* Calculator_h */
