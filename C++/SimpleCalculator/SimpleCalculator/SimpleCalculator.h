//
//  SimpleCalculator.h
//  SimpleCalculator
//
//  Created by 邱兆丰 on 16/2/29.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

// Lab Exercise 1: SimpleCalculator.h

// class SimpleCalculator definition
class SimpleCalculator {
public:
    SimpleCalculator();
    void add(double, double);
    void subtract(double, double);
    void multiply(double, double);
    void divide(double, double);
    double getAnswer() const;
private:
    double answer;
};  // end class SimpleCalculator
