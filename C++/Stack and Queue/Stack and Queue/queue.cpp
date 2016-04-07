//
//  queue.cpp
//  Stack and Queue
//
//  Created by 邱兆丰 on 16/3/9.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "queue.hpp"

// you can not push an element when the storage is full
void queue::push(int a) {
    if ((rear + 1) % (max_size) != head) {
        storage[rear++] = a;
        if (rear == max_size) {
            rear = 0;
        }
    }
}

void queue::pop(void) {
    if (head != rear) {
        storage[head++] = 0;
        if (head == max_size) {
            head = 0;
        }
    }
}

int queue::front(void) {
    if (head == rear)
        return 0;
    else
        return head;
}

int queue::back(void) {
    if (head == rear)
        return 0;
    else
        return (rear - 1 + max_size) % max_size;        //保证不为负
}

bool queue::isFull(void) {
    if ((rear + 1) % (max_size) == head)
        return 1;
    else
        return 0;
}

bool queue::isEmpty(void){
    if (head == rear)
        return 1;
    else
        return 0;
}

void queue::clear(void) {
    head = rear = 0;
}




