#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* appendNode(struct Node* head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head!=NULL){
        head->next = newNode;
    }
    return newNode;
}

void printlist(struct Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

struct Node* InsertNode(struct Node* head1, struct Node* temp, int x){
    struct Node* head = head1;
    while(head!=NULL){
        if(head->data == x){
            struct Node* tempi = head->next;
            head->next = temp;
            temp->next = tempi;
            break;
        }
        head = head->next;
    }
    return head1;
}

int main(){
    int n, y, x;
    scanf("%d", &n);
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* head1 = NULL;
    scanf("%d %d", &x, &y);
    head = appendNode(head, x);
    head1 = appendNode(head, y);
    for(int i = 0; i < n-2; i++){
        scanf("%d %d", &x, &y);
        temp = NULL;
        temp = appendNode(temp, y);
        head = InsertNode(head, temp, x);
    }
    printlist(head);
    return 0;
}
