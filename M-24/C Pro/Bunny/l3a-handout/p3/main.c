#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int matrix[n][m];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int i = 0, j = 0;
    int sum = matrix[0][0];
    
    while (i < n - 1 || j < m - 1) {
        if (i == n - 1) {
            j++;
        } else if (j == m - 1) {
            i++;
        } else {
            if (matrix[i + 1][j] < matrix[i][j + 1]) {
                i++;
            } else {
                j++;
            }
        }
        sum += matrix[i][j];
    }
    
    printf("%d\n", sum);

    return 0;
}
