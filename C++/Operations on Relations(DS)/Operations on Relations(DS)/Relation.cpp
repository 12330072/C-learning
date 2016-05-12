#include "Relation.hpp"

Relation::Relation(BooleanMatrix const &oth) : matrix(oth) {}

BooleanMatrix Relation::getBooleanMatrix() const {
    return matrix;
}

Relation Relation::complementary() const {
    Relation temp(matrix);
    for (int i = 1; i <= matrix.getRow(); i++) {
        for (int j = 1; j <= matrix.getColums(); j++) {
            temp.matrix.replace(!temp.matrix.getElement(i, j), i, j);
        }
    }
    return temp;
}

Relation Relation::inverse() const {
    Relation out(matrix.transpose());
    return out;
}

Relation Relation::operator&(const Relation& oth) {
    Relation temp(matrix & oth.matrix);
    return temp;
}

Relation Relation::operator|(const Relation& oth) {
    Relation temp(matrix | oth.matrix);
    return temp;
}
