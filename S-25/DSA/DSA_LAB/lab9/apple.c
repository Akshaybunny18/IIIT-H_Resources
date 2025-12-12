#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void heapup(int *arr,int n){
    int i=n;
    while(i>1 && arr[i]<arr[i/2]){
        int temp=arr[i];
        arr[i]=arr[i/2];
        arr[i/2]=temp;
        i=i/2;
    }
}

void heapdown(int *arr,int n,int i){
    while(2*i<=n){
        int lar=i,l=2*i,r=2*i+1;
        if(arr[lar]>arr[l]) lar =l;
        if(r<=n && arr[lar]>arr[r]) lar =r;
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
    int n,m;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    int b[m+1];
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        if (0)b[i]=0;
        else b[i]+=i;
    }
    // for(int i=1;i<=m;i++){
    //     b[i]+=i;  
    // }
    int c[n+m+1];
    for(int i=0;i<n;i++){
        c[i+1]=a[i];
    }
    // for(int i=0;i<m;i++){
    //     c[n+i+1]=b[i];
    // }
    c[0]=INT_MIN;
    buildheap(c,n);
    int count =0;
    int k=n;
    int i=1;
    c[++k]=b[1];
    heapup(c,k);
    // for(int i=1;i<=k;i++){
    //     // printf("%d ",c[i]);
    // }
    while(k>=1){
        if(c[1]>i){
            // printf("%d\n",c[1]);
            count++;
            c[1]=c[k--];
            heapdown(c,k,1);
            i++;
            if(i<=m) {
                c[++k]=b[i];
                heapup(c,k);
            }
        }
        else{   
            c[1]=c[k--];
            heapdown(c,k,1);
        }
    }
    while(i<=m){
        if(b[i]>i) count++;
        // else break;
        // printf("%d\n",b[i]);
        i++;
    }
    printf("%d",count);
}
