//
//  main.cpp
//  Big Integer Add & Subtract
//
//  Created by 邱兆丰 on 16/3/23.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "BigInteger.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2;
    cin >> s4;
    BigInteger a(s1);
    BigInteger b(s2);
    BigInteger c(a);
    BigInteger d(s4);
    BigInteger sum(a+b);
    BigInteger diff(c-d);
    cout << sum << endl;
    cout << diff << endl;
    return 0;
}

