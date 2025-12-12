/* 
 * Lab 3 Wednesday Batch Problem 3
 */
#include<stdio.h>

int main(){
	int c=0;
	int k=0,u,n;
	scanf("%d",&n);
	int a[n],o;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=0;i<n;i++){
    	c=0;
		for (k=i+1;k<(n);k++){
			if (a[i]<=a[k]){
				c=c+1;
			}
		}
		if (c==0){
			printf("%d ",a[i]);
		}
	}
    return 0;
}
