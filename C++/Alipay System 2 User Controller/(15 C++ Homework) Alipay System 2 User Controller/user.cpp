#include "user.hpp"
#include <string.h>
#include <cstdio>
using namespace Alipay;

user::user(const char* username, const char* password) {
    setUsername(username);
    setPassword(password);
    balance = 0.0;
}

user::~user() {}

const char* user::getUsername() const {
    return username;
}
const char* user::getPassword() const {
    return password;
}

const void user::setUsername(const char* username) {
    snprintf(this->username, sizeof(this->username), username);
}

const void user::setPassword(const char* password) {
    snprintf(this->password, sizeof(this->password), password);
}

double user::getBalance() {
    return balance;
}

bool user::withdraw(double amount) {
    if (balance - amount < 0) {
        return 0;
    } else {
        balance -= amount;
        return 1;
    }
}

bool user::deposite(double amount) {
    if (amount > 0) {
        balance += amount;
        return 1;
    } else {
        return 0;
    }
}
