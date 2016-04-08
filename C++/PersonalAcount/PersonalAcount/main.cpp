//
//  main.cpp
//  PersonalAcount
//
//  Created by 邱兆丰 on 16/2/27.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include<iostream>
#include "PersonalAccount.h"
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    // declare a object and it's balance is 0.
    PersonalAccount pa;
    
    // add a dollar into user's account..
    pa.add(a);
    
    // deduct b dollar from user's account..
    pa.subtract(b);
    
    // show balance..
    pa.getBalance();
}