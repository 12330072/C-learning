//
//  IntegerSet.cpp
//  IntegerSet(for lab)
//
//  Created by 邱兆丰 on 16/3/18.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "IntegerSet.h"

void IntegerSet::emptySet() {
    for (int i = 0; i < 101; i++) {
        set[i] = 0;
    }
}

IntegerSet::IntegerSet(int s[], int l) {
    emptySet();
    for (int i = 0; i < l; i++) {
        if (validEntry(s[i]) == 0)
            cout << "Invalid insert attempted!" << endl;
        else
        set[s[i]] = 1;
    }
}

void IntegerSet::insertElement(int element) {
    if (validEntry(element))
        set[element] = 1;
    else if (element != -1)
        cout << "Invalid insert attempted!" << endl;
}

void IntegerSet::deleteElement(int element) {
    if (validEntry(element))
        set[element] = 0;
    else if (element != -1)
        cout << "Invalid insert attempted!" << endl;
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet& othSet) {
    IntegerSet uni = IntegerSet();
    for (int i = 0; i < 101; i++) {
        if (set[i] || othSet.set[i]) {
            uni.set[i] = 1;
        }
    }
    return uni;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& othSet) {
    IntegerSet uni = IntegerSet();
    for (int i = 0; i < 101; i++) {
        if (set[i] && othSet.set[i]) {
            uni.set[i] = 1;
        }
    }
    return uni;
}

bool IntegerSet::isEqualTo(const IntegerSet& othSet) const {
    int count = 0;
    for (int i = 0; i < 101; i++) {
        if (set[i] == othSet.set[i])
            count++;
    }
    if (count == 101)
        return true;
    else
        return false;
}









