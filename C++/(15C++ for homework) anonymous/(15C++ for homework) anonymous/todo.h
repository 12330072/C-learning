#ifndef todo_h
#define todo_h

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

class point {
 public:
    point(double _x = 0, double _y = 0);
    void print();
    double getX();
    double getY();
 protected:
    double x;
    double y;
};

class vector: public point {
 public:
    vector(double _x = 0, double _y = 0, double _dx = 0, double _dy = 0);
    void print();
    double Clength();
    double getLength();
 private:
    double dx;
    double dy;
    double length;
};

class circle: public point {
 public:
    circle(double _x = 0, double _y = 0, double _r = 0);
    void print();
    double getArea();
    double getR();
 private:
    double r;
    double area;
};

class todo: public vector, public circle {
 public:
    todo(double _x = 0, double _y = 0, double _dx = 0, double _dy = 0, double _r = 0);
    void print();
 private:
    double volume;
};

#endif /* todo_hpp */
