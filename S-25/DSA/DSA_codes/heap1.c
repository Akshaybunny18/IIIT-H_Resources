#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void heapup(int *arr,int n){
    int i=n;
    while(i>1 && arr[i]>arr[i/2]){
        int temp=arr[i];
        arr[i]=arr[i/2];
        arr[i/2]=temp;
        i=i/2;
    }
}

void heapdown(int *arr,int n,int i){
    while(2*i<=n){
        int lar=i,l=2*i,r=2*i+1;
        if(arr[lar]<arr[l]) lar =l;
        if(r<=n && arr[lar]<arr[r]) lar =r;
        if(lar==i) break;
        int temp = arr[i];
        arr[i]=arr[lar];
        arr[lar]=temp;
        i = lar;
    }

}

void buildheap(int *arr,int n){
    for(int i=n/2;i>=1;i--){
        heapdown(arr,n,i);
    }
}


int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1];
    int arr[0]=INT_MAX;
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
}