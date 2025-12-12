#include <stdio.h>
#include <stdlib.h>

void merge(int *l, int start, int size, int n) {
    int *li = (int *)malloc(sizeof(int) * (3 * size));
    int k = 0, i = start, j = start + size, m = start + 2 * size;

    int end_i = (start + size - 1 < n - 1) ? start + size - 1 : n - 1;
    int end_j = (start + 2 * size - 1 < n - 1) ? start + 2 * size - 1 : n - 1;
    int end_m = (start + 3 * size - 1 < n - 1) ? start + 3 * size - 1 : n - 1;

    while (i <= end_i && j <= end_j && m <= end_m) {
        if (l[i] <= l[j] && l[i] <= l[m]) {
            li[k++] = l[i++];
        } else if (l[j] <= l[i] && l[j] <= l[m]) {
            li[k++] = l[j++];
        } else {
            li[k++] = l[m++];
        }
    }

    while (i <= end_i && j <= end_j) {
        li[k++] = (l[i] <= l[j]) ? l[i++] : l[j++];
    }
    while (j <= end_j && m <= end_m) {
        li[k++] = (l[j] <= l[m]) ? l[j++] : l[m++];
    }
    while (i <= end_i && m <= end_m) {
        li[k++] = (l[i] <= l[m]) ? l[i++] : l[m++];
    }

    while (i <= end_i) li[k++] = l[i++];
    while (j <= end_j) li[k++] = l[j++];
    while (m <= end_m) li[k++] = l[m++];

    for (int a = 0; a < k; a++) {
        l[start + a] = li[a];
    }

    free(li);
}

int main() {
    int x;

    printf("Enter length of list: ");
    scanf("%d", &x);

    int *l = (int *)malloc(sizeof(int) * x);

    for (int i = 0; i < x; i++) {
        printf("Enter value of %dth element of list: ", i + 1);
        scanf("%d", &l[i]);
    }

    int i = 1;
    while (i < x) {
        for (int a = 0; a < x; a += 3 * i) {
            merge(l, a, i, x);
        }
        i *= 3;
    }

    printf("Sorted list: ");
    for (int i = 0; i < x; i++) {
        printf("%d ", l[i]);
    }
    printf("\n");

    free(l);
    return 0;
}
