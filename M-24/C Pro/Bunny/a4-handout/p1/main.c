/* 
 * Assignment 4 Problem 1
 */
#include<stdio.h>

int main()
{
    // write your code here
    long long int ans,a=0,b=1,hie;
    int c=0;
    scanf("%lld",&hie);
    while(c!=hie){
        ans=(a+b)%1000000007;
        a=b;
        b=ans;
        c++;
    }
    printf("%lld",ans); 
    return 0;
} 
