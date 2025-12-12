#include <stdio.h>
#include <stdlib.h>

void function(long long int n, long long int* arr);
// {
//     for(long long int i=0;i<n;i++){
//         arr[i]=i+1;
//         if((i+1)%2==0){
//             arr[i]=-1;
//         }
//         if((i+1)%7==0){
//             arr[i]=-2;
//         }
//         if((i+1)%14==0){
//             arr[i]=-3;
//         }
//     }
// }

int main() {
    long long int n;
    scanf("%d",&n);
    long long int arr[n];
    function(n,arr);
    for(long long int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}