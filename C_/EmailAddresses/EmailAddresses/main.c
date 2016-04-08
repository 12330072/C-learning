#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int N;
    int i, j;
    char add[50][50];
    char bdd[50][50];
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%s", add[i]);
        for (j = 0; j < i; j++) {
            if (strcmp(add[i], add[j]) == 0) {
                N--;
                i--;
            }
        }
    }
    for (i = 0; i < N; i++) {
        strncpy(bdd[i], add[i], 50);
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < 50; j++) {
            if (isupper(add[i][j])) {
                add[i][j] += 32;
            }
        }
    }
    char temp[50];
    int top, seek;
    for (top = 0; top < N - 1; top++) {
        for (seek = top + 1; seek < N; seek++) {
            if (strcmp(add[top], add[seek]) > 0) {
                strncpy(temp, add[top], 50);
                strncpy(add[top], add[seek], 50);
                strncpy(add[seek], temp, 50);
                strncpy(temp, bdd[top], 50);
                strncpy(bdd[top], bdd[seek], 50);
                strncpy(bdd[seek], temp, 50);
            }
        }
    }
    for (i = 0; i < N; i++) {
        printf("%s\n", bdd[i]);
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < 50; j++) {
            add[i][j] = '\0';
            bdd[i][j] = '\0';
        }
    }
    return 0;
}
