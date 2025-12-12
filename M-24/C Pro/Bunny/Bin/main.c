#include <stdio.h>
#include <math.h>
int main()
{ 	int d,i=0,bin,n;
	scanf("%d",&n);
	for(i;n!=0;i++)
 {	 d=n%2;
	 bin=d*pow(10,i)+bin;
	 n=n/2;}
	printf("%d",bin);
        return 0;}
