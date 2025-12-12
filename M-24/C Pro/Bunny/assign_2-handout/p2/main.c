/* 
 * Assignment 2 Problem 2
 */
#include <stdio.h>

int main(){
int n,k=0,r=0,u=0;
scanf("%d",&n);
for (int i=1;i<=n;i++){
k=i;
r=0;
for (int j=0;j<100;j++){
int k_orig=k;
r=0;
while (k>0){
u=k%10;
r+=u*u;
k/=10;
}
if (r==1){
printf("%d ",i);
break;
}
k=r;
if (k==k_orig){
break;
}
}
}
return 0;
}
