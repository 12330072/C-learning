//
//  cmp.h
//  template cmp
//
//  Created by 邱兆丰 on 16/4/15.
//  Copyright © 2016年 菇生. All rights reserved.
//

#ifndef cmp_h
#define cmp_h

#include <typeinfo>

template <typename T>
bool cmp(T t1, T t2) {
    return t1 == t2;
}

template <typename T>
bool cmp(T* t1, T* t2) {
    return *t1 == *t2;
}

bool cmp(char* t1, char* t2) {
    return(strcmp(t1, t2) == 0);
}
#endif /* cmp_h */
