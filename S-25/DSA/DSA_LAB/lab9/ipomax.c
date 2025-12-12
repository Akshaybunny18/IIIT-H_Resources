#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cap;
    int ret;
} pro;

void merge(pro* arr, int l, int m1, int m2, int r) {
    int n1 = m1 - l + 1;
    int n2 = m2 - m1;
    int n3 = r - m2;
    pro* L = (pro*)malloc(n1 * sizeof(pro));
    pro* M = (pro*)malloc(n2 * sizeof(pro));
    pro* R = (pro*)malloc(n3 * sizeof(pro));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) M[i] = arr[m1 + 1 + i];
    for (int i = 0; i < n3; i++) R[i] = arr[m2 + 1 + i];
    int i = 0, j = 0, k = 0, p = l;
    while (i < n1 && j < n2 && k < n3) {
        if (L[i].cap <= M[j].cap && L[i].cap <= R[k].cap) arr[p++] = L[i++];
        else if (M[j].cap <= L[i].cap && M[j].cap <= R[k].cap) arr[p++] = M[j++];
        else arr[p++] = R[k++];
    }
    while (i < n1 && j < n2) {
        if (L[i].cap <= M[j].cap) arr[p++] = L[i++];
        else arr[p++] = M[j++];
    }
    while (j < n2 && k < n3) {
        if (M[j].cap <= R[k].cap) arr[p++] = M[j++];
        else arr[p++] = R[k++];
    }
    while (i < n1 && k < n3) {
        if (L[i].cap <= R[k].cap) arr[p++] = L[i++];
        else arr[p++] = R[k++];
    }
    while (i < n1) arr[p++] = L[i++];
    while (j < n2) arr[p++] = M[j++];
    while (k < n3) arr[p++] = R[k++];
    free(L);
    free(M);
    free(R);
}

void mergesort3way(pro* arr, int l, int r) {
    if (l < r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        mergesort3way(arr, l, m1);
        mergesort3way(arr, m1 + 1, m2);
        mergesort3way(arr, m2 + 1, r);
        merge(arr, l, m1, m2, r);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            swap(&heap[index], &heap[parent]);
            index = parent;
        } else break;
    }
}

void heapifyDown(int* heap, int size, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;
        if (largest != index) {
            swap(&heap[index], &heap[largest]);
            index = largest;
        } else break;
    }
}

void insertHeap(int* heap, int* size, int value) {
    heap[(*size)++] = value;
    heapifyUp(heap, *size - 1);
}

int extractMax(int* heap, int* size) {
    int max = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size, 0);
    return max;
}

int main() {
    int k, c, n;
    scanf("%d %d %d", &n, &k, &c);
    pro* ipo = (pro*)malloc(n * sizeof(pro));
    for (int i = 0; i < n; i++) scanf("%d %d", &ipo[i].ret, &ipo[i].cap);
    mergesort3way(ipo, 0, n - 1);
    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0, j = 0;
    for (int i = 0; i < k; i++) {
        while (j < n && ipo[j].cap <= c) {
            insertHeap(heap, &heapSize, ipo[j].ret);
            j++;
        }
        if (heapSize == 0) break;
        c += extractMax(heap, &heapSize);
    }
    printf("%d\n", c);
    free(ipo);
    free(heap);
    return 0;
}