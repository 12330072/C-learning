//
//  Line.cpp
//  Point&Line
//
//  Created by 邱兆丰 on 16/3/17.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "Line.h"
#include <math.h>
#include <sstream>

Line::Line() {
    a = 0;
    b = 0;
    c = 0;
}

Line::Line(double _a, double _b, double _c) {
    a = _a;
    b = _b;
    c = _c;
}

void Line::reset(const double &_a, const double &_b, const double &_c) {
    a = _a;
    b = _b;
    c = _c;
}

string Line::display() {
    ostringstream LS;
    if (a)
        LS << a << 'x';
    if (a) {
        if (b > 0)
            LS << '+' << b << 'y';
        else if (b < 0)
            LS << b << 'y';
    } else {
            LS << b << 'y';
    }
    if (a || b) {
        if (c > 0)
            LS << '+' << c;
        else if (c < 0) {
            LS << c;
        }
    }
    LS << "=0";
    return LS.str();
}

double dist_LP(const Line &L, const Point &P) {
    double fenmu = sqrt(pow(L.a, 2.0) + pow(L.b, 2.0));
    double fenzi = fabs(L.a * P.x + L.b * P.y + L.c);
    return fenzi / fenmu;
}

double dist_LL(const Line &L1, const Line &L2) {
    if (L1.a == 0) {
        if (L2.a == 0) {
            if (L1.b != 0 && L2.b != 0) {
                return fabs(L1.c / L1.b - L2.c / L2.b);
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    } else {
        if (L2.a == 0) {
            return -1;
        } else {
            if (L1.b == 0) {
                if (L2.b != 0) {
                    return -1;
                } else {
                    return fabs(L1.c / L1.a - L2.c / L2.a);
                }
            } else {
                if (L2.b == 0) {
                    return -1;
                } else {
                    double k = L1.a / L2.a;
                    if (L1.a / L2.a != L1.b / L2.b)
                        return -1;
                    double fenmu = sqrt(pow(L1.a, 2.0) + pow(L1.b, 2.0));
                    double fenzi = fabs(L1.c - L2.c * k);
                    return fenzi / fenmu;
                }
            }
        }
    }
}









