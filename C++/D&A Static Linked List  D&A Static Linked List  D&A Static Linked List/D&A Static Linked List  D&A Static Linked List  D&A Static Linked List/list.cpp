//
//  list.cpp
//  D&A Static Linked List  D&A Static Linked List  D&A Static Linked List
//
//  Created by 邱兆丰 on 16/4/9.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "list.hpp"
#include <sstream>
#define newNode(a, da, po) a = empty_head; \
empty_head = storage[empty_head].next; \
storage[a].next = po; \
storage[a].data = da;
//  不能delete 名字为T的指针
#define deleteNode(a) pointer T = empty_head; \
empty_head = a; \
storage[a].next = T; \
storage[a].data = 0;

list::list() {
    _size = 0;
    head = nullpointer;
    empty_head = 0;
    for (int i = 0; i < MAX_STORAGE - 1; i++) {
        storage[i].next = i + 1;
    }
    storage[MAX_STORAGE - 1].next = nullpointer;
}

list::list(const list& another) {
    _size = 0;
    head = nullpointer;
    empty_head = 0;
    for (int i = 0; i < MAX_STORAGE - 1; i++) {
        storage[i].next = i + 1;
    }
    storage[MAX_STORAGE - 1].next = nullpointer;
    *this = another;
}

list& list::operator=(const list& another) {
    for (int i = 0; i < MAX_STORAGE; i++) {
        storage[i] = another.storage[i];
    }
    _size = another._size;
    head = another.head;
    empty_head = another.empty_head;
    return *this;
}

list::~list() {
    clear();
}

bool list::empty(void) const {
    return (_size == 0);
}

list::size_type list::size(void) const {
    return _size;
}

std::string list::toString(void) const {
    pointer p = head;
    std::ostringstream out;
    while (p != nullpointer) {
        out << storage[p].data << "->";
        p = storage[p].next;
    }
    out << "NULL";
    return out.str();
}

void list::insert(int position, const int& data) {
    if (position > _size || position < 0 || _size == MAX_STORAGE) {
        return;
    }
    else if (position == 0) {
        pointer temp;
        newNode(temp, data, head);
        head = temp;
    } else {
        pointer p = head;
        int count = position - 1;
        while (count--) {
            p = storage[p].next;
        }
        pointer temp;
        newNode(temp, data, storage[p].next);
        storage[p].next = temp;
    }
    _size++;
}

void list::erase(int position) {
    if (position >= _size || position < 0) {
        return;
    }
    else if (position == 0) {
        pointer temp = head;
        head = storage[head].next;
        deleteNode(temp);
    } else {
        pointer p = head;
        int count = position - 1;
        while (count--) {
            p = storage[p].next;
        }
        pointer temp = storage[p].next;
        storage[p].next = storage[temp].next;
        deleteNode(temp);
    }
    _size--;
}

void list::clear(void) {
    if (head != nullpointer) {
        _size = 0;
        head = nullpointer;
        empty_head = 0;
        for (int i = 0; i < MAX_STORAGE - 1; i++) {
            storage[i].next = i + 1;
        }
        storage[MAX_STORAGE - 1].next = nullpointer;
    }
}

list& list::sort(void) {
    if (head != nullpointer && storage[head].next != nullpointer) {
        pointer slow = head;
        pointer fast = storage[head].next;
        while (fast != nullpointer) {
            if (storage[fast].data >= storage[slow].data) {
                fast = storage[fast].next;
                slow = storage[slow].next;
            } else {
                pointer pre = head;
                if (storage[head].data > storage[fast].data) {
                    storage[slow].next = storage[fast].next;
                    storage[fast].next = head;
                    head = fast;
                } else {
                    while (storage[storage[pre].next].data <= storage[fast].data) {
                        pre = storage[pre].next;
                    }
                    storage[slow].next = storage[fast].next;
                    storage[fast].next = storage[pre].next;
                    storage[pre].next = fast;
                }
            }
            fast = storage[slow].next;
        }
    }
    return *this;
}
