#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n, int max) {
    int* count = (int*) calloc(max + 1, sizeof(int));  // Array to store the count of each element
    int* output = (int*) malloc(n * sizeof(int));  // Output array to store the sorted result

    // Count each element in the array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modify the count array such that each element at index i stores the sum of previous counts
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Build the sorted output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted output back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 8;  // Maximum value in the array

    countingSort(arr, n, max);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

