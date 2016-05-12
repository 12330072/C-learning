//
//  header.h
//  games
//
//  Created by 邱兆丰 on 16/4/22.
//  Copyright © 2016年 菇生. All rights reserved.
//

#ifndef header_h
#define header_h
#include <iostream>

using namespace std;

class gameobject {
  public:
    gameobject(int _x, int _y): x(_x), y(_y) {
        HP = 10;
    }
    virtual ~gameobject() {}
    virtual void select() = 0;
    virtual void move() = 0;
    virtual void attack(gameobject* p) = 0;
    virtual void repair(gameobject* p) = 0;
    int get_hp() {
        return HP;
    }
    int x;
    int y;
    int HP;
};

class worker: public gameobject {
  public:
    worker(int _x = 0, int _y = 0): gameobject(_x, _y) {}
    virtual void move() {
        x += 1;
        y += 1;
        cout << "Worker moves to (" << x << ", " <<  y << ')' << endl;
    }
    virtual void select() {
        cout << "Scv good to go, sir!" << endl;
    }
    virtual void repair(gameobject* p) {
        p->HP = 10;
    }
    void build(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n - i; j++) {
                cout << ' ';
            }
            for (int k = 0; k < 2 * i + 1; k++) {
                cout << '*';
            }
            cout << endl;
        }
    }
    void attack(gameobject* p) {}
    ~worker() {}
};


class zealot: public gameobject {
  public:
    zealot(int _x = 0, int _y = 0): gameobject(_x, _y) {}
    virtual void select() {
        cout << "My life for Aiur!" << endl;
    }
    virtual void move() {
        x += 2;
        y += 2;
        cout << "Zealot moves to (" << x << ", " <<  y << ')' << endl;
    }
    virtual void attack(gameobject* p) {
        if (p->HP > 0) {
            p->HP--;
        }
    }
    void repair(gameobject* p) {}
    ~zealot() {}
};

class tower: public gameobject {
  public:
    tower(int _x = 0, int _y = 0): gameobject(_x, _y) {}
    virtual void select() {
        cout << "~" << endl;
    }
    virtual void move() {
        cout << "Tower cannot move." << endl;
    }
    virtual void attack(gameobject* p) {
        if (p->HP > 0) {
            p->HP--;
        }
    }
    void repair(gameobject* p) {}
    ~tower() {}
};


#endif /* header_h */
