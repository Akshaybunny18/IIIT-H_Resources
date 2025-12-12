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
    for(int i=b;i>0;i--){
        
            if(a[b-i]>=i){
                printf("%d %d",i,c);
                n=1;
                return 0;
            }
        
    }
    if(n==0){
        printf("0 %d",c);
    }
    return 0;
}