//
//  main.c
//  函数练习使用
//
//  Created by 邱兆丰 on 15/12/2.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include<stdio.h>

int gcd(int m, int n);
int fac(int p);

int main(void) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d %d\n", gcd(a, b), fac(c));
}

int gcd(int m, int n) {             //求最大公约数
    int c;
    c = m % n;
    while(c!=0)
    {
        m = n;
        n = c;
        c = m % n;
    }
    return n;
}

int gcd1(int a, int  b) {
    int c, r;
    int
}

int fac(int m) {                //求阶乘
    int i;
    int op = 1;
    for (i = 1; i <= m; i++) {
        op *= i;
    }
    return op;
}


