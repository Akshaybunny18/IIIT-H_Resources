#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node * next;
};
struct Node *createnode(struct Node *head,int num){
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data=num;
    newnode->next=NULL;
    if(head==NULL) return newnode;
    head->next=newnode;
    return newnode;

}
struct Node* addlist(struct Node *l1,struct Node*l2){
    int carry=0;
    struct Node* head=NULL;
    struct Node* headend=NULL;
    while(l1!=NULL && l2!=NULL){
        int temp=l1->data+l2->data+ carry;
            carry = temp/10;
            temp=temp%10;
        if(head==NULL){
                struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
                newnode->data=temp;
                newnode->next=NULL;
                head=headend=newnode;
        }
        else{
        headend=createnode(headend,temp);
        }
        l1=l1->next;
        l2=l2->next;
    }
    while(l2!=NULL){
        int temp=l2->data+ carry;
            carry = temp/10;
            temp=temp%10;
        if(head==NULL){
                struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
                newnode->data=temp;
                newnode->next=NULL;
                head=headend=newnode;
        }
        else{
        headend=createnode(headend,temp);
        }
        l2=l2->next;
    }
    while(l1!=NULL){    
        int temp=l1->data+ carry;
            carry = temp/10;
            temp=temp%10;
        if(head==NULL){
                struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
                newnode->data=temp;
                newnode->next=NULL;
                head=headend=newnode;
        }
        else{
        headend=createnode(headend,temp);
        }
        l1=l1->next;
    }
    if(carry !=0){
        createnode(headend,carry);
    }
    return head;
}
void print(struct Node* l){
    while(l!=NULL){
        printf("%d ",l->data);
        l=l->next;
    }
    printf("\n");
}
int main(){
    int x;
    scanf("%d",&x);
    for (int i=0;i<x;i++){
        struct Node *head1=NULL;
        struct Node *head2=NULL;
        struct Node *head1end=NULL;
        struct Node *head2end=NULL;
        struct Node* head=NULL;
        int num;
        scanf("%d",&num);
        while(num!=-1){
            if(head1==NULL){
                struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
                newnode->data=num;
                newnode->next=NULL;
                head1=head1end=newnode;
            }
            else{
                head1end=createnode(head1end,num);
            }
            scanf("%d",&num);
        }
        scanf("%d",&num);
        while(num!=-1){
            if(head2==NULL){
                struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
                newnode->data=num;
                newnode->next=NULL;
                head2=head2end=newnode;
            }
            else{
                head2end=createnode(head2end,num);
            }
            scanf("%d",&num);
        }
        head=addlist(head1,head2);
        // print(head1);
        // print(head2);
        print(head);
    }
}