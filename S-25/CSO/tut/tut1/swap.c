#include <stdio.h>

void swap(long *xp, long *yp) {
    long t0 = *xp;
    long t1 = *yp;
    *xp = t1;
    *yp = t0;
}

int main() {
    long int x,y;
    scanf("%ld %ld", &x, &y);
    printf("x = %ld, y = %ld\n", x, y);
    swap(&x, &y);
    printf("x = %ld, y = %ld\n", x, y);
    return 0;
}