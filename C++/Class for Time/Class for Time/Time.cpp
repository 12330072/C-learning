//
//  Time.cpp
//  Class for Time
//
//  Created by 邱兆丰 on 16/3/4.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "Time.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Time::Time() {
    m = h = s = 0;
}

Time::Time(int a){
    h = a;
    m = 0;
    s = 0;
}

Time::Time(int a, int b){
    h = a;
    m = b;
    s = 0;
}

Time::Time(int a, int b, int c){
    h = a;
    m = b;
    s = c;
}
Time::Time(const Time &otherTime){
    h = otherTime.h;
    m = otherTime.m;
    s = otherTime.s;
}

void Time::setHour(int a) {
    h = a;
}

void Time::setMinute(int a) {
    m = a;
}

void Time::setSecond(int a) {
    s = a;
}

string Time::toString() {
    int _h = h;
    ostringstream Hour, Minute, Second, Day, ALL;
    if (h > 12) {
        _h = h % 12;
        Day << " PM";
    } else {
        Day << " AM";
    }
    if (_h < 10)
        Hour << '0' << _h;
    else
        Hour << _h;
    if (m < 10)
        Minute << '0' << m;
    else
        Minute << m;
    if (s < 10)
        Second << '0' << s;
    else
        Second << s;
    ALL << Hour.str() << ':' <<Minute.str() << ':' << Second.str() << Day.str();
    return ALL.str();
}

int Time::getSecond() {
    return s;
}

int Time::getHour() {
    return h;
}

int Time::getMinute() {
    return m;
}

bool Time::isValid() {
    bool check = 0;
    if (h < 24 && m < 60 && s < 60) {
        check = 1;
    }
    return check;
}

Time Time::after(int r) {
    int add;
    int _s = s;
    int _h = h;
    int _m = m;
    _s += r;
    if (_s >= 60) {
        add = _s / 60;
        _s %= 60;
        _m += add;
    }
    if (_m >= 60) {
        add = _m / 60;
        _m %= 60;
        _h += add;
    }
    if (_h >= 24) {
        _h %= 24;
    }
    Time after = Time(_h, _m, _s);
    return after;
}

Time::~Time() {
    cout << "Recycle time: " << this->toString() << endl;
}









