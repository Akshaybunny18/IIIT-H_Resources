#include <stdio.h>
void main(){
	int a,b,c=0,d=0;
	scanf("%d %d",&a,&b);
	if(b>a){
		printf("-1");
		return ;
	}
	while(1){
		if(c<a){
			c+=2;
			d+=1;
		}
		else{
			break;
		}
	}
	while(1){
		if(c>a){
			c-=1;
			d+=1;
		}
		else{
			break;
		}
	}
	while(1){
		if(d%b==0){
			break;
		}
		else {
			d+=1;
		}
	}
	printf("%d",d);
		
}
