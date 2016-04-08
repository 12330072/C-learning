//
//  PersonalAccount.c
//  PersonalAcount
//
//  Created by 邱兆丰 on 16/2/27.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "PersonalAccount.h"
#include <iostream>

PersonalAccount::PersonalAccount() {
    balance = 0;
}
void PersonalAccount::add(int value) {
    balance += value;
}
void PersonalAccount::subtract(int value) {
    int count = balance - value;
    if (count < 0) {
        std::cout << "insufficient balance..\n";
    } else {
        balance = count;
    }
}
void PersonalAccount::getBalance() {
    std::cout << "The Balance is:"<< balance<< "\n";
}