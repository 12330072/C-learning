//
//  Student.h
//  The Student Class with Private Data fields
//
//  Created by 邱兆丰 on 16/3/4.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include <iostream>
#include <stdio.h>
using namespace std;
class Student {
  public:
    Student();
    Student(int a);
    Student(int, const char*);
    Student(int, const char*, int);
    void set(int, const char*, int);
    void print();
  private:
    int id;
    char name[50];
    int age;
};

Student::Student() {
    id = 0;
    strncpy(name, "No Name", 50);
    age = 0;
}

Student::Student(int a, const char* b) {
    id = a;
    strncpy(name, b, 50);
    age = 0;
}


Student::Student(int a) {
    id = a;
    strncpy(name, "No Name", 50);
    age = 0;
}

Student::Student(int a, const char* b, int c) {
    id = a;
    strncpy(name, b, 50);
    age = c;
}

void Student::set(int a, const char* b, int c) {
    id = a;
    strncpy(name, b, 50);
    age = c;
}

void Student::print() {
    cout << name<< '(' << id<< ')'<< "is"<< age<< "years old."<< endl;
}

#endif /* Student_h */










