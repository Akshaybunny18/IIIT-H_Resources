#include <stdio.h>
#include <stdlib.h>

// Function to find the next greater element for each element in the array
void nextgrelt(long long* arr, long long n, long long* result, long long* stack);
// {
//     for (long long i = 0; i < n; i++) {
//         result[i] = -1;
//     }
//     for(long long i=n-1;i>=0;i--){
//         while(*top!=-1 && stack[*top] <= arr[i]){
//             (*top)--;
//         }
//         if(*top == -1){
//             result[i] = -1;
//         } else {
//             result[i] = stack[*top];
//         }
//         stack[++(*top)] = arr[i];
//     }
// }

int main() {
    long long n;
    scanf("%lld", &n);
    long long *arr = (long long *)malloc(n * sizeof(long long));
    for(long long i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    long long* stack = (long long*)malloc(n * sizeof(long long));
    long long* result = (long long*)malloc(n * sizeof(long long));
    nextgrelt(arr, n, result, stack);
    for (long long i = 0; i < n; i++) {
        printf("%lld ", result[i]);
    }
    return 0;
}