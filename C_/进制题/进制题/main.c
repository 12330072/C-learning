//
//  main.c
//  进制题
//
//  Created by 邱兆丰 on 15/12/18.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include <stdio.h>

int main() {
    int n, x;
    int i, j;
    int num;
    int sum;
    int maxsum = 0;
    scanf("%d%d",&n, &x);
    for (i = 2; i < n; i++) {
        j = n;
        sum = 0;
        while (j) {              //进制
            num = j % i;
            j /= i;
            if (num == x) {
                sum++;
            }
        }
        if (sum >= maxsum) {
            maxsum = sum;
        }
    }
    printf("%d\n", maxsum);
}
