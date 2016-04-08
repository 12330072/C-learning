//
//  main.cpp
//  Class for Datetime
//
//  Created by 邱兆丰 on 16/3/25.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include <iostream>
#include "Datetime.h"

using namespace std;

int main() {
    Datetime datetime1(2015, 3, 21, 23, 59, 58);
    
    // test for overloaded operator ++.
    Datetime datetime2 = (datetime1++);
    cout << datetime2.toString() << endl;
    cout << datetime1.toString() << endl;
    datetime2 = ++datetime1;
    cout << datetime2.toString() << endl;
    cout << datetime1.toString() << endl;
    
    Datetime datetime3(datetime2);
    if (datetime3 == datetime1) cout << "They are the same!" << endl;
    else cout << "They are different!" << endl;
    
    int year, month, day, hour, minute, second;
    cin >> year >> month >> day >> hour >> minute >> second;
    datetime3.setYear(year);
    datetime3.setMonth(month);
    datetime3.setDay(day);
    datetime3.setHour(hour);
    datetime3.setMinute(minute);
    datetime3.setSecond(minute);
    
    if (datetime3 != datetime1) cout << "They are different!\n";
    else cout << "They are not different!\n";
    if (datetime3 > datetime1) cout << "First datetime"
        << "is latter than the second one.\n";
    if (datetime3 < datetime1) cout << "First datetime"
        << "is earlier than the second one.\n";
    
    int seconds = 10;
    cin >> seconds;
    cout << datetime3.after(seconds).toString() << endl;
}
