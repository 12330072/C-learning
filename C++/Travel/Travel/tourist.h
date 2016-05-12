//
//  Header.h
//  Travel
//
//  Created by 邱兆丰 on 16/4/8.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef Header_h
#define Header_h

class Tourist {
  public:
    explicit Tourist(Vehicle* strategy_) {
        strategy = strategy_;
    }
    void setStrategy(Vehicle* strategy_) {
        strategy = strategy_;
    }
    void travel(const City& src, const City& dest) {
        strategy->doTravel(src, dest);
    }
  private:
    Vehicle* strategy;
};



#endif /* Header_h */
