/* 
 * Assignment 3 Problem 1
 */
#include <stdio.h>
int main(){
	int a,b,p;
	char c;
	scanf("%d %d",&a,&b);
	int x[500],y[500],sum[1001]={0},k,t=0;
	for(int i=0;i<a;i++){
		scanf(" %c",&c);
		x[i]=(int)c-48;
	}
	for(int i=0;i<b;i++){
		scanf(" %c",&c);
		y[i]=(int)c-48;
	}
	for(int i=0;i<3;i++){
	//	printf("%d %d ",x[i],y[i]);
	}
	for(int i=1;i<=a;i++){
		//t=i-1;
		for(int j=1;j<=b;j++){
			p=x[a-i]*y[b-j];
			t=i-1+j-1;
			sum[t]=p+sum[t];
			sum[t+1]=sum[t]/10+sum[t+1];
			sum[t]=sum[t]%10;
				//sum[k+1]=p+sum[k+1];
			
		}
	}
	int q;
	/*for(int i=1000;i>=0;i--){
		if(sum[i]!=0){
			q=i;
		}
	for(int i=q;i>=0;i--){
		printf("%d",sum[q]);
	}
	}*/
	if(sum[a+b-1]==0){
		q=a+b-2;
	}
	else if(sum[a+b-1]==0 && sum[a+b-2]==0){
		printf("0");
		return 0;
	}
	else{
		q=a+b-1;
	}
	for(int i=q;i>=0;i--){
		printf("%d",sum[i]);
	}
	return 0;
}
