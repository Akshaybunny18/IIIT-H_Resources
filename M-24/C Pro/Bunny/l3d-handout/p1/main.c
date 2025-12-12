/* 
 * Lab 3D Problem 1
 */
#include<stdio.h>

int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int m[a*b],temp;
	for (int i=0;i<a*b;i++){
		scanf("%d",&m[i]);
	}
	for(int k=0;k<c;k++){
		temp=m[a*b-1];
		for (int j=a*b-2;j>=0;j--){
			m[j+1]=m[j];
		}
		m[0]=temp;
	}
	for(int i=0;i<a*b;i++){
		printf("%d ",m[i]);
		if((i+1)%b==0){
			printf("\n");}

	}
		
    // write your code here




    
    return 0;
} 
