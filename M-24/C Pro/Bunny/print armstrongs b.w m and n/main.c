/* 
 * Lab 2 Problem 3
 */
#include<stdio.h>
#include <string.h>
int poe(int u,int v){
if (v==0){return 1;}
int um=1;
int c=0;
for (int r=0;r<v;r++){
um=um*u;}
return um;}
int main(){
int a,b,num=0,re,high,sum=0,c=0,temp;
scanf("%d %d",&a,&b);
for (int i=a;i<=b;i++){
char str[8];
sprintf(str,"%d",i);
temp=i;
int x=strlen(str);
if (i<0){x=x-1;}
if (i>=0){
for (int k=1;i>0;k++){
re=i%10;
i=i/10;
sum=poe(re,x)+sum;}}
else {
for (int k=1;i<0;k++){
re=i%10;
i=i/10;
sum=poe(re,x)+sum;}}
i=temp;
if (temp==sum){printf("%d ",temp);c=c+1;high=temp;}
sum=0;}
printf("\n");
if (c!=0){
printf("%d",high);}
if (c==0){printf("-1");}
return 0;
} 
