//
//  main.c
//  求因子
//
//  Created by 邱兆丰 on 15/11/11.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include <stdio.h>

int main() {
    int	n, i;
    scanf("%d", &n);
    while (n != 1) {
        for (i = 2; i <= n; i++) {
        if (n % i == 0 ) {
            printf("%d ", i);
            n = n / i;
            break;
        }
    }}
    return 0;
}
