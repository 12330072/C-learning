//
//  main.c
//  snake
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

void snakeMove(int a, int b);
void put_money();
void output();
void gameover();
void collision();

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
int snakeLife = 1;

int main() {
    while (snakeLife) {
        output();
        char ch;
        ch = getchar();
        switch (ch) {
            case 'a':
                snakeMove(0, -1);
                break;
            case 'd':
                snakeMove(0, 1);
                break;
            case 'w':
                snakeMove(-1, 0);
                break;
            case 's':
                snakeMove(1, 0);
                break;
                
            default:
                break;
        }
        collision();
        system("clear");
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

void snakeMove(int a, int b) {
    int i, j;
    for (i = 1; i < 11; i++) {
        for (j = 1; j < 11; j++) {
            map[i][j] = ' ';
        }
    }
    for (i = 0; i < snakeLength; i++) {
        snakeX[i] = snakeX[i + 1];
        snakeY[i] = snakeY[i + 1];
        map[snakeX[i]][snakeY[i]] = 'X';
    }
    snakeX[snakeLength] += a;
    snakeY[snakeLength] += b;
    map[snakeX[snakeLength]][snakeY[snakeLength]] = 'H';
}

void collision() {
    if (snakeX[snakeLength] == 11 || snakeX[snakeLength] == 0) {
        snakeLife = 0;
        printf("Gameover\n");
    }
    if (snakeY[snakeLength] == 11 || snakeY[snakeLength] == 0) {
        snakeLife = 0;
        printf("Gameover\n");
    }
}
