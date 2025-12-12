#include <stdio.h>
void main(){
	int m,p,e,pc,ec;
	scanf("%d %d %d",&m,&p,&e);
	m=m-e;
	pc=m/p;
	m=m%p;
	ec=m/e;
	m=m%e;
	printf("%d %d %d",pc,ec+1,m);	
}
