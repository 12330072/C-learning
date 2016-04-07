//
//  PersonalAccount.hpp
//  BankAccount-1
//
//  Created by 邱兆丰 on 16/4/1.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef SSCPP2014_PER_ACCOUNT_H
#define SSCPP2014_PER_ACCOUNT_H

#include "Account.h"

class PersonalAccount : public Account {
private:
    static int _total_per_account;
    static int _acc_id_ptr;
public:
    PersonalAccount();
    ~PersonalAccount();
    // override
    std::string profile() const;
    void reset();
    // static
    static int get_total_per_account();
};

#endif