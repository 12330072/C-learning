//
//  array.cpp
//  D&A 2 Array
//
//  Created by 邱兆丰 on 16/3/14.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "array.hpp"

array::array(size_t size) {
    _data = new int[size];
    _size = size;
}

array::~array() {
    _size = 0;
    delete []_data;
}

unsigned int array::max_size(void) {
    return _size;
}

int& array::at(const data_type& i) {
    return _data[i];
}

int& array::front() {
    return _data[0];
}

int& array::back() {
    return _data[_size - 1];
}

int* array::data() {
    return _data;
}

void array::fill(const data_type& value) {
    for (int i = 0; i < _size; i++) {
        _data[i] = value;
    }
}

void array::resize(int newSize) {
    int* LData = _data;
    _data = new int[newSize];
    for (int i = 0; i < _size; i++) {
        _data[i] = LData[i];
    }
    _size = newSize;
    delete []LData;
}

void array::sort(int from, int to) {
    int i, j, temp;
    for (i = 1; i < to - from; i++) {
        for (j = from; j < to - i; j++) {
            if (_data[j] > _data[j + 1]) {
                temp = _data[j];
                _data[j] = _data[j + 1];
                _data[j + 1] = temp;
            }
        }
    }
}







