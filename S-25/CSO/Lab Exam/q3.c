#include <stdio.h>
#include <stdlib.h>

long long score(char* str);
// {
//     long long sc=0;
//     for(long long i=1;str[i]!='\0';i++){
//         char a=str[i-1];
//         char b=str[i];
//         long long diff=abs(a-b);
//         sc+=diff;
//     }
//     return sc;
// }

int main() {
    char str[101];
    scanf("%s",str);
    printf("%lld\n",score(str));
    return 0;
}