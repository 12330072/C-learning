//
//  main.cpp
//  Multiple exceptions(for hw)
//
//  Created by 邱兆丰 on 16/4/29.
//  Copyright © 2016年 菇生. All rights reserved.
//

#include <iostream>
#include "multi_throw.h"
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    int input;
    while (cin >> input) {
        try {
            multi_throw(input);
        } catch(std::out_of_range) {
            cout << "Exception: too big" << endl;
            cout << "Exception type: class out_of_range" << endl;
        } catch(int i) {
            cout << "Exception: " << i << endl;
            cout << "Exception type: int" << endl;
        } catch(std::runtime_error) {
            cout << "Exception: run error" << endl;
            cout << "Exception type: class runtime_error" << endl;
        } catch(std::logic_error) {
            cout << "Exception: non-positive" << endl;
            cout << "Exception type: class logic_error" << endl;
        }
    }
}
