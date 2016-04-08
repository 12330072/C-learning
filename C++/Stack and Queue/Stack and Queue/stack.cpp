//
//  stack.cpp
//  Stack and Queue
//
//  Created by 邱兆丰 on 16/3/9.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "stack.hpp"

void stack::push(int a) {
    if (top < max_size - 1) {
        storage[++top] = a;
    }
}

void stack::pop(void) {
    if (top > -1) {
        storage[top--] = 0;
    }
}

int stack::peek(void) {
    if (top == -1)
        return 0;
    else
        return storage[top];
}

bool stack::isEmpty(void) {
    if (top == -1)
        return 1;
    else
        return 0;
}

bool stack::isFull(void) {
    if (top == max_size - 1)
        return 1;
    else
        return 0;
}

void stack::clear(void) {
    top = -1;
}
