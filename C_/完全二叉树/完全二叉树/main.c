//
//  main.c
//  完全二叉树
//
//  Created by 邱兆丰 on 15/12/7.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include"DFS.h"
#define MAX 50

int main() {
    int leng = 0;
    int arr[MAX] = {0};
    int i;
    int X = 0;
    scanf("%d", &leng);
    for (i = 0; i < leng; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &X);
    DFS(arr, leng, 0, X);
    return 0;
}