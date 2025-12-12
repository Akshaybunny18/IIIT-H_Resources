/* 
 * Assignment 1 Problem 1
 */
#include<stdio.h>

int main()
{
long int a,b,c,d,co=0;
scanf("%ld %ld %ld %ld",&a,&b,&c,&d);
if (a==b){co+=1;}
if (a==c){co+=1;}
if (a==d){co+=1;}
if (b==c){co+=1;}
if (b==d){co+=1;}
if (c==d){co+=1;}
else ;
if (co==0 || co==1){printf("%ld",co);}
else if (co==6){printf("%ld",co-3);}
else {printf("%ld",co-1);}    
    return 0;
} 
