#include<stdio.h>
long int po(long int l, int m){
	long int o=1;
	for(int k=0;k<m;k++){
		o=o*l;
	}
	return o;
}/*
void num(int n){
	if(n>1){
		num(n/2);
	}
	printf("%d",n%2);
}*/
int main(){
	long int z,a[20],b[20],x,sum1=0,sum2=0,temp,j,d,bin=0;
	scanf("%ld",&z);
	for(int i=0;i<20;i++){
		scanf("%ld",&a[i]);
		if (sum1<a[i]){
			sum1=a[i];
		}
	}
	for(int i=0;i<20;i++){
		scanf("%ld",&b[i]);
		if(sum2<b[i]){
			sum2=b[i];
		}
	}
	if (sum1>(sum2/2)){
		x=sum1+z;
	}
	else {
		x=(sum2/2)+z;
	}
	for(int i=0;x>0;i++){
		 d=x%2;
		 bin=d*po(10,i)+bin;		
		 x=x/2;
	}
	//num(x);
	printf("%ld",bin);	
    return 0;
}
