//
//  PersonalAccount.h
//  PersonalAcount
//
//  Created by 邱兆丰 on 16/2/27.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef PERSONALACCOUNT_H
#define PERSONALACCOUNT_H

class PersonalAccount {
private:
    int balance;
public:
    PersonalAccount();
    void add(int value);
    void subtract(int value);
    void getBalance();
};

#endif
