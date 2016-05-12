//
//  Arithmetic.hpp
//  Template Arithmetic
//
//  Created by 邱兆丰 on 16/4/18.
//  Copyright © 2016年 菇生. All rights reserved.
//

#ifndef Arithmetic_h
#define Arithmetic_h

#include <iostream>

template<typename T>
class Arithmetic {
  public:
    Arithmetic(T _a = 0, T _b = 0);
    T addition();
    T subtraction();
    T multiplication();
    T division();
  private:
    T a;
    T b;
};

#endif /* Arithmetic_h */
