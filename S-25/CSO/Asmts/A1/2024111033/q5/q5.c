#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void prodarr(long long* arr,long long n, long long* res);
// {
//     long long zerocount=0;
//     long long prod=1;
//     for(long long i=0; i<n; i++)
//     {
//         if(arr[i]==0)
//         {
//             zerocount++;
//         }
//         else
//         {
//             prod*=arr[i];
//         }
//     }
//     if(zerocount>1)
//     {
//         for(long long i=0; i<n; i++)
//         {
//             res[i]=0;
//         }
//         return;
//     }
//     else if (zerocount==1){
//         for(long long i=0; i<n; i++){
//             if(arr[i]==0){
//                 res[i]=prod;
//             }
//             else{
//                 res[i]=0;
//             }
//         }
//         return;
//     }
//     else{
//         for(long long i=0; i<n; i++){
//             res[i]=prod/arr[i];
//         }
//         return;
//     }
// }

int main()
{
    long long n;
    scanf("%lld", &n);
    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    long long* res=(long long*)malloc(n*sizeof(long long));
    prodarr(arr, n, res);
    for (long long i = 0; i < n; i++)
    {
        printf("%lld ", (res[i]%LLONG_MAX));
    }
    printf("\n");
    return 0;
}
