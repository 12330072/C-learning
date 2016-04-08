//
//  tree.h
//  二叉树链表实现
//
//  Created by 邱兆丰 on 15/12/28.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#ifndef ________tree_h
#define ________tree_h

typedef struct node {
    int x;
    struct node* left;
    struct node* right;
} BN;

void buildTree(BN** rootptr);
void outputTree(BN* root);

void buildTree(BN** rootptr) {
    BN* que[50];
    int n;
    int head = 0;
    int tail = 1;
    que[0] = malloc(sizeof(BN));
    *rootptr = que[0];
    scanf("%d", &que[0]->x);
    que[0]->left = NULL;
    que[0]->right = NULL;
    while (scanf("%d", &n) &&  n != -1) {
        que[tail] = malloc(sizeof(BN));
        que[tail]->x = n;
        que[tail]->left = NULL;
        que[tail]->right = NULL;
        if (que[head]->left == NULL) {
            que[head]->left = que[tail];
            tail++;
        }
        else if (que[head]->right == NULL) {
            que[head]->right = que[tail];
            tail++;
            head++;
        }
    }
}

void outputTree(BN* root) {
    if (root != NULL) {
        outputTree(root->left);
        printf("%d ", root->x);
        outputTree(root->right);
    }
}
#endif



















