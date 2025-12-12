#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void heapd(int *arr,int p){
    int i=1;
    while(1){
        if(2*i<=p && 2*i+1<=p){
            int t;
            if(arr[2*i]<arr[2*i+1]){
                // ind = 2*i;
                t=arr[2*i];
                if(arr[i]>arr[2*i]){
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
                if(arr[i]>arr[2*i+1]){
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
            if(arr[i]>arr[2*i]){
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
        if(arr[p]<arr[p/2]){
            int t=arr[p];
            arr[p]=arr[p/2];
            arr[p/2]=t;
            p=p/2;
        }
        else break;
    }
}

// if(p==1) return ;
//     if(arr[p]<arr[p/2]){
//         int temp=arr[p];
//         arr[p]=arr[p/2];
//         arr[p/2]=temp;
//     }
//     else if(arr[p-1]<arr[(p-1)/2]){
//         int temp=arr[p-1];
//         arr[p-1]=arr[(p-1)/2];
//         arr[(p-1)/2]=temp;
//     }
//     heapify(arr,p/2);
//     // heapify(arr,(p-1)/2);

int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1];
    arr[0]=INT_MIN;
    int k=0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x==1){
            scanf("%d",&arr[++k]);
            heapin(arr,k);
        }
        else if(x==2){
            arr[1]=arr[k--];
            heapd(arr,k);
        }
        else if(x==3){
            printf("%d\n",arr[1]);
        }
    }
    return 0;
}