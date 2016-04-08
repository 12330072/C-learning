#include "Matrix.h"
#include <sstream>

Matrix::Matrix() {
    width = height = 0;
    cout << "construct an uninitialised matrix." << endl;
}

Matrix::Matrix(string _name, int w, int h, int** pa) : name(_name), width(w), height(h), param(pa) {
    cout << "construct a matrix called " << name << '.' << endl;
}

Matrix::Matrix(const Matrix & othM) {
    name = othM.name;
    width = othM.width;
    height = othM.height;
    param = othM.param;
    cout << "copy construct a matrix called " << name << '.' << endl;
}

Matrix::~Matrix() {
    cout << "release memory from a matrix called " << name << '.' << endl;
}


void Matrix::setName(string _name) {
    name = _name;
}


void Matrix::print() {
    ostringstream out;
    out << name << " = [" << endl;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height - 1; j++) {
            out << param[i][j];
            out << ", ";
        }
        out << param[i][height - 1] << endl;
    }
    out << ']' << endl;
    cout << out.str();
}







