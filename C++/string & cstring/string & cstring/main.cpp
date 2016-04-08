//
//  main.cpp
//  string & cstring
//
//  Created by 邱兆丰 on 16/2/29.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include "exchange.h"
std::string st1;
char st2[100];
int main() {
    std::cin >> st1;
    change2(st1, st2);
    puts(st2);
    scanf("%s", st2);
    std::cout << change1(st2) << std::endl;
    return 0;
}