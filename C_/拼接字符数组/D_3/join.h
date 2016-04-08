//
//  Header.h
//  D_3
//
//  Created by 邱兆丰 on 15/12/9.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#ifndef D_3_Header_h
#define D_3_Header_h
char* join(char a[], int size1, char b[], int size2) {
    char *p;
    p = malloc((size1 + size2) * sizeof (*p));
    strncpy(p, a, size1 + 1);
    strncat(p, b, size2 + 1);
    return p;
}

#endif

