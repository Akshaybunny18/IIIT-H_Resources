#include <stdio.h>
#include <stdlib.h>

long long subzero(long long* arr, long long n);
// {
//     int count=0;
//     for(int i=1;i<=n;i++){
//         int sum=0;
//         for(int j=0;j<i;j++){
//             sum+=arr[j];
//         }
//         if(sum==0){
//             count++;
//         }
//         for(int j=i;j<n;j++){
//             sum-=arr[j-i];
//             sum+=arr[j];
//             if(sum==0){
//                 count++;
//             }
//         }
//     }
//     return count;
// }

int main() {
    long long n;
    scanf("%lld", &n);
    long long *arr = (long long*)malloc(n*sizeof(long long));
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    printf("%lld\n",subzero(arr, n));
    return 0;
}