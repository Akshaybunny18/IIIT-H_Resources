#include <stdio.h>
#include <stdlib.h>

void merge(long long int arr[], int left, int mid, int right){
    //akshay
    int n1 = right-left+1;
    long long int ar[n1];
    int i=left;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=right){
        if(arr[i]>arr[j]){
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
void merg_sort( long long int arr[], int left, int right){
    if(left<right){ 
        int mid = (left+right)/2;
        merg_sort(arr,left,mid); 
        merg_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}   

int main(){
    int n;
    scanf("%d",&n);
    long long int arr[n];
    long long int sum=0;
    for(int i=0;i<n;i++){
        long long int a,b;
        scanf("%lld %lld",&a,&b);
        sum+=(n*b)-a;
        arr[i]=a-b;
    }
    merg_sort(arr,0,n-1);
    //reverse
    // for(int i=0;i<n/2;i++){
    //     int temp=arr[i];
    //     arr[i]=arr[n-i-1];
    //     arr[n-i-1]=temp;
    // }
    // for(int i=0;i<n;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\n%d\n",sum);
    for(int i=1;i<=n;i++){
        sum+=arr[i-1]*i;
    }
    printf("%lld",sum);
    return 0;
}