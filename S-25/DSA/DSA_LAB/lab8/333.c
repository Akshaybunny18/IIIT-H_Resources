#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &ar[i]);
    }
    // qsort(arr,n,sizeof(arr[0]),cmp);
    if (n == 0 || n == 1)
    {
        printf("%d\n", n);
        return 0;
    }
    // if(n==1)
    qsort(arr, n, sizeof(int), cmp); // Sort first column separately
    qsort(ar, n, sizeof(int), cmp);  // for(int i=0;i<n;i++){
    //     printf("%d %d\n",arr[i][0],arr[i][1]);
    // }
    // for(int i=0;i<n;i++){
    //     ar[i]=arr[i][1];
    // }
    int i = 1, j = 0;
    int count = 1;
    int max = 1;
    while (i < n && j < n)
    {
        if (arr[i] <= ar[j])
        {
            count++;
            i++;
        }
        else
        {
            // count--;
            j++;
            i++;
        }
        // if (count > max)
        //     max = count;
    }
    printf("%d\n", count);
    return 0;
}