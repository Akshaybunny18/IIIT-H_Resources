/* 
 * Lab 1 Problem 3
 */
#include<stdio.h>

int main()
{long long int x=1,y;
scanf("%lld",&y);
for(int i=1;i<=y;i++){
x=x*i;
}
if (y==0){
	printf("1");
}
else {
	printf("%lld",x);
}
    // write youelser code here




    
    return 0;
} 
