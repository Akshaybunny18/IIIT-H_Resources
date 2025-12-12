#include <stdio.h>
#include <stdlib.h>
struct PtrNode{
	int Element;
	struct PtrNode* NextNode;
};
struct PtrNode *end=NULL;

struct PtrNode *Insert(struct PtrNode * Head, int num){
	struct PtrNode *temp = (struct PtrNode *)malloc(sizeof(struct PtrNode));
    if(Head==NULL){
        temp->Element=num;
        temp->NextNode=temp;
        end=temp;
        return temp;
    }
	temp->Element=num;
    temp->NextNode=Head;
    end->NextNode=temp;
    Head=temp;
    return Head;
}
struct PtrNode *Find2(struct PtrNode *Head,int num){
    if(Head==NULL) return NULL;
    struct PtrNode *temp=Head;
    // struct PtrNode *tempo=Head;
    // int temp1=0;
    if(Head->Element==num){
        return Head;
    }
    while(temp->NextNode->Element!=num && temp->NextNode!=Head){
        temp=temp->NextNode;
    }
    if(temp->NextNode->Element==Head->Element){
        return NULL;
    }
    if(temp->NextNode->Element==num && temp->NextNode==end){
        end=temp;
        return temp->NextNode;
    }
    // temp1=temp->NextNode->Element;
    //tempo=temp->NextNode;
    struct PtrNode * hi= temp->NextNode;
    temp->NextNode=temp->NextNode->NextNode;
    hi->NextNode=Head;
    end->NextNode=hi;
    Head=hi;
    return Head;
    // struct PtrNode *temp11 = (struct PtrNode *)malloc(sizeof(struct PtrNode));
    // temp11->Element=temp1;
    // temp11->NextNode=Head;
    // end->NextNode=temp11;
    //return temp11;
    //free(tempo);
}
void Print(struct PtrNode * Head){
	if(Head==NULL){
		return;
	}
    struct PtrNode *temp = Head;
	do {
        printf("%d ", temp->Element);
        temp = temp->NextNode;
    } while (temp != Head);
	printf("\n");
}
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