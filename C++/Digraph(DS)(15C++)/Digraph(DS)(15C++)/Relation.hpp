#include "ProductSet.hpp"
#include "BooleanMatrix.hpp"

class Relation {
public:
    int getRow();
    int getColums();
    Relation(BooleanMatrix const &m);
protected:
    BooleanMatrix bMatrix;
};
