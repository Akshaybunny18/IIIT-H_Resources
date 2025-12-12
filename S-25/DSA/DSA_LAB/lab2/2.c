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
int sizell (struct Node* head){
    int count =0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
int main(){
    int x;
    scanf("%d",&x);
    struct Node* head=NULL;
    struct Node* headend=NULL;
    for (int i=0;i<x;i++){
        int p;
        scanf("%d",&p);
        if(p==1){
            int num;
            scanf("%d",&num);
            if(head==NULL){
                struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
                newnode->data=num;
                newnode->next=NULL;
                head=headend=newnode;
            }
            else{
            struct Node* hi=createnode(NULL,num);
            hi->next=head;
            head=hi;
            }
            printf("%d\n",num);
        }
        else if(p==2){
            int num;
            scanf("%d",&num);
            if(headend==NULL|| head==NULL){
                struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
                newnode->data=num;
                newnode->next=NULL;
                head=headend=newnode;
            }
            else{
                headend=createnode(headend,num);
            }
            printf("%d\n",num);
        }
        else if(p==3){
            if(head==NULL){
                printf("-1\n");
            }
            else{
                if(head->next==NULL){
                    printf("%d\n",head->data);
                    free(head);
                    head=NULL;
                    headend=NULL;
                    continue;
                }
                struct Node* hi=head;
                printf("%d\n",head->data);
                head=head->next;
                free(hi);
            }
        }
        else if(p==4){
            if(head==NULL){
                printf("-1\n");
            }
            else{
                struct Node* hi=head;
                if(head->next==NULL){
                    printf("%d\n",head->data);
                    free(head);
                    head=NULL;
                    headend=NULL;
                    continue;
                }
                while(hi->next->next!=NULL){
                    hi=hi->next;
                }
                printf("%d\n",hi->next->data);
                free(hi->next);
                hi->next=NULL;
                headend=hi;
            }
        }
        else if(p==5){
            printf("%d\n",sizell(head));
        }
    }
}