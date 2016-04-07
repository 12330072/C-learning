//
//  User.cpp
//  Alipay System 1 user
//
//  Created by 邱兆丰 on 16/3/6.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "user.hpp"
#include <string.h>

bool checkC(unsigned int a) {
     if (a >= 97 && a <= 122)
         return 1;
     else if (a >= 65 && a <=90)
         return 1;
     else if (a >=48 && a <=57)
         return 1;
     else
         return 0;
}

bool alipay::User::setUsername(const char *username) {
    unsigned long sLen = strlen(username);
    unsigned int check;
    alipay::User::username = "";
    if (sLen >= 6 && sLen <= 20) {
        for (int i = 0; i < sLen; i++) {
            check = username[i];
            if (checkC(check)) {
                alipay::User::username += username[i];
            } else {
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

bool alipay::User::setPassword(const char *new_password, const char *old_password) {
    if (password != old_password)
        return 0;
    password = "";
    unsigned long sLen = strlen(new_password);
    unsigned int check;
    if (sLen >= 8 && sLen <= 20) {
        for (int i = 0; i < sLen; i++) {
            check = new_password[i];
            if (checkC(check)) {
                password += new_password[i];
            } else {
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

bool alipay::User::setPhone(const char *new_phone) {
    unsigned long sLen = strlen(new_phone);
    unsigned int check;
    phone = "";
    if (sLen == 13) {
        for (int i = 0; i < sLen; i++) {
            check = new_phone[i];
            if (check >= 48 && check <= 57) {
                phone += new_phone[i];
            } else {
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

bool alipay::User::setGender(Gender::Gender gender) {
    if (gender == 0 || gender == 1) {
        alipay::User::gender = gender;
        return 1;
    } else {
        return 0;
    }
}

std::string alipay::User::getUsername(void) {
    return username;
}

std::string alipay::User::getPhone(void) {
    return phone;
}

alipay::Gender::Gender alipay::User::getGender(void) {
    return gender;
}

long long int alipay::User::getMoneyAmount(const char *password) {
    if (alipay::User::password == password)
        return balance;
    else
        return -1;
}

bool alipay::User::deposit(long long int amount) {
    if (amount > 0) {
        balance += amount;
        return 1;
    } else {
        return 0;
    }
}

bool alipay::User::withdraw(long long int amount, const char *password) {
    if (alipay::User::password == password && amount > 0 && balance - amount >= 0) {
        balance -= amount;
        return 1;
    } else {
        return 0;
    }
}

inline bool verifyPasswordFormat(const std::string &password);
inline bool verifyUsernameFormat(const std::string &username);
inline bool verifyPhoneFormat(const std::string &phone);
