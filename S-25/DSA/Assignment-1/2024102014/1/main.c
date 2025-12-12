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
void merge(int *l, int start, int size, int n) {
    int *li = (int *)malloc(sizeof(int) * (3 * size));
    int k = 0, i = start, j = start + size, m = start + 2 * size;

    int end_i = (start + size - 1 < n - 1) ? start + size - 1 : n - 1;
    int end_j = (start + 2 * size - 1 < n - 1) ? start + 2 * size - 1 : n - 1;
    int end_m = (start + 3 * size - 1 < n - 1) ? start + 3 * size - 1 : n - 1;

    while (i <= end_i && j <= end_j && m <= end_m) {
        if (l[i] <= l[j] && l[i] <= l[m]) {
            li[k++] = l[i++];
        } else if (l[j] <= l[i] && l[j] <= l[m]) {
            li[k++] = l[j++];
        } else {
            li[k++] = l[m++];
        }
    }

    while (i <= end_i && j <= end_j) {
        li[k++] = (l[i] <= l[j]) ? l[i++] : l[j++];
    }
    while (j <= end_j && m <= end_m) {
        li[k++] = (l[j] <= l[m]) ? l[j++] : l[m++];
    }
    while (i <= end_i && m <= end_m) {
        li[k++] = (l[i] <= l[m]) ? l[i++] : l[m++];
    }

    while (i <= end_i) li[k++] = l[i++];
    while (j <= end_j) li[k++] = l[j++];
    while (m <= end_m) li[k++] = l[m++];

    for (int a = 0; a < k; a++) {
        l[start + a] = li[a];
    }

    free(li);
}
int main(){
    int x;
    scanf("%d",&x);
    int arr[x];
    for(int i=0;i<x;i++) scanf("%d",&arr[i]);
    int target ;
    scanf("%d",&target);
    //merg_sort(arr,0,x-1);
    int u=1;
    while(u<x){
        for (int a = 0; a < x; a += 3 * u) {
            merge(arr, a, u, x);
        }
        u *= 3;
    }
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
