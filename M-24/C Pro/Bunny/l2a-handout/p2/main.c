/* 
 * Lab 1 Problem 2
 */
#include<stdio.h>

int main()
{
    // write your code here
long long int p,q,r,s;
scanf("%lld",&p);
s=0;
for  (q=0;q<p;q++)
{
scanf("%lld",&r);
if (r==0)
{
break;
}
else
{
s=s+r;

}
}

printf("%lld",s);
   return 0;
}
