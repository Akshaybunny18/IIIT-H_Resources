#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
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







int main(){
    int n;
    // node *root=NULL;
    scanf("%d",&n);
    int a[n][2];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i][0]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i][1]);
    }
    int arr[n];
    int i=0;
    int c=0;
    arr[0]=INT_MIN;
    arr[1]=a[0][1];
    i=1;
    while(i<n){
        if(a[i][0]<arr[1]){
            arr[1]=a[i][1];
            heapd(arr,i);
            i++;
            continue;
        }
        arr[++i]=a[i-1][1];
        heapin(arr,i);
        c++;
    }
    printf("%d",c);
    return 0;
}