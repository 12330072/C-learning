#include <iostream>
#include <cstring>
#include "String.h"
#include <string>
using namespace std;

String a, b("MFGZ!");
String c = b;

void display() {
    cout << a.empty() << " " << a.length() << " " << a << endl;
    cout << b.empty() << " " << b.length() << " " << b << endl;
    cout << c.empty() << " " << c.length() << " " << c << endl;
}

int main() {
    string aa, bb, cc;
    display();  //r
    c[0] = 'K';
    display();  //r
    cin >> aa >> cc;
    a.assign(aa.c_str()); //r
    c.assign(cc.c_str()); //12
    display();//9
    b.clear();
    display();//12
    for (int i = 0 ; i < 10; ++i) {
        char t;
        cin >> t;
        a.append(t);
        b.append(t);
        c.append(t);
    }
    display();//15 w
    b = c;
    display();//18
    b = a + c;
    display();//21
    cout << a.find(String("1993")) << endl;
    cout << b.find(String("HYOUKA")) << endl;
    cout << c.find(String("RIKKA")) << endl; //24
    cout << a.substr(0, 3) << endl;
    cout << b.substr(3, 8) << endl;
    cout << c.substr(6, 1) << endl; //27
    cout << (a > b) << (a >= b) << (a < b) << (a <= b) << (a == b) << endl;
    cout << a.compare(b) << b.compare(a) << endl;
    cout << (a > c) << (a >= c) << (a < c) << (a <= c) << (a == c) << endl;     //30
    cout << a.compare(c) << c.compare(a) << endl;
    b = a;
    cout << (a > b) << (a >= b) << (a < b) << (a <= b) << (a == b) << endl;
    cout << a.compare(b) << b.compare(a) << endl;
    cout << a.compare(a) << endl;
    return 0;
}
