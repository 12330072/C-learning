//
//  Arithmetic.cpp
//  Template Arithmetic
//
//  Created by 邱兆丰 on 16/4/18.
//  Copyright © 2016年 菇生. All rights reserved.
//

#include "Arithmetic.h"

template<typename T>
Arithmetic<T>::Arithmetic(T _a, T _b) : a(_a), b(_b) {}

template<typename T>
T Arithmetic<T>::addition() {
    return a + b;
}

template<typename T>
T Arithmetic<T>::subtraction() {
    return a - b;
}

template<typename T>
T Arithmetic<T>::multiplication() {
    return a * b;
}

template<typename T>
T Arithmetic<T>::division() {
    return a / b;
}