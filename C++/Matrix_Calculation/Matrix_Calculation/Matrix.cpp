#include "Matrix.h"

Matrix::Matrix(string _name, int h, int w, int** pa) {
    name = _name;
    height = h;
    width = w;
    param = new int*[height];
    for (int i = 0; i < h; i++) {
        param[i] = new int[width];
        for (int j = 0; j < w; j++) {
            param[i][j] = pa[i][j];
        }
    }
}

Matrix::Matrix(const Matrix &otherMat) {
    name = otherMat.name;
    width = otherMat.width;
    height = otherMat.height;
    param = new int*[height];
    for (int i = 0; i < height; i++) {
        param[i] = new int[width];
        for (int j = 0; j < width; j++)
            param[i][j] = otherMat.param[i][j];
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < height; i++) {
            delete []param[i];
    }
        delete []param;
}

bool Matrix::operator ==(const Matrix& othM) {
    for (int i = 0; i < othM.height; i++) {
        for (int j = 0; j < othM.width; j++) {
            if (param[i][j] != othM.param[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator !=(const Matrix& othM) {
    for (int i = 0; i < othM.height; i++) {
        for (int j = 0; j < othM.width; j++) {
            if (param[i][j] != othM.param[i][j]) {
                return true;
            }
        }
    }
    return false;
}
void Matrix::operator +=(const Matrix& othM) {
    if (height != othM.height || width != othM.width) {
        cout << "invalid addition." << endl;
        return;
    }
    for (int i = 0; i < othM.height; i++) {
        for (int j = 0; j < othM.width; j++) {
            param[i][j] += othM.param[i][j];
        }
    }
}

void Matrix::operator -=(const Matrix& othM) {
    if (height != othM.height || width != othM.width) {
        cout << "invalid substraction." << endl;
        return;
    }
    for (int i = 0; i < othM.height; i++) {
        for (int j = 0; j < othM.width; j++) {
            param[i][j] -= othM.param[i][j];
        }
    }
}

Matrix Matrix::operator *(const Matrix& othM) {
    Matrix out;
    if (width != othM.height) {
        cout << "invalid multiplication." << endl;
        return out;
    } else {
        int i, j, k;
        out.name = "newMat";
        out.height = this->height;
        out.width = othM.width;
        out.param = new int*[out.height];
        for (i = 0; i < out.height; i++) {
            out.param[i] = new int[out.width];
            for (j = 0; j < out.width; j++) {
                out.param[i][j] = 0;
            }
        }
        for (i = 0; i < out.height; i++) {
            for (j = 0; j < out.width; j++) {
                for (k = 0; k < width; k++) {
                    out.param[i][j] += (param[i][k] * othM.param[k][j]);
                }
            }
        }
        return out;
    }
}





