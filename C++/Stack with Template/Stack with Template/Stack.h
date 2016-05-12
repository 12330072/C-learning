//
//  Stack.h
//  Stack with Template
//
//  Created by 邱兆丰 on 16/4/22.
//  Copyright © 2016年 菇生. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

template<typename T>
class Stack {
  public:
    Stack() {
        top_node = NULL;
        node_num = 0;
    }
    Stack(const Stack &stack) {
        if (stack.top_node != NULL) {
            top_node = new Node(stack.top_node->element, NULL);
            node_num = stack.node_num;
            Node* p1 = top_node;
            Node* p2 = stack.top_node;
            while (p2->next != NULL) {
                p1->next = new Node(p2->next->element, NULL);
                p2 = p2->next;
                p1 = p1->next;
            }
        } else {
            top_node = NULL;
            node_num = 0;
        }
    }
    ~Stack() {
        if (node_num != 0) {
            clear();
        }
    }
    bool empty() {
        return node_num == 0;
    }
    size_t size() const {
        return node_num;
    }
    T top() const {
        return top_node->element;
    }
    void push(T element) {
        Node* temp = new Node(element, top_node);
        top_node = temp;
        node_num++;
    }
    void pop() {
        if (top_node != NULL) {
            Node* p = top_node;
            top_node = top_node->next;
            delete p;
            node_num--;
        }
    }
    void swap(Stack& stack) {
        Node* pTemp = top_node;
        top_node = stack.top_node;
        stack.top_node = pTemp;
        size_t nTemp = node_num;
        node_num = stack.node_num;
        stack.node_num = nTemp;
    }
    void reverse() {
        Stack newStack;
        while (node_num > 0) {
            newStack.push(top_node->element);
            this->pop();
        }
        swap(newStack);
    }
    void clear() {
        Node* p = top_node;
        Node* temp = p;
        while (p != NULL) {
            temp = p;
            p = p->next;
            delete temp;
        }
        node_num = 0;
    }
  private:
    struct Node {
        T element;
        Node* next;
        Node(T ele, Node *n = NULL) {
            element = ele;
            next = n;
        }
    };
    Node *top_node;
    size_t node_num;
};

#endif /* Stack_h */
