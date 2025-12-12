/* 
 * Lab 2 Problem 2
 */
#include<stdio.h>
int x;
int fac(x){int sum=1;
for (int i=1;i<=x;i++){
sum=sum*i;}
if (x==0){return 1;}
return sum;}
int main()
{int a,b;
scanf("%d %d",&a,&b);  
int y=fac(a)/(fac(a-b)*fac(b));
printf("%d",y);
    return 0;
}
