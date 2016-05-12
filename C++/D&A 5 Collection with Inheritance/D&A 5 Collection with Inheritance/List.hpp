//
//  List.hpp
//  D&A 5 Collection with Inheritance
//
//  Created by 邱兆丰 on 16/4/18.
//  Copyright © 2016年 菇生. All rights reserved.
//

#ifndef List_h
#define List_h
#include "Collection.hpp"

class List : public Collection {
public:
    virtual E& operator[](int index) = 0;
    virtual E& get(int index) = 0;
    virtual int indexOf(E) = 0;
    virtual void sort() = 0;
};

#endif /* List_h */
