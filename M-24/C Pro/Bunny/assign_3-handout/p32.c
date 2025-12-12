#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b,k=2;
    scanf("%d %d",&a,&b);
    int **inp=(int**)malloc(b*sizeof(int*));
    for (int i=0;i<b;i++){
        int inp[i]=(int*)malloc(2*sizeof(int*));
    }
    
    for(int i=0;i<b;i++){
        scanf("%d %d",inp[i][j],inp[i][j+1]);
        if(inp[i][j]==1){
            int inp[i]=(int*)realloc(inp[i],3*sizeof(int*));
            scanf("%d",inp[i][j+2]);
        }
    }





    
    
}