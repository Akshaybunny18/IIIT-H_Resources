#include <stdio.h>
void main (){
int c=0;
int k=0,u;
	int a[]={9,7,6,5,3,4,2,1};
	for (int i=0;i<8;i++){
    	int o =a[i];
    	c=0;
		for (k=i;k<(8);k++){
		u=a[k];
			if (o<u){ c=c+1;}	
		}
		if (c==0){
		printf("%d\t",o);}
	}
}
