#include <stdio.h>
#include <stdlib.h>
int min(int a,int b){
    if(a<b) return a;
    else return b;
}
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
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
    int arr[x];
    for(int i=0;i<x;i++) scanf("%d",&arr[i]);
    int target ;
    scanf("%d",&target);
    merg_sort(arr,0,x-1);
    int diff=abs(arr[0]+arr[1]-target);
    int i=0,j=x-1;
    int n1=arr[0],n2=arr[1];
    while(i<j){
        int sum=arr[i]+arr[j];
        int cdiff=abs(sum-target);
        if(abs(arr[i]+arr[j]-target)<diff){
            n1=min(arr[i],arr[j]);
            n2=max(arr[i],arr[j]);
            diff=abs(arr[i]+arr[j]-target);
        }
        else if(abs(arr[i]+arr[j]-target)==diff){
            if(abs(arr[i]-arr[j])<abs(n1-n2)){
                n1=min(arr[i],arr[j]);
                n2=max(arr[i],arr[j]);
            }
            else if(min(arr[i],arr[j])>n1){
                n1=min(arr[i],arr[j]);
                n2=max(arr[i],arr[j]);
            }
        }
        if(arr[j]>=target){
            j--;
        }
        else if(arr[j]<target){
            if(arr[j]+arr[i]<=target){
                i++;
            }
            else if(arr[j]+arr[i]>target){
                j--;
            }
        }
    }
    printf("%d %d",n1,n2);
    return 0;
}