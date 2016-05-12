//
//  Bitset.h
//  Bitset2
//
//  Created by 邱兆丰 on 16/4/15.
//  Copyright © 2016年 菇生. All rights reserved.
//

#ifndef Bitset_h
#define Bitset_h

template <size_t bitLen>
class bitset {
public:
    bitset();
    void set(int n);
    int count();
private:
    bool bit[bitLen];
};

#include "bitset.cpp"

#endif /* Bitset_h */
