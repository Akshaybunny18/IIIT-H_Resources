#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f;
int check(char *arr,int n){
	int k=0;
	for(int i=0;i<n;i++){
		if(arr[i]=='(') k++;
		if(arr[i]==')') k--;
		if(k<0) return 1;
	}
	return k;
}

void per(int n,char *arr,int m){
	if(m==n ){
		if(check(arr,n)==0 && f==0){
			printf("%s\n",arr);
		}
		else if(f==2){
			
			printf("%s\n",arr);
		}
		else if(f==1 && check(arr,n)!=0){
			printf("%s\n",arr);
		}
		return;
	}
	arr[m]='(';
	per(n,arr,m+1);
	arr[m]=')';
	per(n,arr,m+1);
}
int main(){
	int x;
	scanf("%d %d",&x,&f);
	int n=2*x;
	char arr[n];
	arr[n]='\0';
	per(n,arr,0);
	return 0;
}
