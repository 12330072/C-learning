#include "userController.hpp"
#include <sstream>
#include <string.h>
using namespace Alipay;

userController::userController(double interest_rate) {
    userController::interest_rate = interest_rate;
    usercount = 0;
    for (int i = 0; i < MAX_USER; i++) {
        users[i] = NULL;
    }
}

userController::~userController() {
    for (int i = 0; i < usercount; i++) {
        delete users[i];
    }
}

bool userController::createUser(const char* username, const char* password) {
    if (strlen(username) > 20 || strlen(password) > 20 || strlen(username) < 6 || strlen(password) < 8) {
        return 0;
    }
    if (usercount >= MAX_USER - 1 || getUserIndex(username) != -1) {
        return 0;
    } else {
        user* temp = new user(username, password);
        users[usercount++] = temp;
        return 1;
    }
}

bool userController::removeUserByUsername(const char* username) {
    int pos = getUserIndex(username);
    if (pos == -1 || usercount == 0) {
        return 0;
    } else {
        delete users[pos];
        for (int i = pos; i < usercount - 1; i++) {
            users[i] = users[i + 1];
        }
        users[--usercount] = NULL;
        return 1;
    }
}

inline int userController::getUserIndex(const char* username) const {
    if (strlen(username) > 20|| strlen(username) < 6) {
        return -1;
    } else {
        for (int i = 0; i < usercount; i++) {
            if (strcmp(userController::users[i]->getUsername(), username) == 0)
                return i;
        }
        return -1;
    }
}

bool userController::deposite(const char* username, double amount) {
    int pos = getUserIndex(username);
    if (pos == -1) {
        return 0;
    } else {
        users[pos]->deposite(amount);
        return 1;
    }
}

bool userController::withdraw(const char* username, double amount) {
    int pos = getUserIndex(username);
    if (pos == -1) {
        return 0;
    }
    if (users[pos]->getBalance() - amount < 0) {
        return 0;
    }
    users[pos]->withdraw(amount);
    return 1;
}

std::string userController::getUserInfoByName(const char* username) const {
    std::ostringstream out;
    int i = getUserIndex(username);
    if (i == -1) {
        out << "No such user!";
        return out.str();
    } else {
        out << "username:" << username << std::endl;
        out << "password:*********" << std::endl;
        out << "balance:" << users[i]->getBalance();
        return out.str();
    }
}

int userController::getUserCount(void) const {
    return usercount;
}

bool userController::setInterest(double interest) {
    if (interest >= 0) {
        interest_rate = interest;
        return 1;
    } else {
        return 0;
    }
}

void userController::payInterest(void) {
    for (int i = 0; i < usercount; i++) {
        users[i]->deposite((users[i]->getBalance()) * interest_rate);
    }
}
