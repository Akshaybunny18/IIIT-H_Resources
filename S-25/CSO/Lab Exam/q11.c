#include <stdio.h>
#include <stdlib.h>
#define ll long long

void fun(ll* arr, ll n, ll* stack, ll* res);
// {
//     ll top = -1;
//     for (ll i = 0; i < n; i++) {
//         while(top!=-1 && stack[top]<=arr[i]){
//             top--;
//         }
//         if(top==-1){
//             res[i]=-1;
//         }
//         else{
//             res[i]=stack[top];
//         }
//         top++;
//         stack[top]=arr[i];
//     }
// }

int main() {
    ll n;
    scanf("%lld", &n);
    ll* arr=(ll*)malloc(n*sizeof(ll));
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    ll* res=(ll*)malloc(n*sizeof(ll));
    ll* stack=(ll*)malloc(n*sizeof(ll));
    fun(arr, n, stack, res);
    for (ll i = 0; i < n; i++) {
        printf("%lld ", res[i]);
    }
    printf("\n");
    return 0;
}