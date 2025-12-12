#include <stdio.h>
int fa(int n){
int f=1;
if (n==0){return 1 ; }
else {
for (n;n>1;n--){
f=f*n;}
return f ;}  }
void main() {
int a;
printf("enter no. of lines of pascal triangle you need ");
scanf("%d",&a);
for (int p=1;p<=a;p++){
for (int i=1;i<=a-p+1;i++){
printf(" ");}
for (int k=0;k<p;k++){
printf("%d ",fa(p-1)/(fa(k)*fa(p-k-1)));}
printf("\n");}}

