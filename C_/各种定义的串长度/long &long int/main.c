//
//  main.c
//  long &long int
//
//  Created by 邱兆丰 on 15/11/21.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
int main() {
    printf("size of char is %d\n", CHAR_BIT);
    printf("char max is %d\n", CHAR_MAX);
    printf("char min is %d\n", CHAR_MIN);
    printf("int min is %d\n", INT_MIN);
    printf("int max is %d\n", INT_MAX);
    printf("long min is %ld\n", LONG_MIN);
    printf("long max is %ld\n", LONG_MAX);
    printf("short min is %d\n", SHRT_MIN);
    printf("short max is %d\n", SHRT_MAX);
    printf("unsigned char max is %d\n", UCHAR_MAX);
    printf("unsigned long max is %lu\n", ULONG_MAX);
    printf("unsigned int max is %u\n", UINT_MAX);
    printf("unsigned short max is %d\n", USHRT_MAX);
    return 0;
}