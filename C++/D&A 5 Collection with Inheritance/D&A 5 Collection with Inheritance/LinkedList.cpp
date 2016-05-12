//
//  LinkedList.cpp
//  D&A 5 Collection with Inheritance
//
//  Created by 邱兆丰 on 16/4/18.
//  Copyright © 2016年 菇生. All rights reserved.
//

#include "LinkedList.hpp"

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
    _size = 0;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::add(E e) {
    //  不知道题目要在头加还是在尾部加，先在头加；
    if (head == NULL) {
        head = new node(e, NULL, NULL);
        tail = head;
        _size++;
    } else {
        node* temp = new node(e, head, NULL);
        head->prev = temp;
        head = temp;
        _size++;
    }
}

void LinkedList::clear(void) {
    node* p = head;
    node* temp = NULL;
    if (p != NULL) {
        while (p->next != NULL) {
            temp = p;
            p = p->next;
            delete temp;
        }
        delete p;
    }
    head = NULL;
    tail = NULL;
    _size = 0;
}

bool LinkedList::contain(E e) {
    node* p = head;
    while (p != NULL) {
        if (p->data == e) {
            return true;
        }
        p = p-> next;
    }
    return false;
}

bool LinkedList::isEmpty(void) {
    return _size == 0;
}

void LinkedList::remove(E e) {
    node* p = head;
    node* temp = NULL;
    while (p != NULL) {
        if (p->data == e) {
            if (_size == 1) {
                delete head;
                tail = NULL;
                head = NULL;
                p = NULL;
                _size--;
                return;
            }
            else if (p == head) {
                temp = p;
                p = p->next;
                p->prev = NULL;
                head = p;
                delete temp;
            }
            else if (p == tail) {
                tail = p->prev;
                p->prev->next = NULL;
                delete p;
                p = NULL;
            } else {
                p->next->prev = p->prev;
                p->prev->next = p->next;
                temp = p->next;
                delete p;
                p = temp;
            }
            _size--;
        } else {
            p = p->next;
        }
    }
}

Collection::E& LinkedList::operator[](int index) {
    return get(index);
}

Collection::E& LinkedList::get(int index) {
    node* p = head;
    while (index--) {
        p = p->next;
    }
    return p->data;
    // 无错误判定
}

int LinkedList::indexOf(E element) {
    node* p = head;
    unsigned count = 0;
    while (p != NULL) {
        if (p->data == element) {
            return count;
        }
        count++;
        p = p->next;
    }
    return -1;
}

void LinkedList::sort(void) {
    if (_size > 1) {
        node* slow = head;
        node* fast = head->next;
        node* p = NULL;
        while (fast != NULL) {
            if (fast->data >= slow->data) {
                fast = fast->next;
                slow = slow->next;
            } else {
                p = head;
                if (head->data > fast->data) {
                    slow->next = fast->next;
                    if (fast->next != NULL) {
                        fast->next->prev = slow;
                    }
                    fast->next = head;
                    fast->prev = NULL;
                    head->prev = fast;
                    head = fast;
                } else {
                    while (p->next->data <= fast->data) {
                        p = p->next;
                    }
                    slow->next = fast->next;
                    if (fast->next != NULL) {
                        fast->next->prev = slow;
                    }
                    fast->next = p->next;
                    p->next->prev = fast;
                    p->next = fast;
                    fast->prev = p;
                }
                fast = slow->next;
            }
        }
        tail = slow;
    }
}

int LinkedList::size(void) {
    return _size;
}
