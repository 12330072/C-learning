//
//  main.c
//  tou
//
//  Created by 邱兆丰 on 15/11/4.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//
int encrypt_1(int data);
int encrypt_2(int data);
int getMode(int data);

int getMode(int data) {
    return data % 10;
}

int encrypt_1(int data) {
    return data % 20;
}

int encrypt_2(int data) {
    return data % 20 + 20;
}
#include<stdio.h>
int main() {
    int n, a[100], b[100];
    int i, k;
    int sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        k = getMode(a[i]);
        if (k == 0) {
            b[i] = a[i];
        }
        if (k == 1) {
            b[i] = encrypt_1(a[i]);
        }
        if (k == 2) {
            b[i] = encrypt_2(a[i]);
        }
        if (k == 3) {
            b[i] = encrypt_1(a[i]) + encrypt_2(a[i]);
        }
        if (k == 4) {
            b[i] = 2 * encrypt_1(a[i]);
        }
        if (k == 5) {
            b[i] = 2 * encrypt_2(a[i]);
        }
        if (k >= 6) {
            b[i] = 2 * a[i];
        }
        sum += b[i];
    }
    printf("%d\n", sum);
    return 0;
}
