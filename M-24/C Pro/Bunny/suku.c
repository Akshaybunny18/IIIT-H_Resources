#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int x;
int aaa = 0;
void print(int a[][x]) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Checks if the entire Sudoku board is valid
int check(int a[][x]) {
    // Check rows
    for (int i = 0; i < x; i++) {
        int row[x];
        memset(row, 0, sizeof(row));
        for (int j = 0; j < x; j++) {
            if (a[i][j] != 0) {
                row[a[i][j] - 1]++;
                if (row[a[i][j] - 1] > 1) return 0;
            }
        }
    }

    // Check columns
    for (int i = 0; i < x; i++) {
        int col[x];
        memset(col, 0, sizeof(col));
        for (int j = 0; j < x; j++) {
            if (a[j][i] != 0) {
                col[a[j][i] - 1]++;
                if (col[a[j][i] - 1] > 1) return 0;
            }
        }
    }

    // Check subgrids
    int subgrid_size = (int)sqrt(x);
    for (int i = 0; i < x; i += subgrid_size) {
        for (int j = 0; j < x; j += subgrid_size) {
            int subgrid[x];
            memset(subgrid, 0, sizeof(subgrid));
            for (int k = i; k < i + subgrid_size; k++) {
                for (int l = j; l < j + subgrid_size; l++) {
                    if (a[k][l] != 0) {
                        subgrid[a[k][l] - 1]++;
                        if (subgrid[a[k][l] - 1] > 1) return 0;
                    }
                }
            }
        }
    }
    return 1;
}

// Checks if placing number `k` at position (i, j) is valid
int cheek(int a[][x], int i, int j, int k) {
    // Check row
    for (int l = 0; l < x; l++) {
        if (a[i][l] == k) return 0;
    }

    // Check column
    for (int l = 0; l < x; l++) {
        if (a[l][j] == k) return 0;
    }

    // Check subgrid
    int subgrid_size = (int)sqrt(x);
    int start_row = (i / subgrid_size) * subgrid_size;
    int start_col = (j / subgrid_size) * subgrid_size;
    for (int row = start_row; row < start_row + subgrid_size; row++) {
        for (int col = start_col; col < start_col + subgrid_size; col++) {
            if (a[row][col] == k) return 0;
        }
    }
    return 1;
}

int q = 0;
void suku(int a[][x]) {
    if (q == aaa) {  // All cells are filled, check if the solution is valid
        if (check(a)) {
            printf("Solution:\n");
            print(a);
        }
        return;
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (a[i][j] == 0) {
                for (int k = 1; k <= x; k++) {
                    if (cheek(a, i, j, k)) {
                        a[i][j] = k;
                        q++;
                        suku(a);
                        q--;
                        a[i][j] = 0;  // Backtrack
                    }
                }
                return ;
            }
        }
    }
}

int main() {
    scanf("%d", &x);
    int a[x][x];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            //a[i][j] = 0;
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            //a[i][j] = 0;
            if(a[i][j] == 0) aaa++;
        }
    }

    suku(a);
    return 0;
}
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0