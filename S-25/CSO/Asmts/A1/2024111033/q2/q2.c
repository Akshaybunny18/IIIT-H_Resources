#include <stdio.h>

long long* rotateby2(long long* a,long long n);
// {
//     long long temp1=a[n-1],temp2=a[n-2];
//     for(long long i=n-3;i>=0;i--){
//         a[i+2]=a[i];
//     }
//     a[0]=temp2;
//     a[1]=temp1;
//     return a;
// }

int main()
{
    long long n;
    scanf("%lld",&n);
    long long a[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    long long* b=rotateby2(a,n);
    for(int i=0;i<n;i++){
        printf("%lld ",b[i]);
    }
    printf("\n");
    return 0;
}
