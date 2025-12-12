#include <stdio.h>
#include <stdlib.h>
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
    int x,l;
    scanf("%d %d",&x,&l);
    int arr1[x];
    int arr2[x];
    for(int i=0;i<x;i++) scanf("%d %d",&arr1[i],&arr2[i]);
    //merg_sort(arr1,0,x-1);
    //merg_sort(arr2,0,x-1);
    int u=1;
    while(u<x){
        for (int a = 0; a < x; a += 3 * u) {
            merge(arr1, a, u, x);
        }
        u *= 3;
    }
    u=1;
    while(u<x){
        for (int a = 0; a < x; a += 3 * u) {
            merge(arr2, a, u, x);
        }
        u *= 3;
    }
    int max=0;
    int m=arr2[0];
    //count number 102
    for(int i=0;i<x;i++){
        if(arr1[i]>=m){
            m=arr2[i];
            max++;
        }
    }
    // printf("\n");
    // for(int i=0;i<x;i++){aa
    //     printf("%d %d\n",arr1[i],arr2[i]);
    // }
    printf("%d\n",max+1);
}
