#include <stdio.h>
#include <stdlib.h>


int compare_ints( const void* a, const void* b ) {
    int* arg1 = (int*) a;
    int* arg2 = (int*) b;
    if( *arg1 < *arg2 ) return -1;
    else if( *arg1 == *arg2 ) return 0;
    else return 1;
}

void heapup(long long int *arr,int n){
    int i=n;
    while(i>1 && arr[i]<arr[i/2]){
        long long int temp=arr[i];
        arr[i]=arr[i/2];
        arr[i/2]=temp;
        i=i/2;
    }   
}


void heapdown(long long int *arr,int n,int i){
    // int lar=i,l=2*i,r=2*i+1;
    while(2*i<=n){
        int lar=i,l=2*i,r=2*i+1;
        if(arr[lar]>arr[l]) lar=l;
        if(2*i+1<=n && arr[lar]>arr[r]) lar=r;
        if(lar==i) break;
        long long int temp=arr[i];
        arr[i]=arr[lar];
        arr[lar]=temp;
        i=lar;
    }

}


void buildheap(long long int *arr,int n){
    for(int i=n/2;i>=1;i--){
        heapdown(arr,n,i);
    }
}



int main(){
    int n;
    scanf("%d",&n);
    if(n==0 ){ printf("0");
    return 0;}
    long long int arr[n+1];
    for(int i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
        // heapup(arr,i);
    }
    long long int sum=0;
    buildheap(arr,n);
    // qsort(arr,n,sizeof(long long int),compare_ints);
    // printf("%d\n",n);
    // for(int i=0;i<n;i++){
    //     printf("%d ",arr[i+1]);
    // }
    // printf("\n");
    int k=n;
    while(n!=1){
        long long int a,b;
        a=arr[1];
        arr[1]=arr[n--];
        heapdown(arr,n,1);
        b=arr[1];
        arr[1]=arr[n--];
        heapdown(arr,n,1);
        // long long int h=a+b;
        if(n+1<=k)arr[++n]=a+b;
        heapup(arr,n);
        sum=sum+a+b;
    }
    printf("%lld\n",sum);
}