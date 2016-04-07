//
//  Vector.hpp
//  Vector-2D
//
//  Created by 邱兆丰 on 16/3/1.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef VECTOR_H
#define VECTOR_H
using namespace std;

class Vector {
public:
    // constructer
    Vector();
    Vector(int, int);
    // copy constructer
    Vector(const Vector &otherVec);
    // destructer
    ~Vector() {}
    // vecter1 + vecter2
    Vector add(Vector);
    // vecter1 - vecter2
    Vector sub(Vector);
    // -vecter1
    Vector inverse();
    // vecter1 * vecter2
    int dot_product(Vector);
    // vecter1 x vecter2
    int cross_product(Vector);
    void print();
private:
    int x, y;
};

#endif
