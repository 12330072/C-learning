//
//  list.cpp
//  D&A Simple Linked List
//
//  Created by 邱兆丰 on 16/3/11.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "list.hpp"
#include <sstream>
using namespace std;

list::list() {
    head = NULL;
    _size = 0;
}

list::list(const list& othList) {
    _size = othList._size;
    head = NULL;
    *this = othList;  //虽然它不存在，但先创建了它，然后再用＝号
}

list& list::operator=(const list& othList) {
    clear();
    _size = othList._size;
    if (_size == 0) {
        head = NULL;
    } else {
        head = new node;
        node* temp1 = othList.head;
        node* temp2 = head;
        while (temp1 != NULL) {
            temp2->data = temp1->data;
            temp1 = temp1->next;
            if (temp1 != NULL) {
                temp2->next = new node;
                temp2 = temp2->next;
            }
        }
        temp1 = NULL;
        temp2 = NULL;
    }
    return *this;
}

list::~list() {
    clear();
}

bool list::empty(void) const {
    if (head == NULL)
        return 1;
    else
        return 0;
}
int list::size(void) const {
    return _size;
}

string list::toString(void) const {
    ostringstream Stemp;
    if (this->head != NULL) {
        node* p = this ->head;
        while (p != NULL) {
            Stemp << p->data;
            Stemp << "->";
            p = p->next;
        }
        Stemp << "NULL";
        p = NULL;
    } else {
        Stemp << "NULL";
    }
    return Stemp.str();
}

void list::insert(int position, const int& data) {
    if (position > _size) {
        return;
    } else {
        node* insert = new node;
        insert->next = NULL;
        insert->data = data;
        if (position == 0) {
            insert->next = head;
            head = insert;
            _size++;
        } else {
            node* temp = head;
            node* lastTemp = NULL;
            for (int i = 0; i < position; i++) {
                lastTemp = temp;
                temp = temp->next;
            }
            lastTemp->next = insert;
            insert->next = temp;
            _size++;
        }
    }
}

void list::erase(int position) {
    node* temp = head;
    if (position > _size) {
        return;
    }
    else if (position == 0) {
        _size--;
        temp = head->next;
        delete head;
        head = temp;
    } else {
        node* lastTemp = NULL;
        for (int i = 0; i < position; i++) {
            lastTemp = temp;
            temp = temp->next;
        }
        lastTemp->next = temp->next;
        delete temp;
        _size--;
        lastTemp = NULL;
    }
    temp = NULL;
}

list& list::sort(void) {
    if (_size == 0) {
        return *this;
    } else {
        int count = _size + 2;
        node **a;
        a = new node*[count];
        node* temp = head;
        for (int i = 0; i < _size; i++) {
            a[i] = temp;
            temp = temp->next;
        }
        int m, n, dateTemp;
        for (m = 0; m < _size - 1; m++) {
            for (n = 1; n < _size - m; n++) {
                if (a[n]->data < a[n - 1]->data) {
                    dateTemp = a[n]->data;
                    a[n]->data = a[n - 1]->data;
                    a[n - 1]->data = dateTemp;
                }
            }
        }
        delete []a;
        return *this;
    }
}











