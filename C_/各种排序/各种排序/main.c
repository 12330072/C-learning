//
//  main.c
//  各种排序
//
//  Created by 邱兆丰 on 15/12/19.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include <stdio.h>

void Bubble_sort(int a[], int n) {  //冒泡排序，从小到大
    int i, j;
    int change;
    for (i = 0; i < n - 1; i++)
        for (j = 1; j < n - i; j++) {
            if (a[j] < a[j - 1]) {
                change = a[j];
                a[j] = a[j - 1];
                a[j - 1] = change;
            }
        }
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Selection_sort(int a[], int n) {
    int i, j;
    int change;
    int min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[min] > a[j]) {
                min=j;
            }
        }
        change = a[i];
        a[i] = a[min];
        a[min] = change;
    }
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Bucket_sort(int a[], int n) {
    int bucket[1001];
    int i, j;
    int t;
    for (i = 0; i < 1001; i++)
        bucket[i] = 0;
    for (i = 0; i < n; i++) {
        t = a[i];
        bucket[t]++;
    }
    for (i = 0; i < 1001; i++) {
        for (j = 1; j <= bucket[i]; j++) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int a[100];
    int n;
    int enter;
    int i;
    printf("=======================sort====================\n");
    printf("1.Bubble_sort  2.Selection_sort  3. Bucket_sort\n");
    scanf("%d", &enter);
    if (enter == 1) {
        printf("Bubble_sort\n");
        printf("Please enter 'n' and 'array'\n");
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        Bubble_sort(a, n);
    }
    if (enter == 2) {
        printf("Selection_sort\n");
        printf("Please enter 'n' and 'array'\n");
        scanf("%d", &n);
        for (i = 0;
             i < n; i++) {
            scanf("%d", &a[i]);
        }
        Selection_sort(a, n);
    }
    if (enter == 3) {
        printf("Bucket_sort\n");
        printf("Please enter 'n' and 'array'\n");
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        Bucket_sort(a, n);
    }
}

