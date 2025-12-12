/* 
 * Assignment 4 Problem 3
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
    // write your code here
    int k,hi,j=0,temp,c=0,l=0,max=-1000000,maxi;
    scanf("%d",&k);
    int b[k];
	int o=k;
	int m=k-1;
	int *a =(int*)malloc(k*sizeof(int));
    for(int i=0;i<k;i++){
        scanf("%d",&a[i]);
    }
	for(int i=0;i<k;i++){
			if(a[i]<a[i+1]){
				break;
			}
			if(i==k-2){
				for(int i=k-1;i>=0;i--){
					printf("%d ",a[i]);
				}
				return 0;
			}
		}
	for(int i=0;i<k-1;i++){
		if(a[i]>a[i+1]){
			break;
		}
		if(i==k-2){
			for(int i=0;i<k;i++){
				printf("%d ",a[i]);
			}
			return 0;
		}
	}

	while(c!=k){
		l=0;
		int u=0;
		max=-1000000;
		for(int i=0;i<o;i++){
			if(max<a[i]){
				max=a[i];
				maxi=i;
			}
		}
		for(int i=0;i<o;i++){
			if(max==a[i]){
				u++;
			}
			if(u>1){
				printf("-1");
				return 0;
			}
		}
		for(int i=maxi;i<o-1;i++){
			a[i]=a[i+1];
		}
		a[m]=max;
		m--;
		c++;
		o--;
		for(int i=0;i<k;i++){
			if(a[i]<a[i+1]){
				break;
			}
			if(i==k-2){
				for(int i=k-1;i>=0;i--){
					printf("%d ",a[i]);
				}
				return 0;
			}
		}
		for(int i=0;i<k-1;i++){
			if(a[i]>a[i+1]){
				break;
			}
			if(i==k-2){
				for(int i=0;i<k;i++){
					printf("%d ",a[i]);
				}
				return 0;
			}
	}
	}
	for(int i=0;i<k;i++){
		printf("%d ",a[i]);
	}
	free(a);
	return 0;
} 
