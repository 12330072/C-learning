#include "Matrices.hpp"

Matrix::Matrix(Matrix const & othM) {
    row = othM.row;
    columns = othM.columns;
    matrix = new double[othM.row * othM.columns];
    for (int i = 0; i < row * columns; i++) {
        matrix[i] = othM.matrix[i];
    }
}

Matrix::Matrix(int r, int c) {
    if (r == 0 && c == 0) {
        row = 1;
        columns = 1;
        matrix = new double[1];
        matrix[0] = 0;
    } else {
        row = r;
        columns = c;
        matrix = new double[row * columns];
        for (int i = 0; i < row * columns; i++) {
            matrix[i] = 0;
        }
    }
}

Matrix::~Matrix() {
    delete []matrix;
}

Matrix Matrix::identifyMatrix(int n) {
    Matrix out(n, n);
    for (int i = 0; i < n * n; i++) {
        if (i % (out.columns + 1) == 0) {
            out.matrix[i] = 1;
        }
    }
    return out;
}

bool Matrix::replace(matrix_element_type e, int r, int c) {
    if (r > row || c > columns)
        return false;
    matrix[(r - 1) * columns + c - 1] = e;
    return true;
}

bool Matrix::isDiagonalMatrix() const {
    if (row != columns)
        return false;
    for (int i = 0; i < row * columns; i++) {
        if (i % (columns + 1) == 0) {
            continue;
        } else {
            if (matrix[i] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isZeroMatrix() const {
    for (int i = 0; i < row * columns; i++) {
        if (matrix[i] != 0)
            return false;
    }
    return true;
}

bool Matrix::isSquareMatrix() const {
    return (columns == row);
}

bool Matrix::isSymmetrix() const {
    if (row != columns)
        return false;
    for (int i = 0; i < row; i++) {
        for(int j = 0; j < columns; j++) {
            if (matrix[i * columns + j] != matrix[j * columns + i]) {
                return false;
            }
        }
    }
    return true;
}

Matrix Matrix::transpose() const {
    Matrix newMatrix(columns, row);
    for (int i = 0; i < newMatrix.row; i++) {
        for(int j = 0; j < newMatrix.columns; j++) {
            newMatrix.matrix[i * newMatrix.columns + j] = matrix[j * columns + i];
        }
    }
    return newMatrix;
}

Matrix& Matrix::operator=(const Matrix & m) {
    delete []matrix;
    row = m.row;
    columns = m.columns;
    matrix = new double[m.row * m.columns];
    for (int i = 0; i < row * columns; i++) {
        matrix[i] = m.matrix[i];
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix & m) {
    if (row != m.row && columns != m.columns) {
        return *this;
    } else {
        Matrix newMatrix(row, columns);
        for (int i = 0; i < row * columns; i++) {
            newMatrix.matrix[i] = matrix[i] + m.matrix[i];
        }
        return newMatrix;
    }
}

Matrix Matrix::operator*(const Matrix & m) {
    if (m.row != columns) {
        return *this;
    } else {
        Matrix newMatrix(row, m.columns);
        for (int i = 0; i < newMatrix.row; i++) {
            for (int j = 0; j < newMatrix.columns; j++) {
                for (int k = 0; k < columns; k++) {
                    newMatrix.matrix[i * newMatrix.columns + j] += matrix[i * columns + k] * m.matrix[k * m.columns + j];
                }
            }
        }
        return newMatrix;
    }
}

bool Matrix::operator==(const Matrix & m) const {
    if (row != m.row || columns != m.columns) {
        return false;
    } else {
        for (int i = 0; i < row * columns; i++) {
            if (matrix[i] != m.matrix[i])
                return false;
        }
    }
    return true;
}


int Matrix::getRow() const {
    return row;
}

int Matrix::getColumns() const {
    return columns;
}

Matrix::matrix_element_type Matrix::getElement(int r, int c) const {
    return matrix[(r - 1) * columns + c - 1];
}










