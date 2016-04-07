//
//  Complex.hpp
//  Complex Again
//
//  Created by 邱兆丰 on 16/3/9.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef Complex_hpp
#define Complex_hpp
#include <iostream>
using namespace std;

class Complex {
  public:
    Complex();
    Complex(double, double);
    void SetReal(double re) {
        real = re;
    };
    void SetImag(double im) {
        imag = im;
    };
    void operator+=(const Complex & othC);
    void operator=(const Complex & othC);
    void operator-=(const Complex & othC);
    void operator*=(const Complex & othC);
    void operator/=(const Complex & othC);
    Complex operator+(const Complex & othC) const;
    Complex operator-(const Complex & othC) const;
    Complex operator*(const Complex & othC) const;
    Complex operator/(const Complex & othC) const;
    bool operator==(const Complex & othC) const;
    bool operator!=(const Complex & othC) const;
    friend ostream & operator<<(ostream & os, const Complex & othC);
  private:
    double real;
    double imag;
};

#endif /* Complex_hpp */
