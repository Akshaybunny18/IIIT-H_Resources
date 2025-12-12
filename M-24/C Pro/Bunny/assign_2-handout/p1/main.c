/* 
 * Assignment 2 Problem 1
 */
#include<stdio.h>

int main()
{
long int a,b=0,c=1,s;
scanf("%ld",&a);
printf("0 1 ");
for (long int i=0;i<a-2;i++){
	s=b+c;
	printf("%ld ",s);
	b=c;
	c=s;
}
    // write your code here




    
    return 0;
} 
