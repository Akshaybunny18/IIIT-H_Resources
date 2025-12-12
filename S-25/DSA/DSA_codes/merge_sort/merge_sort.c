#include <stdio.h>
void merge(int arr[], int left, int mid, int right){
    //akshay
    int n1 = right-left+1;
    int ar[n1];
    int i=left;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            ar[k]=arr[i];
            i++;
        }
        else{
            ar[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        ar[k]=arr[i];
        i++;
        k++;
    }
    while(j<=right){
        ar[k]=arr[j];
        j++;
        k++;
    }
    for(int q=0;q<k;q++){
        arr[left+q]=ar[q];
    }
}
void merg_sort( int arr[], int left, int right){
    if(left!=right){ 
        int mid = (left+right)/2;
        merg_sort(arr,left,mid); 
        merg_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main(){
	int x;
    scanf("%d",&x);
    int y[x];
    for (int i=0;i<x;i++){
        scanf("%d",&y[i]);
    }
    merg_sort(y,0,x-1);
    for (int i=0;i<x;i++){
        printf("%d ",y[i]);
    }
}
