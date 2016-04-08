//
//  Complex.cpp
//  Complex Again
//
//  Created by 邱兆丰 on 16/3/9.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "Complex.h"

Complex::Complex() {
    real = 0.0;
    imag = 0.0;
}

Complex::Complex(double r, double i) {
    real = r;
    imag = i;
}

Complex Complex::operator+(const Complex & othC) const {
    Complex temp;
    temp.real = real + othC.real;
    temp.imag = imag + othC.imag;
    return temp;
}

Complex Complex::operator-(const Complex & othC) const {
    Complex temp;
    temp.real = real - othC.real;
    temp.imag = imag - othC.imag;
    return temp;
}

Complex Complex::operator*(const Complex & othC) const {
    Complex temp;
    temp.real = real * othC.real - imag * othC.imag;
    temp.imag = real * othC.imag + othC.real *imag;
    return temp;
}

Complex Complex::operator/(const Complex & othC) const {
    Complex temp;
    int mon = othC.real * othC.real + othC.imag * othC.imag;
    temp.real = (real * othC.real + imag * othC.imag) / mon;
    temp.imag = ((-real) * othC.imag + othC.real * imag) / mon;
    return temp;
}

ostream & operator<<(std::ostream & os, const Complex & othC) {
    os << othC.real << '+' << othC.imag << 'i';
    return os;
}

void Complex::operator+=(const Complex & othC) {
    real = real + othC.real;
    imag = imag + othC.imag;
}

void Complex::operator-=(const Complex & othC) {
    real = real - othC.real;
    imag = imag - othC.imag;
}

void Complex::operator*=(const Complex & othC) {
    Complex temp;
    temp.real = real * othC.real - imag * othC.imag;
    temp.imag = real * othC.imag + othC.real *imag;
    real = temp.real;
    imag = temp.imag;
}

void Complex::operator/=(const Complex & othC) {
    Complex temp;
    int mon = othC.real * othC.real + othC.imag * othC.imag;
    temp.real = (real * othC.real + imag * othC.imag) / mon;
    temp.imag = ((-real) * othC.imag + othC.real *imag) / mon;
    real = temp.real;
    imag = temp.imag;
}

bool Complex::operator==(const Complex & othC) const {
    if (real == othC.real && imag == othC.imag)
        return 1;
    else
        return 0;
}

bool Complex::operator!=(const Complex & othC) const {
    if (real != othC.real && imag != othC.imag)
        return 1;
    else
        return 0;
}

void Complex::operator=(const Complex & othC) {
    real = othC.real;
    imag = othC.imag;
}






