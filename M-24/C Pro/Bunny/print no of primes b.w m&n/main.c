#include <stdio.h>
void main(){
int c,a,b,o=0;
scanf("%d %d",&a,&b);
for (int i=a;i<=b;i++){
c=0;
for ( int j=2;j<=(i/2);j++){
if (i%j==0){c=c+1;}}
if (c==0){o=o+1;}}
printf("%d",o);}

