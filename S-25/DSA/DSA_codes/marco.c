#include <stdio.h>
#define dbg(x) printf("DBG: %s = %d\n", #x, x);
int main() {
    int a;
    scanf("%d", &a);
    dbg(a);
    return 0;
}
