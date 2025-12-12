/* 
 * Assignment 1 Problem 2
 */
#include <stdio.h>
int main()
{
long int m,n;
scanf("%ld %ld",&m,&n);
if (n%2==0 && (m-1)%4==0 && (m-1)<=(2*n))
    {printf("YES");}
else if (n%2!=0 && (m-1)%4==2 && (m-1)<=(2*n)) 
    {printf("YES");}
else 
    {printf("NO");}
return 0 ;
}
