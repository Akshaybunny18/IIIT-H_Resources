#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int target(int num, int sum, int mul,int tar){
    if(num==tar){
        printf("Yes\n");
        exit(0);
    }
    else if(num>tar){
        return 0;
    }
    target(num+sum,sum,mul,tar);
    target(num*mul,sum,mul,tar);
}

int main(){
    int a,b,c,d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int arr[a];
    for(int i=0;i<a;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<a;i++){
        int x=target(arr[i],c,d,b);
    }
    printf("No\n");
    return 0;
}