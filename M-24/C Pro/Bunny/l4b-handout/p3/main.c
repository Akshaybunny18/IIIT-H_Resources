#include <stdio.h>
int main(){
   int a,b,p=0,k=0,o=0;
   scanf("%d %d",&a,&b);
   char x[a+1],y[b+1];
   scanf("%s %s",x,y);
   x[a]=y[b]='\0';
   if(x==y){
      printf("YES");
   }
   for(int i=0;i<a;i++){
   	for(int j=o;j<b;j++){
   		if(x[i]==y[j]){
   			p+=1;
            o=j;
   		}
   	}
      if(p<=k){
         printf("NO");
         return 0;
      }
      k=p;
   }
   if(p==a){
   	printf("YES");
   }
   else{
   	printf("NO");
   }
   return 0;
}
