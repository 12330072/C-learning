//
//  BigInteger.hpp
//  Big Integer Add & Subtract
//
//  Created by 邱兆丰 on 16/3/23.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef _BIG_INTEGER_
#define _BIG_INTEGER_

#include <iostream>
#include <string>
using std::string;
using std::ostream;

// forward declaration
class BigInteger;

// operators overloading
BigInteger operator+(const BigInteger& left, const BigInteger& right);
BigInteger operator-(const BigInteger& left, const BigInteger& right);
ostream& operator<<(ostream& out, const BigInteger& Bint);

class BigInteger {
public:
    BigInteger();
    explicit BigInteger(const string& number);
    BigInteger(const BigInteger& other);
    friend BigInteger operator+(const BigInteger& left,
                                const BigInteger& right);
    
    // promise left >= right
    friend BigInteger operator-(const BigInteger& left,
                                const BigInteger& right);
    friend ostream& operator<<(ostream& out, const BigInteger& Bint);
    ~BigInteger();
    
private:
    int *data_;
    int size_;
};

#endif  // _BIG_INTEGER_
