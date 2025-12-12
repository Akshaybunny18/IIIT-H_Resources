#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll fun(ll* arr, ll n, ll* freq);
// {
//     ll min=arr[0];
//     for(ll i=0;i<n;i++){
//         freq[i]=0;
//         if(arr[i]<min){
//             min=arr[i];
//         }
//     }
//     for(ll i=0;i<n;i++){
//         freq[arr[i]-min]++;
//     }
//     for(ll i=0;i<n;i++){
//         if(freq[i]!=1)return 0;
//     }
//     return 1;
// }

int main() {
    ll n;
    scanf("%lld", &n);
    ll arr[n];
    for(ll i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }
    ll freq[n];
    printf("%s\n",fun(arr, n, freq) ? "TRUE" : "FALSE");
    return 0;
}