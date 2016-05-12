//
//  ArrayList.cpp
//  D&A 5 Collection with Inheritance
//
//  Created by 邱兆丰 on 16/4/18.
//  Copyright © 2016年 菇生. All rights reserved.
//

#include "ArrayList.hpp"
#include <iostream>

ArrayList::ArrayList() {
    _size = 0;
    _maxsize = extend_factor;
    storage = new E[_maxsize];
    storage[0] = 0;
}

ArrayList::~ArrayList() {
    if (storage != NULL)
        delete []storage;
}

void ArrayList::add(E e) {
    if (_size < _maxsize) {
        storage[_size] = e;
    } else {
        extend();
        storage[_size] = e;
    }
    _size++;
}

void ArrayList::clear(void) {
    //  clear 默认保留两个
    if (storage != NULL) {
        delete []storage;
        _maxsize = extend_factor;
        _size = 0;
        storage = new E[_maxsize];
    }
}

bool ArrayList::contain(E e) {
    for (int i = 0; i < _size; i++) {
        if (storage[i] == e) {
            return true;
        }
    }
    return false;
}

bool ArrayList::isEmpty(void) {
    return _size == 0;
}

void ArrayList::remove(E e) {
    int index = _size;  //  寻求更简便的方法
    for (int i = 0; i < _size; i++) {
        if (storage[i] == e) {
            index = i;
            for (int j = index; j < _size - 1; j++) {
                storage[j] = storage[j + 1];
            }
            i--;
            _size--;
        }
    }
}

ArrayList::E& ArrayList::operator[](int index) {
    return get(index);
}

ArrayList::E& ArrayList::get(int index) {
    if (index >= 0 && index < _size) {
        return storage[index];
    }
    else return storage[0];     //  错误输出storage[0]
}

int ArrayList::indexOf(E element) {
    for (int i = 0; i < _size; i++) {
        if (storage[i] == element) {
            return i;
        }
    }
    return -1;   //  找不到返回－1；
}

void ArrayList::sort(void) {
    Qsort(storage, 0, _size - 1);
}

int ArrayList::size(void) {
    return _size;
}

void ArrayList::extend() {
    E* temp = new E[extend_factor * _maxsize];
    for (int i = 0; i < _maxsize; i++) {
        temp[i] = storage[i];
    }
    delete []storage;
    _maxsize *= extend_factor;
    storage = temp;
}
