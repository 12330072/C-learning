#include<string>
#include<iostream>
#include<sstream>
#include"Datetime.h"

using namespace std;

Datetime::Datetime() :Date(), Time() {
}

Datetime::Datetime(int y, int mo, int d, int h, int m, int s) :Date(y, mo, d), Time(h, m, s) {
}

Datetime::~Datetime() {
    ostringstream out;
    out << "Destructor: ";
    out << Date::toString() << ' ' << Time::toString() << endl;
    cout << out.str();
}

string Datetime::toString() {
    ostringstream out;
    out << Date::toString() << ' ' << Time::toString();
    return out.str();
}

bool Datetime::operator>(const Datetime &othDT) const {
    if (getYear() > othDT.getYear())
        return true;
    if (getYear() < othDT.getYear())
        return false;
    if (getMonth() > othDT.getMonth())
        return true;
    if (getMonth() < othDT.getMonth())
        return false;
    if (getDay() > othDT.getDay())
        return true;
    if (getDay() < othDT.getDay())
        return false;
    if (getHour() > othDT.getHour())
        return true;
    if (getHour() < othDT.getHour())
        return false;
    if (getMinute() > othDT.getMinute())
        return true;
    if (getMinute() < othDT.getMinute())
        return false;
    return (getSecond() > othDT.getSecond());
}

bool Datetime::operator<(const Datetime &othDT) const {
    if (getYear() > othDT.getYear())
        return false;
    if (getYear() < othDT.getYear())
        return true;
    if (getMonth() > othDT.getMonth())
        return false;
    if (getMonth() < othDT.getMonth())
        return true;
    if (getDay() > othDT.getDay())
        return false;
    if (getDay() < othDT.getDay())
        return true;
    if (getHour() > othDT.getHour())
        return false;
    if (getHour() < othDT.getHour())
        return true;
    if (getMinute() > othDT.getMinute())
        return false;
    if (getMinute() < othDT.getMinute())
        return true;
    return (getSecond() < othDT.getSecond());
}

bool Datetime::operator==(const Datetime &othDT) const {
    return (getYear() == othDT.getYear() && getMonth() == othDT.getMonth() && getDay() == othDT.getDay() && getHour() == othDT.getHour() && getMinute() == othDT.getMinute()&& getSecond() == othDT.getSecond());
}

bool Datetime::operator!=(const Datetime &othDT) const {
    return !(othDT == *this);
}

Datetime& Datetime::operator=(const Datetime &othDT) {
    Date::setYear(othDT.getYear());
    Date::setMonth(othDT.getMonth());
    Date::setDay(othDT.getDay());
    Time::setHour(othDT.getHour());
    Time::setMinute(othDT.getMinute());
    Time::setSecond(othDT.getSecond());
    return *this;
}

Datetime& Datetime::operator++() {
    Time::increment();
    if (getHour() == 0 && getMinute() == 0 && getSecond() == 0) {
        Date::increment();
    }
    return *this;
}

Datetime Datetime::operator++(int i) {
    Datetime tem = (*this);
    ++(*this);
    return tem;
}

Datetime Datetime::after(int seconds) {
    Datetime newDT = (*this);
    while (seconds--) {
        ++newDT;
    }
    return newDT;
}

















