#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    FILE * ptr;
    char y[100];
    int x=0;
    int i=0;
    int *a = (int *)malloc(1*sizeof(int));
    ptr = fopen("number.txt","r");
    while(fgets(y,100,ptr)!=NULL){
        x++;
        a[i]=strlen(y);
        a=(int*)realloc(a,(x+1)*sizeof(int));
        i++;
    }
    printf("%d\n",x);
for(int m=0;m<i;m++){
    printf("%d %d\n",m+1,a[m]-1);   
}
free(a);
fclose(ptr);
    return 0;
}
