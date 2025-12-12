#include <stdio.h>
int main(){
    int n;
    int j=0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i=1;i<n;i++){
        int key=arr[i];
        for(j=i-1;j>=0 && key<arr[j];j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}