#include <stdio.h>
#include <stdlib.h>
int main(){
    int x,c=0,k,y;
    scanf("%d",&x);
    int *a=(int*)malloc(sizeof(int)*x);
    for(int i=x-1;i>=0;i--){
        k=0;
        for(int j=0;j<x;j++){
           // k=0;
            if(i==x-1){
                scanf("%d",&a[j]);
                if(a[j]>=10){
                    c+=1;
                }
            }
            if(a[j]<=a[i]){
                k+=1;
            }
        }
        if(k>=a[i]){
            //y=k;
            printf("%d %d",a[i],c);
            free(a);
            return 0;
        }
    }
    printf("0 %d",c);
  //  printf("%d %d",y,c);
}
