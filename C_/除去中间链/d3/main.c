//
//  main.c
//  d3
//
//  Created by 邱兆丰 on 15/12/23.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "function.h"

int main() {
    int a, b;
    
    scanf("%d%d", &a, &b);
    swap(&a, &b);  // 交换a，b变量的值
    printf("%d %d\n", a, b);
    
    // 链表头部、尾部、用于存储malloc得到Node地址的临时指针
    Link head, tail, temp;
    head = tail = NULL;
    
    // 创建长度为3的链表
    int t = 3;
    while (t--) {
        // 这里写上强制类型转换也能过google风格
        // temp = (Link)malloc(sizeof(Node));
        temp = malloc(sizeof(Node));
        scanf("%d", &temp->num);
        //  将每个节点的下个指针置为NULL
        temp->next = NULL;
        if (!head) {  // 第一个节点
            head = tail = temp;
        } else {  // 后续节点
            tail->next = temp;
            tail = tail->next;
        }
    }
    
    temp = subMiddle(head);  // 移除中间节点
    free(temp);  // 释放内存中间节点内存
    
    temp = head;
    while (temp) {  // 遍历输出
        printf("%d ", temp->num);
        temp = temp->next;
    }
    
    while (head) {  // 释放移除节点后的链表所占内存
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
