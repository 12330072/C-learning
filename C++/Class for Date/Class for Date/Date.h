#ifndef Date_hpp
#define Date_hpp

#include <iostream>
#include <sstream>

class Date {
  public:
    Date(int, int, int);
    ~Date() {
        std::cout << "Destructor: [" << year << '-' <<
        month << '-' << day << ']' << std::endl;
    }
    int& operator[](unsigned i) {
        if (i == 0)
            return year;
        if (i == 1)
            return month;
        else
            return day;
    }
    const int & operator[](unsigned i) const {
        if (i == 0)
            return year;
        if (i == 1)
            return month;
        else
            return day;
    }
    std::string toString();
    friend std::ostream& operator<<(std::ostream & os, const Date & _date);
    friend std::istream& operator>>(std::istream & os, Date &_date);
    Date& operator++();
    Date operator++(int);
    Date after(int y);
    void addOneDay();
    void setDay(int d);
    bool isYunNian();
    bool isValid();
    int dayCount();
    bool operator==(const Date &othD);
    bool operator!=(const Date &othD);
    bool operator>(const Date &othD);
    bool operator<(const Date &othD);
 private:
    int year;
    int month;
    int day;
};

#endif /* Date_hpp */
