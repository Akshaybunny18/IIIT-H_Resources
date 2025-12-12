	/* 
 * Lab 3 Problem 1
 */
#include<stdio.h>

int main(){
	int n,x;float sum=0;char g;
	scanf("%d %c",&n,&g);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		sum=sum+x;
	}
	int k=g;
	float gr=(sum/n)*100;
	//if(k==70){
	//	printf("%c",k);
//	}
	if(k==70){
		printf("F");
	}
	else{
	if(gr<85 && gr>=75){
		k=k+1;if(k>68){
			k=68;
		}
	}
	else if(gr<75 && gr>65){
		k=k+2;
		if(k>68){
			k=68;
		}

	}
	else if(gr<=65){
		k=70;
	}
	if (k==68){
		printf("D");
	}
	else if(k>68){
		printf("F");
	}
	else{
		printf("%c",k);
	}}
    return 0;
}
