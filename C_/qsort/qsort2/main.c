//
//  main.c
//  qsort2
//
//  Created by 邱兆丰 on 15/12/9.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//
/* qsort example */

#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */

int values[] = { 40, 10, 100, 90, 20, 25 };

int compare (const void * a, const void * b)
{
    return ( *(int*)b - *(int*)a);
}

int main ()
{
    int n;
    qsort (values, 6, sizeof(int), compare);
    for (n=0; n<6; n++)
        printf ("%d ",values[n]);
    return 0;
}