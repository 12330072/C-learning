//
//  main.c
//  十进制转十六进制
//
//  Created by 邱兆丰 on 15/11/30.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include <stdio.h>

int main() {
    int num;
    int i = 0;
    int a[100];
    int b;
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    
    scanf("%d", &num);
    if (num < 0) {
        num = - num;
        printf("-");
    }
    while (num) {
        a[i++] = num % 16;
        num /= 16;
    }
    for (i = i - 1; i >= 0; i--) {
        b = a[i];
        printf("%c", hex[b]);
    }
    printf("\n");
    return 0;
}
