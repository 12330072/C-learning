//
//  main.c
//  别人的蛇形
//
//  Created by 邱兆丰 on 15/11/14.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int a[10][10];

int main()
{
    int top, bottom, left, right, n;
    int num = 1;
    int i, j;
    scanf("%d", &n);
    top = 0;
    bottom = n-1;
    left = 0;
    right = n-1;
    a[0][n-1] = num;
    i = 0;
    j = n-1;
    while (num < n*n)
    {
        while (i < bottom)
        {
            a[++i][j] = ++num;
        }
        right--;
        
        while (j > left)
        {
            a[i][--j] = ++num;
        }
        bottom--;
        
        while (i > top)
        {
            a[--i][j] = ++num;
        }
        left++;
        
        while (j < right)
        {
            a[i][++j] = ++num;
        }
        top++;
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

