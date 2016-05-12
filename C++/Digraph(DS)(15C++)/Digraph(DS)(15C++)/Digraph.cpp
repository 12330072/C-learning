#include "Digraph.hpp"

Digraph::Digraph(BooleanMatrix const &m, Set const &s): Relation(m), set(s) {}

int Digraph::inDegree(int e) {
    if (set.isInSet(e)) {
        int sum = 0;
        int pos = getSetElePos(e);
        for (int i = 1; i <= bMatrix.getRow(); i++) {
            sum += bMatrix.getElement(i, pos);
        }
        return sum;
    }
    return -1;
}

int Digraph::outDegree(int e) {
    if (set.isInSet(e)) {
        int sum = 0;
        int pos = getSetElePos(e);
        for (int i = 1; i <= bMatrix.getColums(); i++) {
            if (bMatrix.getElement(pos, i) == true) {
                sum++;
            }
        }
        return sum;
    }
    return -1;
}

Digraph Digraph::pathOfLength(int n) {
    BooleanMatrix out = bMatrix;
    if (n == -1) {
        while (true) {
            if (out == out.BooleanProduct(bMatrix)) {
                break;
            }
            out = out.BooleanProduct(bMatrix);
        }
    } else {
        for (int i = 1; i < n; i++) {
            out = out.BooleanProduct(bMatrix);
        }
    }
    Digraph Dout(out, set);
    return Dout;
}

bool Digraph::isReflexive() const {
    if (bMatrix.isSquareMatrix() == 0)
        return false;
    for (int i = 1; i <= bMatrix.getRow(); i++) {
        if (bMatrix.getElement(i, i) == 0)
            return false;
    }
    return true;
}

bool Digraph::isIrreflexive() const {
    if (bMatrix.isSquareMatrix() == 0)
        return false;
    for (int i = 1; i <= bMatrix.getRow(); i++) {
        if (bMatrix.getElement(i, i) != 0)
            return false;
    }
    return true;
}

bool Digraph::isSymmetric() const {
    if (bMatrix.isSquareMatrix() == 0)
        return false;
    if (bMatrix == bMatrix.transpose()) {
        return true;
    }
    else
        return false;
}

bool Digraph::isAsymmetric() const {
    if (bMatrix.isSquareMatrix() == 0)
        return false;
    for (int i = 1; i <= bMatrix.getRow(); i++) {
        for (int j = 1; j <= bMatrix.getColums(); j++) {
            if (bMatrix.getElement(i, j) == 1
                && bMatrix.getElement(j, i) == 1) {
                return false;
            }
        }
    }
    return true;
}

bool Digraph::isAntisymmetric() const {
    if (bMatrix.isSquareMatrix() == 0)
        return false;
    for (int i = 1; i <= bMatrix.getRow(); i++) {
        for (int j = 1; j <= bMatrix.getColums(); j++) {
            if (i != j
                && bMatrix.getElement(i, j) == 1
                && bMatrix.getElement(j, i) == 1) {
                return false;
            }
        }
    }
    return true;
}

bool Digraph::isTransitive() const {
    for (int i = 1; i <= bMatrix.getRow(); i++) {
        for (int j = 1; j <= bMatrix.getColums(); j++) {
            for (int k = 1; k <= bMatrix.getRow(); k++) {
                if (bMatrix.getElement(i, k) == 1
                    && bMatrix.getElement(k, j) == 1
                    && bMatrix.getElement(i, j) == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

BooleanMatrix Digraph::getBooleanMatrix() const {
    return bMatrix;
}

int Digraph::getSetElePos(int n) {
    for (int i = 1; i <= set.getSize(); i++) {
        if (set.get(i) == n)
            return i;
    }
    return -1;
}
