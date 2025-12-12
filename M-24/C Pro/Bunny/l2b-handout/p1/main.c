/* 
 * Lab 1 Problem 1
 */
#include<stdio.h>

int main()
{
int m,p,e,pn;
scanf("%d %d %d",&m,&p,&e);
pn=m%p;
pn=pn%e;
printf("%d",pn);   
    return 0;
} 
