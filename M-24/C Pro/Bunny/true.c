#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
	void p1(int* arr,int x,int a,int b,int m,int i,int j){
		if(m-1==x){
			if(a>=b){
				printf("true");
				exit(0);
			}
			return ;
		}
		if (j - 1 >= 0 && i + 1 < x) {
       		p1(arr, x, a + arr[j], b + arr[i], m + 2, i + 1, j - 1);
	   	}
	    if (j - 2 >= 0) {
	        p1(arr, x, a + arr[j], b + arr[j-1], m + 2, i, j - 2);
	    }
	    if (i + 2 < x) {
	        p1(arr, x, a + arr[i], b + arr[i+1], m + 2, i + 2, j);
	    }
	    if (i + 1 < x && j - 1 >= 0) {
	        p1(arr, x, a + arr[i], b + arr[j], m + 2, i + 1, j - 1);
	    }
	}

int main(){
	int x;
	scanf("%d",&x);
	int arr[x];
	for(int i=0;i<x;i++){
		scanf("%d",&arr[i]);
	}
	p1(arr,x,0,0,0,0,x-1);
	printf("false");
	return 0;
}
