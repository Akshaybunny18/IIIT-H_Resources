#include <stdio.h>
#include <stdlib.h>
#define ll long long

int fun(ll n, char* str, char* stack);
// {
//     ll top=-1;
//     for(ll i=0;i<n;i++){
//         if(str[i]=='('){
//             top++;
//             stack[top]='(';
//         }
//         else if(str[i]=='['){
//             top++;
//             stack[top]='[';
//         }
//         else if(str[i]=='{'){
//             top++;
//             stack[top]='{';
//         }
//         else if(str[i]==')'){
//             if(top==-1 || stack[top]!='('){
//                 return 0;
//             }
//             top--;
//         }
//         else if(str[i]==']'){
//             if(top==-1 || stack[top]!='['){
//                 return 0;
//             }
//             top--;
//         }
//         else if(str[i]=='}'){
//             if(top==-1 || stack[top]!='{'){
//                 return 0;
//             }
//             top--;
//         }
//     }
//     return 1;
// }

int main() {
    ll n;
    scanf("%lld", &n);
    char* str=(char*)malloc((n+1)*sizeof(char));
    scanf("%s", str);
    char* stack=(char*)malloc((n+1)*sizeof(char));
    printf("%s\n", fun(n, str, stack)==1?"BALANCED":"NOT BALANCED");
    return 0;
}