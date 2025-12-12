/* 
 * Assignment 3 Problem 2
 */
#include<stdio.h>
#include<stdlib.h>

int main(){
    int b,c=0,y,n=0;
    scanf("%d",&b);
    int *a=(int*)malloc(sizeof(int)*b);
    for(int i=0;i<b;i++){
        scanf("%d",&a[i]);
        if(a[i]>=10){
            c+=1;
        }
        if(a[i]<=b-i && a[i]<=b){
            y=i;
            n=1;
        }
    }
    if(n!=1){
        printf("0 %d",c);
    }
    else{
        printf("%d %d",a[y],c);
    }
     free(a);
    return 0;
} 
