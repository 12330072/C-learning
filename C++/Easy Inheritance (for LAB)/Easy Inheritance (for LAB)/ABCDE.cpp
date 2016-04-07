//
//  ABCDE.cpp
//  Easy Inheritance (for LAB)
//
//  Created by 邱兆丰 on 16/3/25.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//
#include<iostream>

using namespace std;

class E {
public:
    E() {
        cout << "In E()" << endl;
    }
    
    ~E() {
        cout << "In ~E()" << endl;
    }
};

class C {
public:
    C() {
        cout << "In C()" << endl;
    }
    
    ~C() {
        cout << "In ~C()" << endl;
    }
};

class A : C{
public:
    A() {
        cout << "In A()" << endl;
    }
    
    ~A() {
        cout << "In ~A()" << endl;
    }
};

class D : E, C{
public:
    D() {
        cout << "In D()" << endl;
    }
    
    ~D() {
        cout << "In ~D()" << endl;
    }
};

class B : D, A {
public:
    B() {
        cout << "In B()" << endl;
    }
    
    ~B() {
        cout << "In ~B()" << endl;
    }
};






