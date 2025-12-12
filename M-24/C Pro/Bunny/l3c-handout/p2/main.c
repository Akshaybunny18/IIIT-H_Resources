/* 
 * Lab 3 Problem 2
 */
#include<stdio.h>

int main(){
	int a;
	scanf("%d",&a);
	int l[a],sum=0;
	for(int i=0 ;i<a;i++){
		scanf("%d",&l[i]);
		if(i%2==0){
			sum=sum+l[i];
		}
		else{
			sum=sum-l[i];
		}
	}
	printf("%d",sum);
    return 0;
} 
