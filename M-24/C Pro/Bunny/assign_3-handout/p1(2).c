/* 
 * Assignment 3 Problem 1
 */
#include<stdio.h>
#include<stdlib.h>

int main(){
    int a,b,num;
    scanf("%d %d",&a,&b);
    char x[a+1],y[b+1];
    for(int i=0;i<a;i++){
        scanf(" %c",&x[i]);
    }
    x[a]='\0';
    for(int i=0;i<b;i++){
        scanf(" %c",&y[i]);
    }
    x[b]='\0';
    num=atoi(x);
    num*=atoi(y);
    printf("%d",num);
    // write your code here   
    return 0;
} 
