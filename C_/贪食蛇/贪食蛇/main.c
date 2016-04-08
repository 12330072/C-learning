//
//  main.c
//  贪食蛇
//
//  Created by 邱兆丰 on 15/12/26.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define SNAKE_FOOD '$'
#define BLANK_CELL ' '
#define WALL_CELL '*'

enum Direction {up, down, left, right};

void snakeMove();
void put_money(void);
void output(void);
void gameover(void);

char map[12][12]=
{"************",
 "*XXXXH     *",
 "*          *",
 "*          *",
 "*          *",
 "*          *",
 "*          *",
 "*          *",
 "*          *",
 "*          *",
 "*          *",
 "************"};

int snakeX[SNAKE_MAX_LENGTH] = {1, 1, 1, 1, 1};
int snakeY[SNAKE_MAX_LENGTH] = {1, 2, 3, 4, 5};
int snakeLength = 4;
int game = 1;
int direction = right;

void snakeMove(int a, int b) {
    int i, j;
    for (i = 1; i < 11; i++) {
        for (j = 1; j < 11; j ++) {
            map[i][j] = ' ';
        }
    }
    if (getch() == 'a' && direction != right) {
        for (i = 0; i < snakeLength - 1; i++) {
            snakeX[i] = snakeX[i + 1];
            snakeY[i] = snakeY[i + 1];
        }
        snakeX[snakeLength]--;
        map[snakeX[snakeLength]][snakeY[snakeLength]] = 'H';
    }
    if (getch() == 'w' && direction != down) {
        for (i = 0; i < snakeLength - 1; i++) {
            snakeX[i] = snakeX[i + 1];
            snakeY[i] = snakeY[i + 1];
        }
        snakeY[snakeLength]--;
        map[snakeX[snakeLength]][snakeY[snakeLength]] = 'H';
    }
    if (getch() == 'd' && direction != left) {
        for (i = 0; i < snakeLength - 1; i++) {
            snakeX[i] = snakeX[i + 1];
            snakeY[i] = snakeY[i + 1];
        }
        snakeX[snakeLength]++;
        map[snakeY[snakeLength]][snakeY[snakeLength]] = 'H';
    }
    if (getch() == 's' && direction != up) {
        for (i = 0; i < snakeLength - 1; i++) {
            snakeX[i] = snakeX[i + 1];
            snakeY[i] = snakeY[i + 1];
        }
        snakeY[snakeLength]++;
        map[snakeX[snakeLength]][snakeY[snakeLength]] = 'H';
    }
    for (i = 0; i < snakeLength - 1; i++) {
        map[snakeX[i]][snakeY[i]] = 'X';
    }
}

void output() {
    int i, j;
    for (i = 0; i < 12 ;i++) {
        for (j = 0; j < 12; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    while (game) {
        snakeMove();
        output();
    }
}
