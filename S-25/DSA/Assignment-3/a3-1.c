#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <limits.h>
void merge(int arr[][3], int l, int r) {
    if (l < r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = l + 2 * (r - l) / 3;

        merge(arr, l, mid1);
        merge(arr, mid1 + 1, mid2);
        merge(arr, mid2 + 1, r);

        int n1 = mid1 - l + 1;
        int n2 = mid2 - mid1;
        int n3 = r - mid2;

        int L[n1][3], M[n2][3], R[n3][3];

        for (int i = 0; i < n1; i++) {
            L[i][0] = arr[l + i][0];
            L[i][1] = arr[l + i][1];
            L[i][2] = arr[l + i][2];
        }
        for (int i = 0; i < n2; i++) {
            M[i][0] = arr[mid1 + 1 + i][0];
            M[i][1] = arr[mid1 + 1 + i][1];
            M[i][2] = arr[mid1 + 1 + i][2];
        }
        for (int i = 0; i < n3; i++) {
            R[i][0] = arr[mid2 + 1 + i][0];
            R[i][1] = arr[mid2 + 1 + i][1];
            R[i][2] = arr[mid2 + 1 + i][2];
        }

        int i = 0, j = 0, k = 0, x = l;
        while (i < n1 && j < n2 && k < n3) {
            if (L[i][2] < M[j][2] || (L[i][2] == M[j][2] && L[i][0] < M[j][0])) {
                if (L[i][2] < R[k][2] || (L[i][2] == R[k][2] && L[i][0] < R[k][0])) {
                    arr[x][0] = L[i][0];
                    arr[x][1] = L[i][1];
                    arr[x][2] = L[i][2];
                    i++;
                } else {
                    arr[x][0] = R[k][0];
                    arr[x][1] = R[k][1];
                    arr[x][2] = R[k][2];
                    k++;
                }
            } else {
                if (M[j][2] < R[k][2] || (M[j][2] == R[k][2] && M[j][0] < R[k][0])) {
                    arr[x][0] = M[j][0];
                    arr[x][1] = M[j][1];
                    arr[x][2] = M[j][2];
                    j++;
                } else {
                    arr[x][0] = R[k][0];
                    arr[x][1] = R[k][1];
                    arr[x][2] = R[k][2];
                    k++;
                }
            }
            x++;
        }

        while (i < n1 && j < n2) {
            if (L[i][2] < M[j][2] || (L[i][2] == M[j][2] && L[i][0] < M[j][0])) {
                arr[x][0] = L[i][0];
                arr[x][1] = L[i][1];
                arr[x][2] = L[i][2];
                i++;
            } else {
                arr[x][0] = M[j][0];
                arr[x][1] = M[j][1];
                arr[x][2] = M[j][2];
                j++;
            }
            x++;
        }

        while (j < n2 && k < n3) {
            if (M[j][2] < R[k][2] || (M[j][2] == R[k][2] && M[j][0] < R[k][0])) {
                arr[x][0] = M[j][0];
                arr[x][1] = M[j][1];
                arr[x][2] = M[j][2];
                j++;
            } else {
                arr[x][0] = R[k][0];
                arr[x][1] = R[k][1];
                arr[x][2] = R[k][2];
                k++;
            }
            x++;
        }

        while (i < n1 && k < n3) {
            if (L[i][2] < R[k][2] || (L[i][2] == R[k][2] && L[i][0] < R[k][0])) {
                arr[x][0] = L[i][0];
                arr[x][1] = L[i][1];
                arr[x][2] = L[i][2];
                i++;
            } else {
                arr[x][0] = R[k][0];
                arr[x][1] = R[k][1];
                arr[x][2] = R[k][2];
                k++;
            }
            x++;
        }

        while (i < n1) {
            arr[x][0] = L[i][0];
            arr[x][1] = L[i][1];
            arr[x][2] = L[i][2];
            i++;
            x++;
        }

        while (j < n2) {
            arr[x][0] = M[j][0];
            arr[x][1] = M[j][1];
            arr[x][2] = M[j][2];
            j++;
            x++;
        }

        while (k < n3) {
            arr[x][0] = R[k][0];
            arr[x][1] = R[k][1];
            arr[x][2] = R[k][2];
            k++;
            x++;
        }
    }
}

// int findClosestIndex(int arr[][4], int n, int target) {
//     int low = 0, high = n - 1,ans=-1;

//     while (low <= high) {
//         int mid = (low + high) / 2;

//         if (arr[mid][0] <= target){
//             ans = mid; 
//             low=mid+1;
//         }
//         else
//             high = mid - 1;
//     }
//     return ans;
// }

int main(){
    int n;
    scanf("%d",&n);
    int ar[n][3];
    for(int i=0;i<n;i++){
        scanf("%d %d",&ar[i][0],&ar[i][1]);
        ar[i][2]=ar[i][1]-ar[i][0]+1;
    }
    merge(ar,0,n-1);
    // for(int i=0;i<n;i++){
    //     printf("%d %d %d\n",ar[i][0],ar[i][1],ar[i][2]);
    // }
    int arr[n][4];
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(ar[i][1]>max){
            max=ar[i][1];
        }
        arr[i][0]=ar[i][0];
        arr[i][1]=ar[i][1];
        arr[i][2]=ar[i][2];
        arr[i][3]=max;
    }
    int q;
    scanf("%d",&q);
    // int min=0;
    // int index = findClosestIndex(arr, n, q);
    for(int i=0;i<q;i++){
        int x;
        scanf("%d",&x);
        // int index = findClosestIndex(arr, n, x);
        int min=1e9;
        // if(index==-1){
        //     printf("-1\n");
        //     continue;
        // }
        // while((arr[j][0]<=x && x <= arr[j][1] && j>=0) || (x<=arr[j][3]&&j>=0)){
        //     if(arr[j][0]<=x && x <= arr[j][1] && j>=0){   
        //         if(arr[j][2]<min){
        //             min=arr[j][2];
        //         }
        //     }
        //     j--;
        // }
        // while(arr[k][0]<=x && arr[k][1]>=x && k<n){
        //     if(arr[k][2]<min){
        //         min=arr[k][2];
        //     }
        //     k++;
        // }
        // for (j = 0; j <= index; j++) {
        //     if (arr[j][0] <= x && x <= arr[j][1] && arr[j][2] < min) {
        //         min = arr[j][2];
        //     }
        // }
        int j=0;
        // while(j!=n){
        //     if(arr[j][0]<=x && arr[j][1]>=x){
        //         if(arr[j][2]<min){
        //             min=arr[j][2];
        //         }
        //     }
        //     j++;
        // }
        if(n==0){
            printf("-1\n");
            continue;
        }
        do{
            if(arr[j][0]<=x && arr[j][1]>=x){
                if(arr[j][2]<min){
                    //min=arr[j][2];
                    printf("%d\n",arr[j][2]);
                    min=1;
                    break;
                }
                // printf("%d %d %d\n",arr[j][0],arr[j][1],arr[j][2]);
            }
            j++;
        }while(j!=n);

        if (min==1e9)
        {
            printf("-1\n");
            continue;            
        }
        // printf("%d\n",min);
    }
    return 0;
}