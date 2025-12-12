#include <stdio.h>
void main(){
int w=0;
scanf("%d",&w);
for (int k=0;k<w;k++){
int a,o=0,n;
scanf("%d",&a);
int l[a-1];
for (int i=0;i<(a-1);i++){
scanf("%d",&l[i]);}
n=a;
for (int x=n;x>=1;x--){
o=0;
for (int p=0;p<a-1;p++){
if (l[p]!=x)
{o=o+1;}}
if (o==(a-1)){printf("%d\n",x);}
}}}

