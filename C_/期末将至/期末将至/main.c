//
//  main.c
//  期末将至
//
//  Created by 邱兆丰 on 16/1/4.
//  Copyright (c) 2016年 邱兆丰. All rights reserved.
//

#include <stdio.h>

void fuck(int n, int m);

int main() {
    int N, M;
    int w[10], s[10], t[10], d[10];
    int i;
    int Tbu;
    double sum[10][1000];
    scanf("%d%d", &N, &M);
    for (i = 0; i < N; i++) {
        scanf("%d%d%d%d", &s[i], &w[i], &t[i], &d[i]);
        if (s[i] < 60) {
            Tbu = (60 - s[i]) / d[i] * t[i];
            M -= Tbu;
            s[i] = 60;
        }
    }
    if (M < 0) {
        printf("0\n");
        return 0;
    }
    fuck(N, M);
}

void fuck(int n; int m, double sum[][]x) {
    int i;
    fuck(sum);
    for (i = 0; i * k < M; <#increment#>) {
        <#statements#>
    }
}
