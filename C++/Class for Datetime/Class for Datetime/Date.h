//
//  Date.hpp
//  Class for Datetime
//
//  Created by 邱兆丰 on 16/3/25.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef DATE_H
#define DATE_H
#include<string>
#include<iostream>
using namespace std;

class Date;
ostream& operator<<(ostream& out, const Date& date);
istream& operator>>(istream& in, Date& date);

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int year = 0, int month = 0, int day = 0);
    Date(const Date& date);
    ~Date();
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    
    string toString() const;
    bool isValid();
    int daysOfMonth();
    void increment();
    Date after(int days);
    
    bool operator <(const Date& date);
    bool operator >(const Date& date);
    Date& operator =(const Date& date);
    bool operator ==(const Date& date);
    bool operator !=(const Date& date);
    
    int& operator[](int index);
    
    Date& operator ++();
    Date operator ++(int temp);
    
    friend ostream& operator<<(ostream& out, const Date & date);
    friend istream& operator>>(istream& in, Date & date);
};
#endif
