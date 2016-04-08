#ifndef Header_h
#define Header_h

#include <iostream>
#define MAX 100
#define MIN -100
#define max(a ,b) ((a) > (b) ? (a) : (b))
#define square(x) ((x) * (x))
#define e(a, b) cheng(a, b)
#define mstr(s) str(s)
#define str(s) #s
#define WARN_IF(a) \
do { if (a) \
fprintf (stderr, "Warning: " #a "\n"); } \
while(0)

int cheng(const int a, const int b) {
    int c = a;
    for (int i = 0; i < b; i++)
        c *= 10;
    return c;
}

#endif /* Header_h */
