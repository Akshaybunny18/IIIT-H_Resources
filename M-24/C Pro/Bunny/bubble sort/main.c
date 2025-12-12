#include <stdio.h>
void main(){
	int a[]= {9,8,7,6,5,4},temp;
	for (int i=0;i<6-1;i++){
		int body=0;
		for(int j=0;j<6-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				body=1;
			}
		}
	if (body = 0){break;}
	}
		for(int o=0;o<6;o++){
			printf("%d ",a[o]);
		}
}
