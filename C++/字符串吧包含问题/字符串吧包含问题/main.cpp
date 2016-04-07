//
//  main.cpp
//  字符串吧包含问题
//
//  Created by 邱兆丰 on 16/2/26.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    std::string str1, str2;
    for (int i = 0; i < n; i++) {
        std::cin >> str1 >> str2;
        std::size_t found = str1.find(str2);
        if (found == std::string::npos) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
    return 0;
}
