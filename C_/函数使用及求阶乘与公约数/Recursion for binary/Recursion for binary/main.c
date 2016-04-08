//
//  main.c
//  Recursion for binary
//
//  Created by 邱兆丰 on 15/12/2.
//  Copyright (c) 2015年 邱兆丰. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Cal.h"

void displaymenu() {
    printf("================================\n");
    printf("      MENU                  \n");
    printf("================================\n");
    printf("     1.Add\n");
    printf("     2.Subtract \n");
    printf("     3.Multiply \n");
    printf("     4.Divide \n");
    printf("     5.Modulus \n");
}


int main(int argc, char *argv[]) {
    displaymenu();
    int yourchoice;
    int a;
    int b;
    printf("Enter your choice(1-5):");
    scanf("%d:", &yourchoice);
    printf("Enter your two integer numbers:");
    scanf("%d %d", &a, &b);
    printf("\n");
    switch (yourchoice) {
        case 1:
            printf("Result:%d\n", Add(a, b));
            break;
        case 2:
            printf("Result:%d\n", Substract(a, b));
            break;
        case 3:
            printf("Result:%d\n", Multiply(a, b));
            break;
        case 4:
            printf("Result:%.2f\n", Divide(a, b));
            break;
        case 5:
            printf("Result:%d\n", Modulus(a, b));
            break;
        default:
            printf("Invalid\n");
    }
    return 0;
}

