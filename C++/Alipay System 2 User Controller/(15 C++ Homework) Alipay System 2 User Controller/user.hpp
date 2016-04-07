//
//  user.hpp
//  (15 C++ Homework) Alipay System 2 User Controller
//
//  Created by 邱兆丰 on 16/3/28.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef ALIPAY_USER_H_
#define ALIPAY_USER_H_
namespace Alipay {
    class user {
        char username[21];
        char password[21];
        double balance;
        
    public:
        user(const char* username, const char* password);
        ~user();
        const char* getUsername() const;
        const char* getPassword() const;
        const void setUsername(const char* username);
        const void setPassword(const char* password);
        
        double getBalance();
        
        bool withdraw(double amount);
        bool deposite(double amount);
    };
}
#endif  // !ALIPAY_USER_H_

