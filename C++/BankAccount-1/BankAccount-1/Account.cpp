//
//  Account.cpp
//  BankAccount-1
//
//  Created by 邱兆丰 on 16/4/1.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "Account.h"
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

int Account::_total_account = 0;

Account::Account() {
    _id = 0;
    _balance = 0.0;
    _valid = false;
    _total_account++;
}

Account::~Account() {
    _balance = 0.0;
    _total_account--;
    _valid = false;
}

int Account::id() const {
    return _id;
}

double Account::balance() const {
    return _balance;
}

bool Account::valid() const {
    return _valid;
}

string Account::profile() const {
    ostringstream out;
    out << "ID:" << _id << endl;
    out << "BALANCE:" << setprecision(6) << fixed << _balance << endl;
    out << "VALID:N" << endl;
    return out.str();
}

void Account::reset() {
    _balance = 0.0;
    _valid = false;
    _total_account = 0;
}

bool Account::deposit(const double &num) {
    if (num > 0) {
        _balance += num;
        return true;
    }
    return false;
}

bool Account::draw(const double &num) {
    if (_balance - num >= 0.01 && num > 0) {
        _balance -= num;
        return true;
    }
    return false;
}

int Account::get_total_account() {
    return _total_account;
}
