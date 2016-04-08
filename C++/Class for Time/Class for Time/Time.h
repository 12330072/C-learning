//
//  Time.h
//  Class for Time
//
//  Created by 邱兆丰 on 16/3/4.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;
class Time {
private:
    int h, m, s;
public:
    Time();
    ~Time();
    Time(int);
    Time(int, int);
    Time(int, int, int);
    Time(const Time &otherTime);
    int getSecond();
    int getHour();
    int getMinute();
    void setHour(int);
    void setMinute(int);
    void setSecond(int);
    string toString();
    bool isValid();
    Time after(int);
};

#endif
