#include <stdio.h>
void main (){
	int arr[]={1,9,7,6,5,0},key,j;
	for(int i=1;i<6;i++){
		key=arr[i];
		j=i-1;
		while(j<=0 && key<arr[j]){
			arr[j+1]=arr[j];
			j--;
		}
	}
	for (int i=0;i<6;i++){
		printf("%d ",arr[i]);
	}
}
