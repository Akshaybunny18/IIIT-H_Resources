#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll fun(ll n);
// {
//     ll sum=0;
//     ll temp=n;
//     while(temp>0){
//         ll digit=temp%10;
//         ll fact=1;
//         for(ll i=1;i<=digit;i++){
//             fact*=i;
//         }
//         temp/=10;
//         sum+=fact;
//     }
//     if(sum==n)return 1;
//     return 0;
// }

int main() {
    ll n;
    scanf("%lld", &n);
    printf("%s\n", fun(n) ? "TRUE" : "FALSE");
    return 0;
}