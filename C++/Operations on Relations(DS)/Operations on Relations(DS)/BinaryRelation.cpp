#include "BinaryRelation.hpp"

BinaryRelation::BinaryRelation(BooleanMatrix const &m, Set const &s)
: Relation(m), set(s) {}

int BinaryRelation::getSetElePos(int n) {
    for (int i = 1; i <= set.getSize(); i++) {
        if (set.get(i) == n) {
            return i;
        }
    }
    return -1;
}

int BinaryRelation::outDegree(int n) {
    if (set.isInSet(n)) {
        int sum = 0;
        int pos = getSetElePos(n);
        for (int i = 1; i <= matrix.getColums(); i++) {
            if (matrix.getElement(pos, i)) {
                sum++;
            }
        }
        return sum;
    }
    return -1;
}

int BinaryRelation::inDegree(int n) {
    if (set.isInSet(n)) {
        int sum = 0;
        int pos = getSetElePos(n);
        for (int i = 1; i <= matrix.getRow(); i++) {
            if (matrix.getElement(i, pos)) {
                sum++;
            }
        }
        return sum;
    }
    return -1;
}

BinaryRelation BinaryRelation::pathOfLength(int n) {
    BooleanMatrix temp1(matrix);
    if (n == -1) {
        while (!(temp1 == temp1.BooleanProduct(matrix))) {
            temp1 = temp1.BooleanProduct(matrix);
        }
    } else {
        for (int i = 1; i < n; i++) {
            temp1 = temp1.BooleanProduct(matrix);
        }
    }
    BinaryRelation temp2(temp1, set);
    return temp2;
}

bool BinaryRelation::isReflexive() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        if (matrix.getElement(i, i) != true) {
            return false;
        }
    }
    return true;
}

bool BinaryRelation::isIrreflexive() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        if (matrix.getElement(i, i) == true) {
            return false;
        }
    }
    return true;
}

bool BinaryRelation::isSymmetric() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        for (int j = 1; j <= matrix.getColums(); j++) {
            if (matrix.getElement(i, j) == true &&
                matrix.getElement(j, i) == false) {
                return false;
            }
        }
    }
    return true;
}

bool BinaryRelation::isAsymmetric() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        for (int j = 1; j <= matrix.getColums(); j++) {
            if (matrix.getElement(i, j) == true &&
                matrix.getElement(j, i) == true) {
                return false;
            }
        }
    }
    return true;
}

bool BinaryRelation::isAntisymmetric() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        for (int j = 1; j <= matrix.getColums(); j++) {
            if (i != j &&
                matrix.getElement(i, j) == true &&
                matrix.getElement(j, i) == true) {
                return false;
            }
        }
    }
    return true;
}

bool BinaryRelation::isTransitive() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        for (int j = 1; j <= matrix.getColums(); j++) {
            for (int k = 1; k <= matrix.getRow(); k++) {
                if (matrix.getElement(i, k) == true &&
                    matrix.getElement(k, j) == true &&
                    matrix.getElement(i, j) == false) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool BinaryRelation::isEquivalence() const {
    return (isReflexive() && isSymmetric() && isTransitive());
}

BinaryRelation BinaryRelation::composition(const BinaryRelation &oth) {
    BooleanMatrix temp = matrix.BooleanProduct(oth.getBooleanMatrix());
    BinaryRelation out(temp, set);
    return out;
}

BinaryRelation BinaryRelation::reflexiveClosure() const {
    BooleanMatrix temp(matrix);
    for (int i = 1; i <= matrix.getRow(); i++) {
        temp.replace(true, i, i);
    }
    BinaryRelation out(temp, set);
    return out;
}

BinaryRelation BinaryRelation::symmetricClosure() const {
    BooleanMatrix temp(matrix.transpose());
    for (int i = 1; i <= matrix.getRow(); i++) {
        for (int j = 1; j <= matrix.getColums(); j++) {
            if (matrix.getElement(i, j) == true) {
                temp.replace(true, i, j);
            }
        }
    }
    BinaryRelation out(temp, set);
    return out;
}

BinaryRelation BinaryRelation::transitiveClosure() const {
    BooleanMatrix temp(matrix);
    for (int k = 1; k <= matrix.getRow() ; k++) {
        for (int i = 1; i <= matrix.getRow(); i++) {
            for (int j = 1; j <= matrix.getRow(); j++) {
                if (temp.getElement(i, k) && temp.getElement(k, j)) {
                    temp.replace(true, i, j);
                }
            }
        }
    }
    BinaryRelation out(temp, set);
    return out;
}
