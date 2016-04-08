//
//  Date.cpp
//  Class for Datetime
//
//  Created by 邱兆丰 on 16/3/25.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include<string>
#include<iostream>
#include<sstream>
#include"Date.h"
using namespace std;

Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

Date::Date(const Date& date) {
    *this = date;
}

Date::~Date() {}

void Date::setYear(int year) {
    this->year = year;
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setDay(int day) {
    this->day = day;
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

string intTranStr1(int integer) {
    stringstream ss;
    ss << integer;
    return ss.str();
}

void Date::increment() {
    ++(*this);
}

int Date::daysOfMonth() {
    if ((month%2 == 1 && month < 8) || (month%2 == 0 && month >= 8)) return 31;
    if (month  == 4 || month == 6 || month == 9 || month == 11) return 30;
    if ((year%4 == 0 && year%100 != 0) || year%400 == 0) return 29;
    return 28;
}

string Date::toString() const {
    return ("[" + intTranStr1(year) + "-" + intTranStr1(month) +\
            "-" + intTranStr1(day) + "]");
}

bool Date::isValid() {
    if (year <= 0) return false;
    if (month <= 0 || month > 12) return false;
    if (day <= 0 || day > 31) return false;
    return (day <= daysOfMonth());
}

Date Date::after(int days) {
    Date temp = Date(*this);
    while (days--) {
        ++temp;
    }
    return temp;
}

bool Date::operator <(const Date& date) {
    if (year < date.getYear()) return true;
    if (year > date.getYear()) return false;
    if (month < date.getMonth()) return true;
    if (month > date.getMonth()) return false;
    return (day < date.getDay());
}

bool Date::operator >(const Date& date) {
    return (*this != date) && !(*this < date);
}

Date& Date::operator =(const Date& date) {
    year = date.getYear();
    month = date.getMonth();
    day = date.getDay();
    return *this;
}

bool Date::operator ==(const Date& date) {
    return (year == date.getYear() &&\
            month == date.getMonth() && day == date.getDay());
}

bool Date::operator !=(const Date& date) {
    return !(*this == date);
}

int& Date::operator[](int index) {
    if (index == 0) return year;
    if (index == 1) return month;
    else return day;
}

Date& Date::operator ++() {
    day++;
    if (day > daysOfMonth()) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date Date::operator ++(int temp) {
    Date tmp = *this;
    ++(*this);
    return tmp;
}

ostream& operator<<(ostream& out, const Date& date) {
    out << date.toString() << endl;
    return out;
}

istream& operator>>(istream& in, Date& date) {
    in >> date.year >> date.month >> date.day;
    return in;
}