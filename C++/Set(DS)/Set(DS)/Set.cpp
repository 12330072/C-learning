//
//  Set.cpp
//  Set(DS)
//
//  Created by 邱兆丰 on 16/3/7.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "Set.hpp"

Set::Set() {
    size = 0;
}

Set::Set(int* m, int s) {
    int count = 0;
    bool check;
    for (int i = 0; i < s; i++) {
        check = 0;
        for (int j = 0; j < i; j++) {
            if (members[j] == *(m + i)) {
                count++;
                check = 1;
                break;
            }
        }
        if (check == 1) {
            continue;
        } else {
            members[i - count] = *(m + i);
        }
    }
    size = s - count;
}

bool Set::append(int e) {
    for (int i = 0; i < size; i++) {
        if (members[i] == e)
            return 0;
    }
    members[size] = e;
    size++;
    return 1;
}

bool Set::remove(int e) {
    int check = -1;
    int i;
    for (i = 0; i < size; i++) {
        if (members[i] == e) {
            check = i;
            break;
        }
    }
    if (check != -1) {
        if (check == size - 1) {
            members[size - 1] = 0;
            size--;
            return 1;
        } else {
            for (i = check; i < size - 1; i++) {
                members[i] = members[i + 1];
            }
            members[size - 1] = 0;
            size--;
            return 1;
        }
    } else {
        return 0;
    }
}

bool Set::isEmptySet() {
    if (size == 0)
        return 1;
    else
        return 0;
}

int* Set::getMembers() {
    return members;
}

int Set::getSize() {
    return size;
}

bool Set::isInSet(int e) {
    int check = -1;
    int i;
    for (i = 0; i < size; i++) {
        if (members[i] == e) {
            check = i;
            break;
        }
    }
    if (check == -1)
        return 0;
    else
        return 1;
}
