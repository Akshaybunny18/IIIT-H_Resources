/* 
 * Assignment 3 Problem 3
 */
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,m;
    scanf("%d %d", &n,&m);    
    int **ma = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        ma[i] = (int *)malloc(1 * sizeof(int));
        ma[i][0]=1;
    }
    int *arr=(int*)calloc(n,sizeof(int));
   // arr[m]={1}
    for(int i=0;i<m;i++){
        int r,t,y,c;
        scanf("%d %d",&r,&t);
        if(r==1){
            arr[t-1]++;
            scanf("%d",&y);
            c=arr[t-1]+1;
            ma[t-1] = (int*)realloc(ma[t-1],c*sizeof(int));
            ma[t-1][arr[t-1]]=y;
        }
        if(r==2){
            for(int v=0;v<=(arr[t-1]);v++){
                printf("%d ",ma[t-1][v]);
            }
            printf("\n");
        }
    }
   // return 0;
    for (int i = 0; i < n; i++) {
        free(ma[i]);  
    }
    free(ma);
    free(arr);
    return 0;
}
