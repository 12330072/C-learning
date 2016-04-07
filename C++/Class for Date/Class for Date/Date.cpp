//
//  Date.cpp
//  Class for Date
//
//  Created by 邱兆丰 on 16/3/18.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "Date.h"

Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

void Date::setDay(int d) {
    day = d;
}

bool Date::isValid() {
    int maxDay = dayCount();
    return (year > 0 && day <= maxDay && day > 0 && month > 0 && month <= 12);
}

std::string Date::toString() {
    std::ostringstream outP;
    outP << '[' << year <<'-' << month << '-' << day << ']';
    return outP.str();
}

std::ostream& operator<<(std::ostream & os, const Date & _date) {
    os << '[' << _date.year <<'-' << _date.month << '-' << _date.day << ']' << std::endl;
    return os;
}

std::istream& operator>>(std::istream & is, Date &_date) {
    is >> _date.year >> _date.month >> _date.day;
    return is;
}


Date& Date::operator++() {
    addOneDay();
    return *this;
}

Date Date::operator++(int i) {
    Date before = *this;
    addOneDay();
    return before;
}

void Date::addOneDay() {
    day++;
    if (day > dayCount()) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

bool Date::isYunNian() {
    return((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int Date::dayCount() {
    int i;
    for (i = 1; i <= 7; i += 2) {
        if (month == i)
            return 31;
    }
    for (i = 8; i <= 12; i+= 2) {
        if (month == i)
            return 31;
    }
    if (month == 2) {
        if (isYunNian()) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return 30;
    }
}

bool Date::operator==(const Date &othD) {
    if (year == othD.year) {
        if (month == othD.month)
            if (day == othD.day)
                return true;
    }
    return false;
}

bool Date::operator!=(const Date &othD) {
    return (!(*this == othD));
}

bool Date::operator>(const Date &othD) {
    if (year > othD.year) {
        return true;
    }
    else if (year == othD.year) {
        if (month > othD.month) {
            return true;
        }
        else if (month == othD.month) {
            if (day > othD.day) {
                return true;
            }
        }
    }
    return false;
}

bool Date::operator<(const Date &othD) {
    if (year < othD.year) {
        return true;
    }
    else if (year == othD.year) {
        if (month < othD.month) {
            return true;
        }
        else if (month == othD.month) {
            if (day < othD.day) {
                return true;
            }
        }
    }
    return false;
}

Date Date::after(int d) {
    Date after = *this;
    while (d--) {
        after.addOneDay();
    }
    return after;
}












