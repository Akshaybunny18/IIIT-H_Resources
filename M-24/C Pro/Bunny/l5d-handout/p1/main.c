/*
 Lab 5D problem 1
*/
#include<stdio.h>

int main()
{
    // write your code here
	int a;
	long long int x,y,max=0,p=0,temp;
	scanf("%d",&a);
	long long int arr[a];
	for(int i=0;i<a;i++){
		scanf("%lld %lld",&x,&y);
		arr[i]=1;
		if(y<x){
			temp=y;
			y=x;
			x=temp;
		}
		//p=5;
		while(1){
			if(x==y){
				break;}
			if(y%x==0){
				arr[i]=x;
				break;
			}
			p=y%x;
			y=x;
			x=p;
			//printf("%lld",arr[i]);
			//printf("%lld",p);
		}
		
	}
	for(int i=0;i<a;i++){
		if(arr[i]>max){
			max=arr[i];
		}
		//printf("%lld",arr[i]);
	}
	printf("%lld",max);
	

    
    return 0;
} 
