#include<stdio.h>
#include<stdlib.h>
int a,b;
struct Node {
    int data;
    struct Node *next;
};
struct Node *reverse(struct Node *head) {
    struct Node *prev=NULL,*curr=head,*next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
struct Node* appendnode(struct Node* head,int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL) return newnode;
    struct Node* last=head;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newnode;
    return head;
}
struct Node *addTwoLists(struct Node *num1, struct Node *num2){
    struct Node* head=NULL;
    int carry=0,sum;
    while(num1!=NULL&&num2!=NULL){
        int sum=num1->data+num2->data+carry;
        carry=sum/10;
        head=appendnode(head,sum%10);
        num1=num1->next;
        num2=num2->next;
    }
    while(num1!=NULL){
        int sum=num1->data+carry;
        carry=sum/10;
        head=appendnode(head,sum%10);
        num1=num1->next;
    }
    while(num2!=NULL){
        int sum=num2->data+carry;
        carry=sum/10;
        head=appendnode(head,sum%10);
        num2=num2->next;
    }
    if(carry>0){
        head=appendnode(head,carry);
    }
    return head;
}
int main(){
    char  aa[101],bb[101];
    scanf("%d",&a);
    scanf("%s",aa);
    scanf("%d",&b);
    scanf("%s",bb);
     aa[a]= bb[b]='\0';
    struct Node *head1=NULL;
    struct Node *head2=NULL;
    int i=0;
    while(i<a){
        //i=0;
        head1=appendnode(head1,(int)aa[i]-48);
        i++;
        //aa=aa/10;
    }
    i=0;
    while(i<b){
        head2=appendnode(head2,(int)bb[i]-48);
        i++;
        //bb=bb/10;
    }
    head1 =  reverse(head1);
    head2 =  reverse(head2);
    struct Node *head=addTwoLists(head1,head2);
    head= reverse(head);
    while(head!=NULL){
        printf("%d",head->data);
        head=head->next;
    }
    return 0;
}
