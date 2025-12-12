/*
 Lab 8A problem 1
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    file = fopen("input.bin", "rb");
    long long int sum = 0;
    int x, y;
    int prev_x, prev_y;
    fread(&prev_x, sizeof(int), 1, file);
    fread(&prev_y, sizeof(int), 1, file);
    int a= prev_x;
    int b= prev_y;
    while (fread(&x, sizeof(int), 1, file))
    {
        fread(&y, sizeof(int), 1, file);
        sum += abs(x - prev_x);
        sum%=1000000007;
        sum+= abs(y - prev_y);
        prev_x = x;
        prev_y = y;
        sum%=1000000007;
    }
    sum+=abs(a-prev_x)+abs(b-prev_y);
    sum%=1000000007;
    fclose(file);
    printf("%lld", sum);
    return 0;
}