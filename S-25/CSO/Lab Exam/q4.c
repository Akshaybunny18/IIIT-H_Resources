#include <stdio.h>
#include <stdlib.h>

long long function(long long* arr, long long m, long long n);
// {
//     long long sum=0;
//     for(long long i=0;i<m*n;i++){
//         if(arr[i]%5!=0 && arr[i]%3==0){
//             sum+=arr[i];
//         }
//     }
//     return sum;
// }

int main() {
    long long m,n;
    scanf("%lld %lld", &m, &n);
    long long arr[m][n];
    for (long long i = 0; i < m; i++) {
        for (long long j = 0; j < n; j++) {
            scanf("%lld", &arr[i][j]);
        }
    }
    printf("%lld\n", function(&arr[0][0], m, n));
    return 0;
}