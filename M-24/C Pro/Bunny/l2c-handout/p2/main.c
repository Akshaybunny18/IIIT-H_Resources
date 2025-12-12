#include <stdio.h>
void main(){
int w=0;
scanf("%d",&w);
for (int k=0;k<w;k++){
int a,o=0,n;
scanf("%d",&a);
int l[a-1],sum=0;
for (int i=0;i<(a-1);i++){
scanf("%d",&l[i]);
sum+=l[i];}
sum-=a*(a+1)/2;
sum=-sum;
printf("%d\n",sum);
}}
