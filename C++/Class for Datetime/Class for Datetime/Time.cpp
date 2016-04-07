#include "Time.h"
#include <sstream>
#include <iostream>
using namespace std;

Time::Time(int hour, int minute, int second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

Time::Time(const Time& time) {
    this->hour = time.getHour();
    this->minute = time.getMinute();
    this->second = time.getSecond();
}

Time::~Time() {}

void Time::setHour(int hour) {
    this->hour = hour;
}

void Time::setMinute(int minute) {
    this->minute = minute;
}

void Time::setSecond(int second) {
    this->second = second;
}

int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

int Time::getSecond() const {
    return second;
}

bool Time::isValid() const {
    if (hour < 0 || hour >= 24) return false;
    if (minute < 0 || minute >= 60) return false;
    if (second < 0 || second >= 60) return false;
    return true;
}

// auxiliary function that transfers the integer to string..
string intTranStr(int integer) {
    stringstream ss;
    ss << integer;
    return ss.str();
}

string Time::toString() const {
    string result = "";
    if (hour%12 < 10) result += "0";
    result += (intTranStr(hour%12) + ":");
    if (minute < 10) result += "0";
    result += (intTranStr(minute) + ":");
    if (second < 10) result += "0";
    result += intTranStr(second);
    if (hour >= 12) result += " PM";
    else result += " AM";
    return result;
}

Time Time::after(int seconds) {
    Time temp_time = Time(*this);
    while (seconds--) {
        temp_time.increment();
    }
    return temp_time;
}

void Time::increment() {
    second++;
    if (second >= 60) {
        second = 0;
        minute++;
        if (minute >= 60) {
            minute = 0;
            hour++;
            if (hour >= 24) hour = 0;
        }
    }
}