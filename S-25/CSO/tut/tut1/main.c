#include <stdio.h>

void swap(long* a, long* b);

int main() {
    long a, b;
    scanf("%ld %ld", &a, &b);
    printf("before swap %ld %ld\n", a, b);
    swap(&a, &b);
    printf("after swap %ld %ld\n", a, b);
    return 0;
}
