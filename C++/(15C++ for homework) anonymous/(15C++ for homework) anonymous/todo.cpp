#include "todo.h"

point::point(double _x, double _y) {
    x = _x;
    y = _y;
}

void point::print() {
    cout << setprecision(2) << fixed << "point : " << x << ' ' << y << endl;
}

vector::vector(double _x, double _y, double _dx, double _dy):point(_x, _y) {
    dx = _dx;
    dy = _dy;
    length = sqrt(pow(dx, 2.0) + pow(dy, 2.0));
}

void vector::print() {
    cout << setprecision(2) << fixed << "length : " << length << endl;
    point::print();
}

double vector::getLength() {
    return length;
}

circle::circle(double _x, double _y, double _r):point(_x, _y) {
    r = _r;
    area = acos(-1.0) * pow(r, 2.0);
}

void circle::print() {
    cout << setprecision(2) << fixed <<  "area : " << area << endl;
    point::print();
}

double circle::getArea() {
    return area;
}

double circle::getR() {
    return r;
}

todo::todo(double _x, double _y, double _dx, double _dy, double _r): vector(_x, _y, _dx, _dy), circle(_x, _y, _r) {
    volume = getLength() * 2 * getR() + getArea();
};

void todo::print() {
    cout << setprecision(2) << fixed << "volume : " << volume << endl;
    vector::print();
    circle::print();
}












