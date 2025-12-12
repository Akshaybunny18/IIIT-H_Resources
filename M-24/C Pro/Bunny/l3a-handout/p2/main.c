#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int N, c = 0, a = 0;
    scanf("%d", &N);
    int m[N][N], k[N];
    for (int i = 0; i < N; i++) {
        k[i] = 0;
        for (int j = 0; j < N; j++) {
            scanf("%d", &m[i][j]);
            k[i] += m[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (k[i] == k[j] || gcd(k[i], k[j]) == 1) {
                c += 1;
            }
        }
    }
    printf("%d", c);
    return 0;
}
