#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int left, int mid1, int mid2, int right) {
    int n1 = mid1 - left + 1;
    int n2 = mid2 - mid1;
    int n3 = right - mid2;

    int *L = malloc(n1 * sizeof(int));
    int *M = malloc(n2 * sizeof(int));
    int *R = malloc(n3 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) M[i] = arr[mid1 + 1 + i];
    for (int i = 0; i < n3; i++) R[i] = arr[mid2 + 1 + i];

    int i = 0, j = 0, k = 0, idx = left;
    while (i < n1 && j < n2 && k < n3) {
        if (L[i] <= M[j] && L[i] <= R[k]) arr[idx++] = L[i++];
        else if (M[j] <= L[i] && M[j] <= R[k]) arr[idx++] = M[j++];
        else arr[idx++] = R[k++];
    }

    while (i < n1 && j < n2) arr[idx++] = (L[i] <= M[j]) ? L[i++] : M[j++];
    while (j < n2 && k < n3) arr[idx++] = (M[j] <= R[k]) ? M[j++] : R[k++];
    while (i < n1 && k < n3) arr[idx++] = (L[i] <= R[k]) ? L[i++] : R[k++];

    while (i < n1) arr[idx++] = L[i++];
    while (j < n2) arr[idx++] = M[j++];
    while (k < n3) arr[idx++] = R[k++];

    free(L);
    free(M);
    free(R);
}

void mergeSortIterativeSetsOfThree(int *arr, int n) {
    for (int curr_size = 1; curr_size < n; curr_size *= 3) {
        for (int left = 0; left < n - 1; left += 3 * curr_size) {
            int mid1 = left + curr_size - 1;
            int mid2 = (left + 2 * curr_size - 1 < n - 1) ? left + 2 * curr_size - 1 : n - 1;
            int right = (left + 3 * curr_size - 1 < n - 1) ? left + 3 * curr_size - 1 : n - 1;

            merge(arr, left, mid1, mid2, right);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    mergeSortIterativeSetsOfThree(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
