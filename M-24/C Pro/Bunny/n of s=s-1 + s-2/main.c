#include <stdio.h>
void main()
{
int s,a,b,c;
scanf("%d %d %d",&a,&b,&c);
printf("%d%d",b,c);
for (int m=1;m<=a-2;m++){
s=b+c;
printf("%d",s);
b=c;
c=s;
}}
