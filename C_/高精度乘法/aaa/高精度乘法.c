//
//  main.c
//  aaa
//
//  Created by 邱兆丰 on 15/10/30.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include <stdio.h>
#include<string.h>

int main() {
    char N[1000], M[1000], C[2000];
    int i, j;
    int a[1000], b[1000], c[2000] = {0};
    scanf("%s", N);
    scanf("%s", M);
    int n = strlen(N);
    int m = strlen(M);
    for (i = 0; i < m; i++){
        b[i] = M[m - i - 1] - '0';
    }
    for (j = 0; j < n; j++){
        a[j] = N[n - j - 1] - '0';
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i+j] += (a[i] * b[j]) ;
        }
    }
    for (i = 0; i < n + m; i++) {
        if (c[i] >= 10) {
            c[i + 1] = c[i + 1] + c[i] / 10;
            c[i] = c[i] % 10;
        }
    }
    i = m + n - 1;
    while (c[i]==0) {
        i--;
    }
    for (j = i; j >= 0; j--) {
        printf("%d", c[j]);
    }
    return 0;

}