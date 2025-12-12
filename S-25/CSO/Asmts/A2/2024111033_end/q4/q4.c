#include <stdio.h>
#include <stdlib.h>
#define int long long int

int majority(int* arr, int n);
// {
//     int count=0;
//     int majelt=-1;
//     for(int i=0;i<n;i++){
//         if(count==0){
//             majelt=arr[i];
//             count++;
//         }
//         else if(arr[i]==majelt){
//             count++;
//         }
//         else{
//             count--;
//         }
//     }
//     return majelt;
// }

signed main() {
    int n;
    scanf("%lld", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    printf("%lld\n", majority(arr, n));
    return 0;
}