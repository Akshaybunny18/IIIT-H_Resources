/* 
 * Lab 3D Problem 3
 */
#include<stdio.h>

int main(){
	int a,b=0,c,n=0;
	scanf("%d",&a);
	int l[a];
	for (int i=0;i<a;i++){
		scanf("%d",&l[i]);
	}
	scanf("%d",&c);
	for (int i=0;i<a;i++){
		for(int j=i;j<a;j++){
			b=l[j]+b;
			if(l[i]==c){
			continue ;}
			if(b==c){
			n=1;
			printf("%d %d",i,j);
			break ;}
		}
		b=0;
		if(n==1){break;}
	}
	if(n==0){
	printf("-1 -1");}
    
    // write your code here



    
    return 0;
} 
