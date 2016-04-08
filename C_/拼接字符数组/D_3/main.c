//
//  main.c
//  D_3
//
//  Created by 邱兆丰 on 15/12/9.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <mm_malloc.h>
#include"join.h"
#define MAX 51
int main() {
    char a[MAX];
    char b[MAX];
    char* c = NULL;
    scanf("%s", a);
    scanf("%s", b);
    c = join(a, strlen(a), b, strlen(b));
    printf("%s\n", c);
    printf("%d\n", malloc_usable_size(c));
    free(c);
    return 0;
}