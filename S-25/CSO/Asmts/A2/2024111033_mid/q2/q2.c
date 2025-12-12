#include <stdio.h>
#include <stdlib.h>

long long ncr(int n,int r);
// {
//     if(r==0) return 1;
//     return (n*ncr(n-1,r-1))/r;
// }

int main() {
    long long n,r;
    scanf("%lld %lld",&n,&r);
    printf("%lld\n",ncr(n,r));
    return 0;
}