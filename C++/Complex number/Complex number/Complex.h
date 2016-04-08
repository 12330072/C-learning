//
//  Complex.h
//  Complex number
//
//  Created by 邱兆丰 on 16/2/28.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
public:
    Complex(double real, double imaginary);
    Complex();
    Complex add(const Complex &right);
    Complex subtract(const Complex &right);
    void printComplex();
    void setComplexNumber(double rp, double ip);
    
private:
    int realPart;
    int imaginaryPart;
    
};
#endif