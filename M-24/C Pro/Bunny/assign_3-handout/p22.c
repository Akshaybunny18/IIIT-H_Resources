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
    }
     for(int i=0;i<b;i++){
        for(int j=0;j<b;j++){
            if(a[j]>=i){
                n+=1;
            }
        }
        if(i<=n){
            y=n;
        }
        n=0;
     }
     printf("%d %d",y,c);
     free(a);
    return 0;
} 
