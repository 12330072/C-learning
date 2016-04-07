#include <iostream>
#include "Account.h"
#include "PersonalAccount.h"
#include "VIPAccount.h"
using namespace std;

void display_count() {
    cout << Account::get_total_account() << ",";
    cout << PersonalAccount::get_total_per_account() << ",";
    cout << VIPAccount::get_total_vip_account() << endl;
}

int main() {
    display_count();//  1
    if (true) {
        Account a0, a1, a2;
        display_count();//  2
        PersonalAccount b0, b1;
        display_count();//     3
    }
    VIPAccount c0, c1, c2, c3;
    display_count();//  4
    
    Account *bptr = new Account();
    cout << bptr->profile() << endl;    //5-8
    cout << bptr->id() << bptr->balance() << bptr->valid() << endl; //  9
    delete bptr;
    
    PersonalAccount *pptr = new PersonalAccount();
    cout << pptr->profile() << endl;        //10-14
    for (int i = 0; i < 5; ++i) {   //输入5个输出5个
        double t;
        int op;
        cin >> op >> t;
        if (op < 5) {
            cout << pptr->deposit(t) << ", ";
        } else {
            cout << pptr->draw(t) << ", ";
        }
        cout << pptr->balance() << endl;
    }
    cout << pptr->profile() << endl;//  20-24
    pptr->reset();
    cout << pptr->profile() << endl;//  25-29
    delete pptr;
    
    VIPAccount *vptr = new VIPAccount();
    cout << vptr->profile() << endl;//  30-35
    for (int i = 0; i < 5; ++i) {
        double t;
        int op;
        cin >> op >> t;
        if (op < 5) {
            cout << vptr->loan(t);
        } else {
            cout << vptr->repay(t);
        }
        cout << "\n" << vptr->profile() << endl;// 36-42
    }
    vptr->reset(); //70
    cout << vptr->profile() << endl;
    delete vptr;
    
    return 0;
}