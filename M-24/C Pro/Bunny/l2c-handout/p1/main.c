#include<stdio.h>
#include <string.h>
int main(){
int a,b,c,d,num,co=0;
scanf("%d",&num);
while (num>0){
num+=1;
int hi=num;
a=hi%10;hi=hi/10;b=hi%10;hi=hi/10;c=hi%10;hi=hi/10;d=hi;
co+=1;
if ((a!=b)&&(a!=c)&&(a!=d)&&(b!=c)&&(b!=d)&&(c!=d))
{printf("%d %d",num,co);
break;}
}}
