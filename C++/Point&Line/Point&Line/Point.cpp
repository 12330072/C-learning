//
//  Point.cpp
//  Point&Line
//
//  Created by 邱兆丰 on 16/3/17.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "Point.h"
#include <math.h>
#include <sstream>

Point::Point() {
    x = 0.0;
    y = 0.0;
}

Point::Point(double _x, double _y) {
    x = _x;
    y = _y;
}

void Point::reset(const double & _x, const double & _y) {
    x = _x;
    y = _y;
}

string Point::display() {
    ostringstream Po;
    Po << '(' << x << ", " << y << ')';
    return Po.str();
}

double dist_PP(const Point &a, const Point &b) {
    double X = pow(a.x - b.x, 2.0);
    double Y = pow(a.y - b.y, 2.0);
    return sqrt(X + Y);
}

