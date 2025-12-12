#include <stdio.h>
#include <stdlib.h>
struct PtrNode{
	int Element;
	struct PtrNode* NextNode;
};
struct PtrNode *Insert(struct PtrNode * Head, int num);
struct PtrNode *Find2(struct PtrNode *Head,int num);
void Print(struct PtrNode * Head);
