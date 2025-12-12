#include <stdio.h>
#define MOD 1000000007
int dom(int hie, int a, int b, int bi) {
    if (hie == bi) {
        return b;
    }
    return dom(hie - 1, b, (a + b) % MOD, bi);
}
int main() {
    int hie;
    scanf("%d", &hie);
    printf("%d\n", dom(hie, 0, 1, 1));
    return 0;
}