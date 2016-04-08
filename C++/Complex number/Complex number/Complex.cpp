//
//  Complex.cpp
//  Complex number
//
//  Created by 邱兆丰 on 16/2/28.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//
#include <iostream>
using namespace std;

#include "Complex.h"

Complex::Complex(double real, double imaginary) {
    setComplexNumber(real, imaginary);
}

Complex::Complex() {
    setComplexNumber(0, 0);
}

Complex Complex::add(const Complex &right) {
    Complex temp;
    temp.realPart = realPart + right.realPart;
    temp.imaginaryPart = imaginaryPart + right.imaginaryPart;
    return temp;
}

Complex Complex::subtract(const Complex &right) {
    Complex temp;
    temp.imaginaryPart = imaginaryPart - right.imaginaryPart;
    temp.realPart = realPart - right.realPart;
    return temp;
}

void Complex::printComplex() {
    cout << '(' << realPart << ", " << imaginaryPart << ')';
}

void Complex::setComplexNumber(double rp, double ip) {
    realPart = rp;
    imaginaryPart = ip;
}