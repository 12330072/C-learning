//
//  Vector.cpp
//  Vector-2D
//
//  Created by 邱兆丰 on 16/3/1.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//
#include <iostream>
#include "Vector.h"

Vector::Vector() {
    x = y = 0;
}

Vector::Vector(int a, int b) {
    x = a;
    y = b;
}

Vector::Vector(const Vector &otherVec) {
    x = otherVec.x;
    y = otherVec.y;
}

Vector Vector::add(Vector c) {
    Vector temp(x, y);
    temp.x += c.x;
    temp.y += c.y;
    return temp;
}
Vector Vector::sub(Vector c) {
    Vector temp(x, y);
    temp.x -= c.x;
    temp.y -= c.y;
    return temp;
}
Vector Vector::inverse() {
    Vector temp;
    temp.x = -x;
    temp.y = -y;
    return temp;
}
int Vector::dot_product(Vector c) {
    int s = x * c.x + y * c.y;
    return s;
}
int Vector::cross_product(Vector c) {
    int s = x * c.y - y * c.x;
    s = abs(s);
    return s;
}

void Vector::print() {
    cout << '(' << x << ',' << ' ' << y << ')' << endl;
}