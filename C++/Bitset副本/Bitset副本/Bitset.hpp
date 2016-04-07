//
//  Bitset.hpp
//  Bitset副本
//
//  Created by 邱兆丰 on 16/3/15.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef BITSET_H
#define BITSET_H
#include<iostream>
#define N 5
const int max_length = 32 * N;
class Bitset {
private:
    int a[5];
public:
    Bitset();
    void set(int pos);
    void reset(int pos);
    int count() const;
    bool test(int pos) const;
    bool any() const;
    bool none() const;
    bool all() const;
    Bitset& operator&= (const Bitset& b);
    Bitset& operator|= (const Bitset& b);
    Bitset& operator^= (const Bitset& b);
    Bitset& operator= (const Bitset& b);
    Bitset& operator <<= (int pos);
    Bitset& operator >>= (int pos);
    Bitset operator~() const;
    Bitset operator&(const Bitset& b) const;
    Bitset operator|(const Bitset& b) const;
    Bitset operator^(const Bitset& b) const;
    Bitset operator<<(int pos) const;
    Bitset operator>>(int pos) const;
    bool operator== (const Bitset& b) const;
    bool operator!= (const Bitset& b) const;
    bool operator[] (int pos) const;
    friend std::ostream& operator << (std::ostream& os, const Bitset& s) {
        for (int i = 5-1; i >= 0; i--) {
            for (int j = 31; j >= 0; j--) {
                if (s.a[i] & (1 << j)) os << 1;
                else os << 0;
            }
        }
        return os;
    }
};
#endif

