#include <stdio.h>

void swap(long *a, long *b);

// void swap(long *a, long *b)
// {
//     long t0 = *a;
//     long t1 = *b;
//     *a = t1;
//     *b = t0;
// }

int main()
{
    long a, b;
    scanf("%ld %ld", &a, &b);
    printf("Before swapping: a=%ld and b=%ld\n", a, b);
    swap(&a, &b);
    printf("After swapping: a=%ld and b=%ld\n", a, b);
    return 0;
}
