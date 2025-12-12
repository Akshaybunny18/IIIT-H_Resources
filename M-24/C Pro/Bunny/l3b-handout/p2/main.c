/* 
 * Lab 3 Wednesday Batch Problem 2
 */
#include<stdio.h>

int main(){
	long int m,n,c=0,sum=0;
	scanf("%ld %ld",&n,&m);
	long int p[n],body=1;
	for(int i=0,o=-1;i<n;i++,o++){
		scanf("%ld",&p[i]);
		if(p[i]<0 || p[i]>(n-1)){ 
			body=0;
		}
		sum=sum+p[i];
		if(i==0){
			continue;
		}
		if((p[o]-p[o+1])==1 || p[o+1]-p[o]==1){
		body=0;
		}
	}
	if(sum!=((n*(n-1))/2)){
		body=0;
	}
	for(int i=0,j=n-1;i<n/2;j--,i++){
		if((p[i]+p[j])>=m){
		body=0;
		}
	}
	if(body==0){
		printf("NO");
	}
	else{
		printf("YES");
	}
    // write your code here
    return 0;
} 
