//
//  main.cpp
//  Inheritance(15C++)
//
//  Created by 邱兆丰 on 16/3/27.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include <iostream>
#include "Inheritance.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    cout << "\ncreat base A" << endl;
    baseA ba;
    cout << "\ncreat base B" << endl;
    baseB bb;
    cout << "\ncreat derived A" << endl;
    derivedA da;
    cout << "\ncreat derived B" << endl;
    derivedB db;
    cout << "\ncreat C" << endl;
    C c;
    cout << "\ndestructor" << endl;
    
    
    return 0;
}