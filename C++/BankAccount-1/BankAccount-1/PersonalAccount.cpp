//
//  PersonalAccount.cpp
//  BankAccount-1
//
//  Created by 邱兆丰 on 16/4/1.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "PersonalAccount.h"
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

int PersonalAccount::_total_per_account = 0;
int PersonalAccount::_acc_id_ptr = 12010000;

PersonalAccount::PersonalAccount() {
    _id = PersonalAccount::_acc_id_ptr++;
    _total_per_account++;
    _balance = 10.0;
}

PersonalAccount::~PersonalAccount() {
    _total_per_account--;
}

string PersonalAccount::profile() const {
    ostringstream out;
    out << "ID:" << _id << endl;
    out << "BALANCE:" << setprecision(6) << fixed << _balance << endl;
    out << "VALID:Y" << endl;
    out << "TYPE:PERSONAL" << endl;
    return out.str();
}

void PersonalAccount::reset() {
    _balance = 10.0;
}

int PersonalAccount::get_total_per_account() {
    return _total_per_account;
}
