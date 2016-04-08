//
//  DFS.h
//  完全二叉树
//
//  Created by 邱兆丰 on 15/12/7.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//
#ifndef __DEF_H
#define __DEF_H
void DFS(int arr[], int leng, int pos, int X) {
    printf("%d", arr[pos]);
    if (arr[pos] == X) {
        printf("\n");
        exit(0);
    }
    printf(" ");
    if (pos * 2 + 1 < leng) {
        DFS(arr, leng, pos * 2 + 1, X);
    }
    if (pos * 2 + 2 < leng) {
        DFS(arr, leng, pos * 2 + 2, X);
    }
}

#endif

