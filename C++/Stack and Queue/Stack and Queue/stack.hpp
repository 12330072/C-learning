//
//  stack.hpp
//  Stack and Queue
//
//  Created by 邱兆丰 on 16/3/9.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef STACK_H_
#define STACK_H_
#define MAX_SIZE 10

class stack {
private:
    int * storage;
    int max_size;
    int top;
public:
    stack() {
        this->storage = new int[MAX_SIZE]();
        this->max_size = MAX_SIZE;
        this->top = -1;
    }
    ~stack() {
        delete []this->storage;
    }
    void push(int);
    void pop(void);
    int peek(void);
    bool isEmpty(void);
    bool isFull(void);
    void clear(void);
};

#endif
