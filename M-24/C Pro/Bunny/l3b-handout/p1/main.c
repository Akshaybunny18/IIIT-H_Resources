/* 
 * Lab 3 Wednesday Batch Problem 1
 */
#include<stdio.h>
long int fac(long int k){
	long int b=1;
	for(long int i=1;i<=k;i++){
		b=b*i;
	}
	return b;
}
int main(){
	long int a,b,x;
	scanf("%ld %ld",&a,&b);
	x=fac(a)/(fac(a-b)*fac(b));
	printf("%ld",x);
    return 0;
}
