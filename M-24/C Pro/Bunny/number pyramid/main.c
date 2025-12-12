#include <stdio.h>
void main(){
	int x,j=1;
	scanf("%d",&x);
	for(int s=x,i=1;i<=x;i++,s--){
		if (s==x || s== x-2 || s== x-3 || s== x-1){
				printf(" ");
			}
	for(int k=s;k>0;k--){
		printf("  ");
	}
		for(int l=0;l<i;j++,l++){
			printf("%d  ",j);
		}
		printf("\n");
	}
}
