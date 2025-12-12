#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll binarysearch(ll* arr, ll start, ll end, ll x);
// {
//     if (start > end) return -1;
//     ll mid = start + (end - start) / 2;
//     if (arr[mid] == x) return mid;
//     if (arr[mid] > x) return binarysearch(arr, start, mid - 1, x);
//     return binarysearch(arr, mid + 1, end, x);
// }

int main() {
    ll n;
    scanf("%lld", &n);
    ll* arr=(ll*)malloc(n*sizeof(ll));
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    ll x;
    scanf("%lld", &x);
    printf("%lld\n", binarysearch(arr, 0, n - 1, x));
    return 0;
}