//
//  main.cpp
//  D&A 3 Linked List Again
//
//  Created by 邱兆丰 on 16/3/19.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "List.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool condition1(list::listPointer p) { return true; }

bool condition2(list::listPointer p) {
    if (p->data % 2 == 0) {
        return false;
    }
    return true;
}

bool condition3(list::listPointer p) {
    if (p->data > 5) {
        return false;
    }
    return true;
}

void outputList(const list& li) {
    cout << li << " size:" << li.size();
    if (&li.front() == NULL) {
        cout << " front:NULL";
    } else {
        cout << " front:" << li.front();
    }
    
    if (&li.back() == NULL) {
        cout << " back:NULL";
    } else {
        cout << " back:" << li.back();
    }
    cout << endl;
}

int main() {
    int n, m;
    
    cin >> n >> m;
    
    int* a = new int[n]();
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if (true) {
        list li1(a, n);
        li1.insert(2, 111);
        li1.push_front(150);
        list li2(li1);
        outputList(li1);    //1
        outputList(li2);    //2
    }
    
    cout << endl;
    
    if (true) {
        list li1;
        for (int i = 0; i < n; i++) {
            li1.insert(i, a[i]);
        }
        for (int i = 0; i < m; i++) {
            li1.erase(i);
        }
        outputList(li1);    //3
    }
    
    cout << endl;
    
    if (true) {
        list li1(a, n), li2, li3;
        li1 = li2 = li3 = li1;
        outputList(li1);    //4
        li1.split(0, &li2, &li3);
        outputList(li1);    //5
        outputList(li2);    //6
        outputList(li3);    //7
        li1.split(li1.size(), &li2, &li3);
        outputList(li1);    //8
        outputList(li2);    //9
        outputList(li3);    //10
        li1.split(li1.size() / 2, &li2, &li3);
        cout << li2.toString() << endl;    //11
        cout << li3.toString() << endl;    //12
        li1 += (li2 += li1).merge(li1, li1);
        outputList(li1);    //13
        li1 += li3;
        li2.merge(li1, li3);
        for (int i = 0; i < li1.size(); i++) {
            cout << li1[i] << " ";
        }
        cout << endl;
        outputList(li2);    //14
    }
    
    cout << endl;
    
    cout << endl;       //双空格
    
    if (true) {
        list li1(a, n);
        li1.remove_if(condition1);
        cout << li1 << " " << endl;
        li1.assign(a, n);
        li1.remove_if(condition2);
        cout << li1 << endl;
        li1.assign(a, n);
        li1.remove_if(condition3);
        outputList(li1);
    }
    
    cout << endl;
    
    if (true) {
        list li(a, n);
        li.merge(li, li).merge(li, li).unique();
        outputList(li);
    }
    
    delete[] a;
    
    return 0;
}

