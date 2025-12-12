#include <stdio.h>
#include <string.h>
void main(){
int y;
char hi[100],str[100];
scanf("%d",&y);
int i=0;
int x=y;
for (i=0;y>0;i++){
str[i]=(char)(y%2)+'0';
y=y/2;
}
str[i]='\0';
strcpy(hi,str);
for (int j=0,n=strlen(str);n>1;j++,n--){
hi[j]=str[n-1];
}
if (x%2==0 && x!=0)
{ hi[strlen(hi)-1]=0+'0';}
else if (x==0){printf("0");}




