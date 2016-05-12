//
//  map.hpp
//  cpp Application Greedy Snake
//
//  Created by 邱兆丰 on 16/4/10.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef map_hpp
#define map_hpp

#include "snake.hpp"

class map {
public:
    map(const point& initialSize, const point& initialHead, const std::list<point>& initialFoods) : _size(initialSize), player(initialHead), _foods(initialFoods) {
        snakeStatus = 0;
        _map = new char*[_size.x];
        for (int i = 0; i < _size.x; i++) {
            _map[i] = new char[_size.y];
            memset(_map[i], EMPTY, _size.y);
        }
        changeMap();
    }
    void changeMap() {
        if (snakeStatus == -1) {
            return;
        }
        for (int i = 0; i < _size.x; i++) {
            memset(_map[i], EMPTY, _size.y);
        }
        std::list<point>::iterator itor;
        itor = _foods.begin();
        while (itor != _foods.end()) {
            _map[itor->x][itor->y] = FOOD;
            *itor++;
        }
        _map[player.getHead().x][player.getHead().y] = HEAD;
        for (int i = 0; i < player.getSnakeLength(); i++) {
            _map[player.getBody()[i].x][player.getBody()[i].y] = BODY;
        }
    }
    void print() {
        for (int i = 0; i < _size.x; i++) {
            for (int j = 0; j < _size.y; j++) {
                std::cout << _map[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    void move(direction d) {
        player.Smove(d);
        collision();
        if (snakeStatus == 1) {
            player.snakeGrowth();
            snakeStatus = 0;
        }
        changeMap();
    }
    bool isGameOver() {
        if (snakeStatus == -1)
            return 1;
        else
            return 0;
    }
    ~map() {
        for (int i = 0; i < _size.x; i++) {
            delete []_map[i];
        }
        delete []_map;
    }
    void collision() {
        for (int i = 0; i < player.getSnakeLength(); i++) {
            if (player.getHead().x == player.getBody()[i].x && player.getHead().y == player.getBody()[i].y) {
                snakeStatus = -1;
                return;
            }
        }
        if (player.getHead().x < 0 || player.getHead().x >= _size.x || player.getHead().y < 0 || player.getHead().y >= _size.y) {
            snakeStatus = -1;
            return;
        }
        else if (_map[player.getHead().x][player.getHead().y] == FOOD) {
            std::list<point>::iterator it = find( _foods.begin(), _foods.end(), player.getHead());
            _foods.erase(it);
            snakeStatus = 1;
            return;
        }
        snakeStatus = 0;
    }
private:
    int snakeStatus;
    char **_map;
    point _size;
    snake player;
    std::list<point> _foods;
};

#endif /* map_hpp */
