/* 
 * Assignment 3 Problem 1
 */
#include<stdio.h>
#include<stdlib.h>

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    char *x=(char*)malloc((a+1)* sizeof(char));
    char *y=(char*)malloc((b+1)* sizeof(char));
   // x[a]='\0' , x[b]='\0';
    int num1= (int *)malloc(a* sizeof(int));
    int num2= (int *)malloc(b* sizeof(int));
        scanf("%s %s",x,y);    
    int num= (int *)malloc((b+a) * sizeof(int));
    num1=x;
    num2=y;
    num=num1*num2;
    printf("%d",num);
    // write your code here   
    return 0;
}

