//
//  BinatyTree.cpp
//  Binary Tree
//
//  Created by 邱兆丰 on 16/5/11.
//  Copyright © 2016年 菇生. All rights reserved.
//

#include "BinaryTree.hpp"
#include <queue>
#include <iterator>

BinaryTree::BinaryTree(const BinaryTree& othBT) {
    root = NULL;
    root = copyNode(othBT.getRoot(), root);
}

BinaryTree::BinaryTree(std::vector<char> & Vec) {
    int i = 0;
    if (!Vec.empty()) {
        std::queue<BinaryTree::Node**> q;
        while (!q.empty()) q.pop();
        q.push(&root);
        while (!q.empty()) {
            if (Vec[i] != EMPTY_ELE) {
                *q.front() = new Node(Vec[i], NULL, NULL);
                q.push(&(*q.front())->left);
                q.push(&(*q.front())->right);
            }
            i++;
            q.pop();
        }
    } else {
        root = NULL;
    }
}

BinaryTree::Node* creatTree(std::vector<char>::iterator preOrder,
                            std::vector<char>::iterator inOrder, int n) {
    std::vector<char>::iterator p1, p2;
    int i;
    if (n <= 0) {
        return NULL;
    }
    BinaryTree::Node* root = NULL;
    root = new BinaryTree::Node(*preOrder, NULL, NULL);
    i = 0;
    std::vector<char>::iterator temp = inOrder;
    while (i < n) {
        if (*preOrder == *temp) break;
        ++temp;
        ++i;
    }
    p1 = (preOrder + 1);
    p2 = inOrder;
    root->left = creatTree(p1, p2, i);
    p1 = (preOrder + i + 1);
    p2 = (inOrder + i + 1);
    root->right = creatTree(p1, p2, n - i - 1);
    return root;
}

// created by preorder and inorder
BinaryTree::BinaryTree(const std::vector<char>& preOrder,
                       const std::vector<char>& inOrder) {
    if (!preOrder.empty() && !inOrder.empty()) {
        std::vector<char> copy1(preOrder);
        std::vector<char> copy2(inOrder);
        std::vector<char>::iterator p1 = copy1.begin();
        std::vector<char>::iterator p2 = copy2.begin();
        int n = preOrder.size();
        root = creatTree(p1, p2, n);
    } else {
        root = NULL;
    }
}

BinaryTree::~BinaryTree() {
    if (root != NULL) {
        clear();
    }
}

BinaryTree::Node* BinaryTree::getRoot() const {
    return root;
}

void BinaryTree::clear() {
    if (root != NULL) {
        std::queue<Node**> q;
        while (!q.empty()) q.pop();
        if (root != NULL) {
            Node *p[1000];
            int i = 0;
            q.push(&root);
            while (!q.empty()) {
                if (*q.front() != NULL) {
                    if ((*q.front())->left)
                        q.push(&(*q.front())->left);
                    if ((*q.front())->right)
                        q.push(&(*q.front())->right);
                }
                if (*q.front() != NULL) {
                    p[i++] = *q.front();
                    q.pop();
                } else {
                    q.pop();
                }
            }
            for (int j = 0; j < i; j++) {
                delete p[j];
            }
        }
    }
}

void BinaryTree::preOrder(void (*visite)(BinaryTree::Node*), Node* t) {
    if (t) {
        visite(t);
        preOrder(visite, t->left);
        preOrder(visite, t->right);
    }
}

void BinaryTree::inOrder(void (*visite)(BinaryTree::Node*), Node* t) {
    if (t) {
        inOrder(visite, t->left);
        visite(t);
        inOrder(visite, t->right);
    }
}

void BinaryTree::postOrder(void (*visite)(BinaryTree::Node*), Node* t) {
    if (t) {
        postOrder(visite, t->left);
        postOrder(visite, t->right);
        visite(t);
    }
}

BinaryTree::Node * BinaryTree::copyNode(Node * oldNode, Node * newNode) {
    if (oldNode != NULL) {
        newNode = new Node(oldNode->val);
        newNode->left = copyNode(oldNode->left, newNode->left);
        newNode->right = copyNode(oldNode->right, newNode->right);
    }
    return newNode;
}
