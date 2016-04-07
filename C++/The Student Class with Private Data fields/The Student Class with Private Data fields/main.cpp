//
//  main.cpp
//  The Student Class with Private Data fields
//
//  Created by 邱兆丰 on 16/3/4.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include <iostream>
#include "Student.h"
using std::cin;
int main() {
    int test;
    int id, nid, age;
    char names[10][20] = { "Aries", "Bill gates",
        "John Smith", "Blanton",
        "Blanche", "Halley",
        "Hamilton", "Rachel",
        "Jacobs", "Jan"};
    cin >> test;
    cin >> id >> nid >> age;
    if (test == 0) {
        Student st;
        st.print();
    } else if (test == 1) {
        Student st(id, names[nid], age);
        st.print();
    } else if (test == 2) {
        Student st;
        st.set(id, names[nid], age);
        st.print();
    } else if (test == 3) {
        Student st(id);
        st.print();
    } else {
        Student st(id, names[nid]);
        st.print();
    }
    return 0;
}