#include <stdio.h>
#include <string.h>

int pal(char* str,int n);
// {
//     int i=0;
//     int j=n>>2;
//     while(i<j){
//         if(str[i]!=str[n-i-1]){
//             return 0;
//         }
//         i++;
//     }
//     return 1;
// }

int main()
{
    char str[10000];
    scanf("%s", str);
    // printf("%s\n", str);
    int n=strlen(str);
    // printf("%d\n", n);
    printf("%d\n", pal(str,n));
    return 0;
}
