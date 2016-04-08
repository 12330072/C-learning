//
//  main.c
//  跳跳（递归运用）
//
//  Created by 邱兆丰 on 15/12/2.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include <stdio.h>
void jump(int a);

int main() {
    int J[100];
    int i, k;
    int n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", & J[i]);
    }
    return 0;
}

void jump(int a) {
    
    jump(a);
    
}