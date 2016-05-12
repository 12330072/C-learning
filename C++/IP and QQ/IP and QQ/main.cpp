//
//  main.cpp
//  IP and QQ
//
//  Created by 邱兆丰 on 16/5/6.
//  Copyright © 2016年 菇生. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <iterator>
#include <string>
using namespace std;

typedef pair<string, set<string> > Pair;

int main() {
    int n;
    string qq, id;
    map<string, set<string> > QQ;
    map<string, set<string> > ID;
    cin >> n;
    map<string, set<string> >::iterator iter;
    set<string>::iterator s_iter;
    while (n--) {
        cin >> qq >> id;
        QQ[qq].insert(id);
        ID[id].insert(qq);
    }
    cin >> id >> qq;
    iter = ID.find(id);
    if (iter != ID.end()) {
        cout << id << " ==> " << "[ ";
        for (s_iter = iter->second.begin(); s_iter != iter->second.end(); s_iter++) {
            cout << *s_iter << ' ';
        }
        cout << ']' << endl;
    } else {
        cout << "no qq" << endl;
    }
    iter = QQ.find(qq);
    if (iter != QQ.end()) {
        cout << qq << " ==> " << "[ ";
        for (s_iter = iter->second.begin(); s_iter != iter->second.end(); s_iter++) {
            cout << *s_iter << ' ';
        }
        cout << ']' << endl;
    } else {
        cout << "no ip" << endl;
    }
}
