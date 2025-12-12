#include <stdio.h>
#include <stdlib.h>
#define ll long long 

int fun(ll n, ll d);
// {
//     if(n<=1){
//         return 0;
//     }
//     ll power=1;
//     for(ll i=1;i<d;i++){
//         power*=10;
//     }
//     for(ll i=0;i<d;i++){
//         for(ll j=2;j<n;j++){
//             if(n%j==0){
//                 return 0;
//             }
//         }
//         ll digit=n%10;
//         n/=10;
//         n+=digit*power;
//     }
//     return 1;
// }

int main() {
    ll n,d;
    scanf("%lld %lld", &n, &d);
    printf("%s\n", fun(n,d) ? "TRUE" : "FALSE");
    return 0;
}