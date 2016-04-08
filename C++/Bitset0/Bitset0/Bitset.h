//
//  Bitset.h
//  Bitset0
//
//  Created by 邱兆丰 on 16/3/8.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef Bitset_h
#define Bitset_h

class Bitset {
  private:
    int n;
    bool a[1100];
  public:
    Bitset() {
        memset(a, 0, sizeof(a));
    }
    void set_size(int x) {
        n = x;
    }
    void set(int x) {
        a[x] = 1;
    }
    void print() {
        for (int i = 0; i < n; i++) {
            std::cout << a[i];
        }
        std:: cout << std::endl;
    }
};

#endif /* Bitset_h */
