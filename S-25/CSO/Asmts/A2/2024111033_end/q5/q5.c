#include <stdio.h>
#include <stdlib.h>

short int findpeak(short int* arr, int n);
// {
//     if(n == 1) {
//         return arr[0];
//     }
//     if(n == 2) {
//         if(arr[0] > arr[1]) {
//             return arr[0];
//         } else {
//             return arr[1];
//         }
//     }
//     int mid = n / 2;
//     if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
//         return arr[mid];
//     } 
//     if(arr[mid] < arr[mid - 1]) {
//         return findpeak(arr, mid);
//     }
//     else {
//         return findpeak(arr + mid, n - mid);
//     }
// }

int main() {
    int n;
    scanf("%d", &n);
    short int* arr=(short int*)malloc(n * sizeof(short int));
    for (int i = 0; i < n; i++) {
        scanf("%hd", &arr[i]);
    }
    printf("%hd\n", findpeak(arr, n));
    return 0;
}