//
//  Header.h
//  排序二叉树
//
//  Created by 邱兆丰 on 16/1/6.
//  Copyright (c) 2016年 邱兆丰. All rights reserved.
//

#ifndef ______Header_h
#define ______Header_h

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int value;
} Node;

Node* creatnode(int value) {
    Node* p;
        p = malloc(sizeof(Node));
        p->value = value;
        p->left = NULL;
        p->right = NULL;
    return p;
}

void traverse_tree_inorder(Node *p) {
    if (p != NULL) {
    traverse_tree_inorder(p->left);
    printf("%d ", p->value);
    traverse_tree_inorder(p->right);
    }
}

void recycle_nodes(Node *p) {
    if (p != NULL) {
        recycle_nodes(p->left);
        recycle_nodes(p->right);
        free(p);
    }
}

void insert_node(Node *p, int value) {
    if (p->value > value) {
        if (p->left == NULL) {
            p->left = creatnode(value);
        } else {
            insert_node(p->left, value);
        }
    }
    if (p->value < value) {
        if (p->right == NULL) {
            p->right = creatnode(value);
        } else {
            insert_node(p->right, value);
        }
    }
}

Node* init_root(int value) {
    Node* root;
    root = malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;
    root->value = value;
    return root;
}

#endif
