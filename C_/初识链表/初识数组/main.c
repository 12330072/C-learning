//
//  main.c
//  初识数组
//
//  Created by 邱兆丰 on 15/12/18.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include<stdio.h>
typedef struct node *link;
typedef struct node {
    int student_num;
    char grade;
    link next;
}node;

int main(void) {
    int num, n;
    scanf("%d %d", &num, &n);
    node list[100];
    int i;
    for (i = 0; i < num; i++) {
        scanf("%d %c", &list[i].student_num, &list[i].grade);
        if (i == 0)
            list[i].next = NULL;
        else
            list[i].next = &list[i-1];
    }
    list[0].next = &list[num-1];
    for (i = 0; i < num; i++) {
        if (n == list[i].student_num) {
            printf("%c\n", list[i].next->grade);
            break;
        }
    }
    return 0;
}