//
//  main.c
//  蛇形方针
//
//  Created by 邱兆丰 on 15/11/14.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include <stdio.h>

int main() {
    int top, bottom, right, left;
    int n;
    int num = 1;
    int i, j;
    int a[100][100];
    scanf("%d", &n);
    top = 0;
    bottom = n - 1;
    right = n - 1;
    left = 0;
    i = 0;
    j = n - 1;
    a[i][j] = num;
    while (num < n * n) {
        while (i < bottom) {
            a[++i][j] = ++num;
        }
        right--;
        while (j > left) {
            a[i][--j] = ++num;
        }
        bottom--;
        while (i > top) {
            a[--i][j] = ++num;
        }
        left++;
        while (j < right) {
            a[i][++j] = ++num;
        }
        top++;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d", a[i][n - 1]);
        printf("\n");
    }
    for (j = 0; j < n - 1; j++) {
        printf("%d ", a[n - 1][j]);
    }
    printf("%d", a[n - 1][n - 1]);
    return 0;
}
