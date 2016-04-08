//
//  Matrix.hpp
//  Matrix
//
//  Created by 邱兆丰 on 16/3/21.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string.h>
using namespace std;

class Matrix {
public:
    Matrix();
    Matrix(string _name, int w, int, int** pa);
    Matrix(const Matrix &);
    ~Matrix();
    void setName(string);
    void print();
private:
    string name;
    int width, height, **param;
};

#endif