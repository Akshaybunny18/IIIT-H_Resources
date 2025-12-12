#include <stdio.h>

long long findunique(long long* arr, long long n, long long* freq);
// {
//     for (long long i = 0; i < n; i++)
//     {
//         freq[arr[i]]++;
//     }
//     for (long long i = 0; i < 100001; i++)
//     {
//         if (freq[i] == 1)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

int main(){
    long long n;
    scanf("%lld", &n);
    long long arr[3*n+1];
    for(long long i=0; i<3*n+1; i++)
    {
        scanf("%lld", &arr[i]);
    }
    long long freq[100001];
    for (long long i = 0; i < 100001; i++)
    {
        freq[i] = 0;
    }
    long long res = findunique(arr, 3*n+1, freq);
    printf("%lld\n", res);
    return 0;
}
