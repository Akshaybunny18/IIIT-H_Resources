#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
long long int po(long long x,int n){
    if(n==0) return 1;
    else if(n==1) return x;
    if(n%2==0){
        return po(x*x,n/2);
    }
    return x*po(x*x,n/2);
}

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


void heapd(int *arr,int p){
    int i=1;
    while(1){
        if(2*i<=p && 2*i+1<=p){
            int t;
            if(arr[2*i]>arr[2*i+1]){
                // ind = 2*i;
                t=arr[2*i];
                if(arr[i]<arr[2*i]){
                    arr[2*i]=arr[i];
                    arr[i]=t;
                    i=2*i;
                }
                else {
                    break;
                }
            }
            else{
                // ind = 2*i+1;
                t=arr[2*i+1];
                if(arr[i]<arr[2*i+1]){
                    arr[2*i+1]=arr[i];
                    arr[i]=t;
                    i=2*i+1;
                }
                else{
                    break;
                }
            }
        }
        else if(2*i<=p){
            if(arr[i]<arr[2*i]){
                int t=arr[2*i];
                arr[2*i]=arr[i];
                arr[i]=t;
                i=2*i;
            }
            else{
                break;
            }
        }
        else {
            break;
        }
    }
}

void heapin(int * arr,int p){
    while(1){
        if(p==1) return;
        if(arr[p]>arr[p/2]){
            int t=arr[p];
            arr[p]=arr[p/2];
            arr[p/2]=t;
            p=p/2;
        }
        else break;
    }
}


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n+1];
    arr[0]=INT_MAX;
    int i=0;
    while(i<n){
        scanf("%d",&arr[++i]);
        heapin(arr,i);
    }
    // printf("%d",pow(2,9));
    // qsort(arr,n,sizeof(int),cmp);
    long long int sum=0;
    while(m--){
        arr[1]/=2;
        heapd(arr,n);
    }
    // for(int i=n-1;i>=0;i--){

    // }
    for(int i=1;i<=n;i++){
        sum+=arr[i];
    }


    printf("%lld\n",sum);
}