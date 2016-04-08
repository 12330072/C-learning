//
//  function.h
//  d3
//
//  Created by 邱兆丰 on 15/12/23.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#ifndef d3_function_h
#define d3_function_h

void swap(int * a, int * b) {
    int change;
    change = *a;
    *a = *b;
    *b = change;
}

Link subMiddle(Link head) {
    Link p1, p2, p3;
    p2 = head;
    p3 = head -> next;
    p1 = p3 -> next;
    p2 -> next = p1;
    return p3;
}

#endif
