#include <stdio.h>

long double poe(long double u, long double v) {
    if (v == 0) { return 1; }
    long double um = 1;
    for (long double r = 0; r < v; r++) {
        um *= u;
    }
    return um;
}

long double fac(long double x) {
    if (x == 0) { return 1; }
    long double sum = 1;
    for (long double k = 1; k <= x; k++) {
        sum *= k;
    }
    return sum;
}

int main() {
    long double sem = 0; 
    long double p, n;
    scanf("%Lf %Lf", &p, &n); 
    
    for (long double o = 1; o <= n; o++) {
        long double hi = (poe(-1, o - 1) * poe(p, 2 * (o - 1))) / fac(2 * (o - 1));
        sem += hi;
    }
    
    printf("%.2Lf\n", sem); 
    return 0;
}

