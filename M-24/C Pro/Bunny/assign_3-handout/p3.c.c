#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, k = 1, r, t, y, c;
    scanf("%d %d", &n, &m);    

    // Allocate memory for n pointers to int arrays
    int **ma = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        ma[i] = (int *)malloc(k * sizeof(int));  // Allocate initial memory for 1 element in each row
        ma[i][0] = 1;  // Initialize the first element of each row to 1
    }

    int arr[m];  // Variable-length array
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &r, &t);
        if (r == 1) {
            arr[i] = t;
            scanf("%d", &y);
            c = 0;
            for (int o = 0; o <= i; o++) {
                if (arr[o] == t) {
                    c += 1;
                }
            }
            ma[t] = (int *)realloc(ma[t], (k + c) * sizeof(int));  // Reallocate with the correct size
            ma[t][k + c - 1] = y;  // Store the value y in the next position
        } 
        else if (r == 2) {
            c = 0;
            for (int o = 0; o <= i; o++) {
                if (arr[o] == t) {
                    c += 1;
                }
            }
            // Print the contents of ma[t]
            for (int v = 0; v < (k + c); v++) {
                printf("%d ", ma[t][v]);
            }
            printf("\n");
        }
    }
    for (int i = 0; i < n; i++) {
        free(ma[i]);  // Free each row
    }
    free(ma); 
    return 0;
}
