#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll* fun(ll* arr, ll n);
// {
//     for(ll i=0;i<n-1;i++){
//         for(ll j=0;j<n-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 ll temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//             }
//         }
//     }
//     for(ll i=0;i<n-1;i+=2){
//         ll temp=arr[i];
//         arr[i]=arr[i+1];
//         arr[i+1]=temp;
//     }
//     return arr;
// }

int main() {
    ll n;
    scanf("%lld", &n);
    ll* arr=(ll*)malloc(n * sizeof(ll));
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    arr=fun(arr, n);
    for (ll i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    return 0;
}