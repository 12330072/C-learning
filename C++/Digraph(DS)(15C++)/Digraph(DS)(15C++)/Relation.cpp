#include "Relation.hpp"

Relation::Relation(BooleanMatrix const &m): bMatrix(m) {}

int Relation::getRow() {
    return bMatrix.getRow();
}

int Relation::getColums() {
    return bMatrix.getColums();
}
