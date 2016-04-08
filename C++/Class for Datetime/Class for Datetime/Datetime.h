//
//  Datetime.hpp
//  Class for Datetime
//
//  Created by 邱兆丰 on 16/3/25.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef Datetime_hpp
#define Datetime_hpp

#include <stdio.h>
#include "Time.h"
#include "Date.h"

class Datetime: public Date, public Time {
  public:
    Datetime();
    Datetime(int y, int mo, int d, int h, int m, int s);
    ~Datetime();
    string toString();
    Datetime after(int seconds);
    bool operator>(const Datetime &othDT) const;
    bool operator<(const Datetime &othDT) const;
    bool operator==(const Datetime &othDT) const;
    Datetime& operator=(const Datetime &othDT);
    Datetime& operator++();
    Datetime operator++(int i);
    bool operator!=(const Datetime &othDT) const;
};




#endif /* Datetime_hpp */
