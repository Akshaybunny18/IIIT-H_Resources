#include <stdio.h>
#include <stdlib.h>

long long function(long long n);
// {
//     long long n1=n;
//     long long m=0;
//     while(n!=0){
//         long long r=n%10;
//         m=m+r;
//         n=n/10;
//         m=m*10;
//     }
//     if(m==n1)return 1;
//     else return 0;
// }

int main() {
    long long int n;
    scanf("%lld", &n);
    if(function(n)==1)printf("TRUE\n");
    else printf("FALSE\n");
    return 0;
}