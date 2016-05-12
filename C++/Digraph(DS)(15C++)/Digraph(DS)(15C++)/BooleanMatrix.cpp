#include "BooleanMatrix.hpp"

//  可以把子类放到基类的构造函数中
BooleanMatrix::BooleanMatrix(const BooleanMatrix &othBM): Matrix(othBM) {}

BooleanMatrix::BooleanMatrix(int r, int c): Matrix(r, c) {}

bool BooleanMatrix::replace(matrix_element_type e, int r, int c)  {
    if (r <= getRow() && r > 0 && c <= getColums() && c > 0) {
        Matrix::replace(e, r, c);
        return true;
    }
    else
        return false;
}

BooleanMatrix BooleanMatrix::operator&(const BooleanMatrix &othBM) {
    assert(row == othBM.row);
    assert(columns == othBM.columns);
    BooleanMatrix out(row, columns);
    for (int i = 1; i <= getRow(); i++) {
        for (int j = 1; j <= getColums(); j++) {
            out.replace(this->getElement(i, j) & othBM.getElement(i, j), i, j);
        }
    }
    return out;
}

BooleanMatrix BooleanMatrix::operator|(const BooleanMatrix &othBM) {
    assert(row == othBM.row);
    assert(columns == othBM.columns);
    BooleanMatrix out(getRow(), getColums());
    for (int i = 1; i <= getRow(); i++) {
        for (int j = 1; j <= getColums(); j++) {
            out.replace(this->getElement(i, j) | othBM.getElement(i, j), i, j);
        }
    }
    return out;
}

BooleanMatrix BooleanMatrix::BooleanProduct(const BooleanMatrix &othBM) const {
    assert(columns == othBM.row);
    BooleanMatrix temp(row, othBM.columns);
    for (int i = 1; i <= getRow(); i++) {
        for (int j = 1; j <= temp.getColums(); j++) {
            for (int s = 1; s <= getColums(); s++) {
                //  方法一
                temp.matirx[(i - 1) * temp.columns + j - 1]
                |= getElement(i, s) & othBM.getElement(s, j);
            }
        }
    }
    return temp;
}

//  方法二
//                if (getElement(i, s) * othBM.getElement(s, j) == 1) {
//                    temp.replace(true, i, j);
//                    break;
//                }