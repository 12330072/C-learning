//
//  snake.hpp
//  cpp Application Greedy Snake
//
//  Created by 邱兆丰 on 16/4/10.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef snake_hpp
#define snake_hpp

#include <iostream>
#include "global.hpp"
#include <algorithm>
#include <list>
#include <cstring>

class snake {
public:
    snake (point H) {
        _head = H;
        _tail = H;
        for (int i = 0; i < 100; i++) {
            _body[i].x = -1;
            _body[i].y = -1;
        }
        snakeLength = 0;
    }
    point &getHead() {
        return _head;
    }
    point* getBody() {
        return _body;
    }
    point &getTail() {
        return _tail;
    }
    void snakeGrowth() {
        _body[snakeLength] = _tail;
        snakeLength++;
    }
    void Smove(direction d) {
        if (snakeLength != 0) {
            _tail = _body[snakeLength - 1];
        } else {
            _tail = getHead();
        }
        for (int i = snakeLength - 1; i >0; i--) {
            _body[i] = _body[i - 1];
        }
        _body[0] = _head;
        _head.move(d);
    }
    int getSnakeLength() {
        return snakeLength;
    }
private:
    point _head;
    point _tail;
    point _body[100];
    int snakeLength;
};


#endif /* snake_hpp */
