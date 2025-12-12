#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list* next;
} list;
list * first=NULL;
list* headend;
void append(int data){
    list* head=first;
    if(!head){
        list* new=malloc(sizeof(list));
        new->data=data;
        new->next=NULL;
        first=new;
        return ;
    }
    if(head->data>=data) {
        //printf("hi");
        list* new=malloc(sizeof(list));
        new->data=data;
        new->next=NULL;
        new->next=head;
        first=new;
        return ;
    }
    if(!head->next){
        if(head->data>=data){
            list* new=malloc(sizeof(list));
            new->data=data;
            new->next=NULL;
            new->next=head;
            first=new;
            return ;
        }
        list* new=malloc(sizeof(list));
        new->data=data;
        new->next=NULL;
        head->next=new;
        return ;
    }
    while(head->next->data<data && head->next){
        head=head->next;
        if(head->next==NULL) break;
    }
    if(!head->next){
        list* new=malloc(sizeof(list));
        new->data=data;
        new->next=NULL;
        head->next=new;
        return ;
    }
    list* new=malloc(sizeof(list));
    new->data=data;
    new->next=NULL;
    list* temp=head->next;
    head->next=new;
    new->next=temp;
}

void delete (int data){
    list* head=first;
    if(head== NULL) return; 
    if(head->data==data){
        first=head->next;
        return ;
    }
    while(head->next->data!=data && head->next!=NULL){
        head=head->next;
                if(head->next==NULL) break;
    }
    if(!head->next) return ;
    if(head->next->next==NULL){
        head->next=NULL;
        //free(head->next);
        return;
    }
    list * temp = head->next;
    head->next=head->next->next;
    free(temp);
}

void print(){
    list* head=first;
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
int main(){
    int x;
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        int y;
        scanf("%d",&y);
        append(y);
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d",&a);
        if(a==1) {
            scanf("%d",&b);
            append(b);
        }
        else if(a==2){
            scanf("%d",&b);
            delete(b);
        }
        else if(a==3) print();
    }
}