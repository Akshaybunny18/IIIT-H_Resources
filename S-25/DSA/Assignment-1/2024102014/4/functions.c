#include "functions.h"
struct PtrNode *Insert(struct PtrNode * Head, int num){
	struct PtrNode *temp = (struct PtrNode *)malloc(sizeof(struct PtrNode));
    if(Head==NULL){
        temp->Element=num;
        temp->NextNode=temp;
        return temp;
    }
	temp->Element=Head->Element;
	temp->NextNode=Head->NextNode;
	Head->Element=num;
	Head->NextNode=temp;
    return Head;
}
// struct PtrNode *Find1(struct PtrNode *Head,int num){
//     if(Head==NULL) return NULL;
// 	struct PtrNode *temp=Head;
// 	while(temp->Element!=num){
// 		temp=temp->NextNode;
// 		if(temp==Head){
// 			return Head;
// 		}
// 	}
// 	return temp;
// }
struct PtrNode *Find2(struct PtrNode *Head,int num){
    if(Head==NULL) return NULL;
    struct PtrNode *temp=Head;
    struct PtrNode *tempo=Head;
    int temp1=0;
	if(Head->Element==num){
		return Head;
	}
    while(temp->NextNode->Element!=num && temp->NextNode!=Head){
        temp=temp->NextNode;
    }
    if(temp->NextNode==Head){
        return NULL;
    }
    temp1=temp->NextNode->Element;
    tempo=temp->NextNode;
    temp->NextNode=temp->NextNode->NextNode;
    return Insert(Head,temp1);
    free(tempo);
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
