//
//  Collection.hpp
//  D&A 5 Collection with Inheritance
//
//  Created by 邱兆丰 on 16/4/18.
//  Copyright © 2016年 菇生. All rights reserved.
//

#ifndef Collection_h
#define Collection_h

class Collection {
public:
    typedef int E;
public:
    Collection() {}
    virtual ~Collection() {}
    virtual void add(E) = 0;
    virtual void clear() = 0;
    virtual bool contain(E) = 0;
    virtual bool isEmpty() = 0;
    virtual void remove(E) = 0;
    virtual int size() = 0;
    void Qsort(E *arr, E left, E right) {
        if (left >= right) {
            return;
        }
        E i = left;
        E j = right;
        E key = arr[left];
        while(i < j) {
            while (key <= arr[j] && i < j) {
                j--;
            }
            arr[i] = arr[j];
            while (key >= arr[i] && i < j) {
                i++;
            }
            arr[j] = arr[i];
        }
        arr[i] = key;
        Qsort(arr, left, i - 1);
        Qsort(arr, i + 1, right);
    }
};
#endif /* Collection_h */
