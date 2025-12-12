#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node * next;
};
int len=0;
struct Node *createnode(struct Node *head,int num){
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data=num;
    newnode->next=NULL;
    if(head==NULL) return newnode;
    head->next=newnode;
    return newnode;
}

void print(struct Node* l){
    while(l!=NULL){
        printf("%d ",l->data);
        l=l->next;
    }
    printf("\n");
}
struct Node* deletenode(struct Node* head,int index){
    struct Node* new    =  head;
    if(head->next==NULL && index==0){
        free(head);
        print(NULL);
        return NULL;
    }
    if(index==0){
        struct Node* temp=head;
        head=head->next;
        free(temp);
        print(head);
        return head;
    }
    while(-1+index--) new=new->next;
    struct Node* temp=new->next;
    new->next=new->next->next;
    free(temp);
    print(head);
    return head;
}
struct Node* addindex(struct Node* head,int index,int num){
    struct Node* new = head;
    if(head==NULL){
        head=createnode(NULL,num);
        print(head);
        return head;
    }
    if(index==0){
        struct Node *hi=createnode(NULL,num);
        hi->next=head;
        print(hi);
        return hi;
    }
    while(-1+index--) new=new->next;
    if(index==0){
        struct Node *hi=createnode(NULL,num);
        hi->next=new->next;
        new->next=hi;
    }
    print(head);
    return head;
}
int main(){
    int x;
    scanf("%d",&x);
    struct Node* head=NULL;
    struct Node* headend=NULL;
    for (int i=0;i<x;i++){
       int a;
       scanf("%d",&a);
       if (a==0){
            int index,num;
            scanf("%d %d",&index,&num);
            if(index<=len && index>=0){
                head=addindex(head,index,num);
                len++;
            }
       }
       else if (a==1){
            int del;
            scanf("%d",&del);
            if(del<len && len!=0 && del>=0){
                head=deletenode(head,del);
                len--;
            }
       } 
    }
}