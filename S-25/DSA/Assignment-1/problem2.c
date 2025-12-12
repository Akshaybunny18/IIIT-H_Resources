#include <stdio.h>
#include <stdlib.h>
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
    int x,l;
    scanf("%d %d",&x,&l);
    int arr1[x];
    int arr2[x];
    for(int i=0;i<x;i++) scanf("%d %d",&arr1[i],&arr2[i]);
    merg_sort(arr1,0,x-1);
    merg_sort(arr2,0,x-1);
    int max=0;
    int m=arr2[0];
    //count number 102
    for(int i=0;i<x;i++){
        if(arr1[i]>=m){
            m=arr2[i];
            max++;
        }
    }
    // printf("\n");
    // for(int i=0;i<x;i++){aa
    //     printf("%d %d\n",arr1[i],arr2[i]);
    // }
    printf("%d\n",max+1);
}