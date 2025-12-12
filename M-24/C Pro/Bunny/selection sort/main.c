#include <stdio.h>
void main(){
	int a[]={7,6,5,4,3,2},min,temp;
	for (int i=0;i<6;i++){
		min=i;
		for (int j=i+1;j<6;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	for(int o=0;o<6;o++){
		printf("%d ",a[o]);
	}
}
