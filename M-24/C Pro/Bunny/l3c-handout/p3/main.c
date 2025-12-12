/* 
 * Lab 2 Problem 3
 */
#include<stdio.h>

int main(){
	int n,x,i=1,k;
	scanf("%d %d",&n,&x);
	while(1){
		k=n*i;
		printf("%d ",k%x);
		i++;
		if((k%x)==0){
			break;
		}
	}
    return 0;
} 
