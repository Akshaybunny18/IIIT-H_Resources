#include <stdio.h>
#include <limits.h>

long long diff(long long* arr, long long n);
// {
//     long long max = arr[0];
//     long long min = arr[0];
//     for (long long i = 0; i < n; i++){
//         if (max<arr[i]){
//             max = arr[i];
//         }
//         if (min>arr[i]){
//             min = arr[i];
//         }
//     }
//     return max - min;
// }

int main() {
    long long n;
    scanf("%lld", &n);
    long long arr[n];

    for (long long i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    // // Debugging: Print array before passing to assembly
    // printf("Array: ");
    // for (long long i = 0; i < n; i++) {
    //     printf("%lld ", arr[i]);
    // }
    // printf("\n");

    // // Debugging: Print the size of the array
    // printf("Size of array: %lld\n", n);

    long long int result = diff(arr, n);
    printf("%lld\n", result%LLONG_MAX);
    return 0;
}