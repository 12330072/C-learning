//
//  main.cpp
//  Construct Max Numbers [hw]
//
//  Created by 邱兆丰 on 16/4/9.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include <iostream>
#include <cstring>

bool complare(const std::string&, const std::string&);

int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    std::string a[1000];
    for (int i = 0; i < n ; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            if (!complare(a[j], a[j + 1])) {
                std::string temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n ; i++) {
        std::cout << a[i];
    }
    std::cout << std::endl;
}

//  true 不用调换，false要调换
bool complare(const std::string &a, const std::string &b) {
    unsigned long l1 = a.length();
    unsigned long l2 = b.length();
    unsigned long min = l1 > l2 ? l2 : l1;
    unsigned long max = l1 > l2 ? l1 : l2;
    for (int i = 0; i < min; i++) {
        if (a[i] > b[i]) {
            return true;
        }
        else if (a[i] < b[i]) {
            return false;
        }
    }
    for (unsigned long i = min; i < max; i++) {
        if (l1 > l2) {
            if (a[i] > b[min - 1]) {
                return true;
            }
            else if (a[i] < b[min - 1]) {
                return false;
            }
        }
    }
    return true;
}
