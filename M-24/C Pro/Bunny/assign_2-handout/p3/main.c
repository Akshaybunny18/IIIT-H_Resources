/* 
 * Assignment 2 Problem 3
 */
#include<stdio.h>

int main()
{
int r=0,k;
int a,b;
scanf("%d %d",&a,&b);
for (int i=a;i<=b;i++){
	k=i;
	for (int j=1;k>0;j++){
		r=(k%10)+r;
		k=k/10;	
	}
	if (i%r==0){
		printf("%d ",i);
	}
	r=0;
}

    // write your code here




    
    return 0;
} 
