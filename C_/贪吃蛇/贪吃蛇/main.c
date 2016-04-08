//
//  main.c
//  贪吃蛇
//
//  Created by 邱兆丰 on 15/12/15.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define SNAKE_FOOD '$'
#define BLANK_CELL ' '
#define WALL_CELL '*'

void snakeMove(int, int);
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

int snakeX[SNAKE_MAX_LENGTH] = {1, 2, 3, 4, 5};
int snakeY[SNAKE_MAX_LENGTH] = {1, 1, 1, 1, 1};
int snakeLength = 5;*/
#include <stdlib.h>
#include "conio.h"
#include <time.h>
#include "windows.h"

enum block{
    BLANK = 0, FOOD, SNAKE, HEAD
};

int snake[800][2] = {0};
int len = 0;
int food[2] = {0};
enum block map[20][80] = {HEAD};
int gameOver = 0;

void CreatFood( void )
{
    int flag = 1;
    int i;
    while( flag == 1 )
    {
        flag = 0;
        food[0] = rand()%80;
        food[1] = rand()%20;
        printf( "%d,%d\n", food[0], food[1] );
        for ( i = 0; i < len; ++i )
        {
            if ( snake[i][0] == food[0] && snake[i][1] == food[1] )
            {
                flag = 1;
            }
        }
    }
}

void Init( void )
{
    int i;
    //初始化蛇
    len = 3;
    for ( i = 0; i < len; ++i )
    {
        snake[i][0] = len-i;
    }
    //初始化食物
    CreatFood();
}

void Draw( void )
{
    int i,j;
    
    for ( i = 0; i < 20; ++i )
    {
        for ( j = 0; j < 80; ++j )
        {
            map[i][j] = BLANK;
        }
    }
    //把蛇画到map里
    map[snake[0][1]][snake[0][0]] = HEAD;
    for ( i = 1; i < len; ++i )
    {
        map[snake[i][1]][snake[i][0]] = SNAKE;
    }
    //把食物画到map里
    map[food[1]][food[0]] = FOOD;
    system( "cls" );
    //    printf( "%d,%d\n", food[0], food[1] );
    for ( i = 0; i < 20; ++i )
    {
        for ( j = 0; j < 80; ++j )
        {
            switch ( map[i][j] )
            {
                case BLANK:
                    putchar(' ');
                    break;
                case FOOD:
                    putchar('$');
                    break;
                case SNAKE:
                    putchar('*');
                    break;
                case HEAD:
                    putchar('@');
                    break;
                default:
                    break;
            }
        }
    }
}

int Eat( void )
{
    if ( snake[0][0] == food[0] && snake[0][1] == food[1] )
    {
        return 1;
    }
    return 0;
}

int Die( void )
{
    int i;
    //撞边界死
    if ( snake[0][0] < 0 || snake[0][0] > 80 )
    {
        return 1;
    }
    if ( snake[0][1] < 0 || snake[0][1] > 20 )
    {
        return 1;
    }
    //撞自己死
    for ( i = 1; i < len; ++i )
    {
        if ( snake[i][0] == snake[0][0] && snake[i][1] == snake[0][1] )
        {
            return 1;
        }
    }
    return 0;
}

void Move( char key )
{
    int x, y;
    int pos = 0;
    int i;
    int d[4][2] = {
        {0,-1},
        {-1,0},
        {0,1},
        {1,0},
    };
    switch ( key )
    {
        case 'w':
            pos = 0;
            break;
        case 'a':
            pos = 1;
            break;
        case 's':
            pos = 2;
            break;
        case 'd':
            pos = 3;
            break;
        default:
            break;
    }
    x = snake[len-1][0];
    y = snake[len-1][1];
    for ( i = len-1; i > 0; --i )
    {
        snake[i][0] = snake[i-1][0];
        snake[i][1] = snake[i-1][1];
    }
    snake[0][0] += d[pos][0];
    snake[0][1] += d[pos][1];
    if ( Eat() )
    {
        snake[len][0] = x;
        snake[len][1] = y;
        ++len;
        CreatFood();
    }
    else if ( Die() )
    {
        gameOver = 1;
    }
}

char Judge( char key, char lastKey )
{
    if ( key == 'd' && lastKey == 'a' )
    {
        return lastKey;
    }
    if ( key == 'a' && lastKey == 'd' )
    {
        return lastKey;
    }
    if ( key == 'w' && lastKey == 's' )
    {
        return lastKey;
    }
    if ( key == 's' && lastKey == 'w' )
    {
        return lastKey;
    }
    return key;
}

int main( int argc, char * argv[] )
{
    char lastKey = 'd';
    char key = lastKey;
    int lastTime = GetTickCount();
    
    srand( (unsigned int)GetTickCount() );
    Init();
    Draw();
    while ( 1 )
    {
        while ( !kbhit() )
        {
            while ( GetTickCount()-lastTime < 500 )
            {
                Sleep(1);
            }
            lastTime = GetTickCount();
            Move( key );
            if ( !gameOver )
            {
                Draw();
            }
        }
        key = getch();
        key = Judge( key, lastKey );
        lastKey = key;
        Move( key );
        if ( !gameOver )
        {
            Draw();
        }
        else
        {
            puts( "You Lose!");
            break;
        }
    }
    return 0;
}
