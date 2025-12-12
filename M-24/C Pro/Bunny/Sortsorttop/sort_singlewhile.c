#include <stdio.h>
int main()
{
int n;
scanf("%d",&n);
int arr[n],track=0,i=0;
for(int j=0;j<n;j++)
{
scanf("%d",&arr[j]);
}
while(track!=(n-1))
{
if(i==(n-1))
{i=0;
track=0;
}
if(arr[i]>arr[i+1])
{arr[i]=arr[i]+arr[i+1];
arr[i+1]=arr[i]-arr[i+1];
arr[i]=arr[i]-arr[i+1];}
else
{
track++;
}
i++;
}
for(int j=0;j<n;j++)
{
printf("%d ",arr[j]);
}
return 0;
}
