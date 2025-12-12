#include <stdio.h>
#include <stdlib.h>

int unq(long long *arr, long long n, long long *res);
// {
//     long long size=0;
//     long long prev=arr[0];
//     res[size]=prev;
//     size++;
//     for(long long i=1;i<n;i++){
//         if(arr[i]!=prev){
//             res[size]=arr[i];
//             size++;
//             prev=arr[i];
//         }
//     }
//     return size;
// }

int main() {
    long long n;
    scanf("%lld",&n);
    long long *arr = (long long *)malloc(n * sizeof(long long));
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    long long *res= (long long *)malloc(n * sizeof(long long));
    int size=unq(arr, n, res);
    for (long long i = 0; i < size; i++) {
        printf("%lld ", res[i]);
    }
    return 0;
}