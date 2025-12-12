#include <stdio.h>
#include <stdlib.h>

void merge(int *l, int start, int size, int n) {
    int *li = (int *)malloc(sizeof(int) * (2 * size));
    int k = 0, i = start, j = start + size;

    while (i <= start + size - 1 && j <= (start + 2 * size - 1 < n - 1 ? start + 2 * size - 1 : n - 1)) {
        if (l[i] > l[j]) {
            li[k++] = l[j++];
        } else {
            li[k++] = l[i++];
        }
    }

    while (i <= start + size - 1) {
        li[k++] = l[i++];
    }

    while (j <= (start + 2 * size - 1 < n - 1 ? start + 2 * size - 1 : n - 1)) {
        li[k++] = l[j++];
    }

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
        for (int a = 0; a < x; a += 2 * i) {
            merge(l, a, i, x);
        }
        i *= 2;
    }

    printf("Sorted list: ");
    for (int i = 0; i < x; i++) {
        printf("%d ", l[i]);
    }
    printf("\n");

    free(l);
    return 0;
}
