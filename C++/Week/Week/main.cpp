//
//  main.cpp
//  Week
//
//  Created by 邱兆丰 on 16/4/7.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include <iostream>

void try1(int *i);

int main(int argc, const char * argv[]) {
    enum Week {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
    Week a, b, c;
    int i = 2;
    try1(&i);
    a = Monday;
    b = Tuesday;
    c = Week(3);
  std::cout << i;
}

void try1(int *i) {
    *i = *i + 21;
}
