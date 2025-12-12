#include "functions.h"
int main(){
	int x;
	struct PtrNode *head = NULL;
	scanf("%d",&x);
	for(int i=0;i<x;i++){
		char oper[6];
		scanf("%s",oper);
		int num;
		if(oper[4]=='1' && oper[0]=='O'){
			scanf("%d",&num);
			head=Insert(head,num);
		}
		else if(oper[4]=='2' && oper[0]=='O'){
			struct PtrNode *temp = head;
			scanf("%d",&num);
			temp=Find2(head,num);
			if(temp==NULL){
				continue;
			}
			else{
				head=temp;
			}
		}
		else if(oper[4]=='3' && oper[0]=='O'){
			Print(head);
		}
		else{
			continue;
		}
	}
	return 0;
}
