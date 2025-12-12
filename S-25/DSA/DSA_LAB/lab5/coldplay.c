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
        scanf("%d %d", &arr[i], &ar[i]);
    }
    qsort(arr, n, sizeof(int), cmp);        // Sort first column separately
    qsort(ar, n, sizeof(int), cmp); // for(int i=0;i<n;i++){
    //     printf("%d %d\n",arr[i][0],arr[i][1]);
    // }
    int i = 0, j = 0;
    int count = 0;
    int max = 1;
    while (i < n)
    {
        if (arr[i] < ar[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        if (count > max)
            max = count;
    }
    printf("%d", max);
    return 0;
}