#include <stdio.h>
int main(){
int a,b,c;
scanf("%d:%d:%d",&a,&b,&c);
if (a==00) {printf("%d:%d:%d AM",12,b,c);}
else if (a>12) {a-=12;
printf("%d:%d:%d PM",a,b,c);}
else {printf("%d:%d:%d AM",a,b,c);}
return 0 ;}
