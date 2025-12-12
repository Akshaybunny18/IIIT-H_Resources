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
int main(){
    int n, y, x;
    scanf("%d", &n);
    struct Node* a[n+1];
    for(int i=0;i<=n;i++) {
        a[i]=NULL;
    }
    struct Node* head = NULL;
    //struct Node* temp = NULL;
    struct Node* head1 = NULL;
    scanf("%d %d", &x, &y);
    head = appendNode(head, x);
    //head1 = appendNode(head, y);
    //head1=NULL;
    //int c=1;
    a[x]=head;
    a[y] = appendNode(a[x], y);  
    for(int i=0;i<n-2;i++){
        scanf("%d %d", &x, &y);
        //akshay
        a[y] = appendNode(NULL, y);  
        a[y]->next = a[x]->next;
        a[x]->next = a[y];

    }
    printlist(head);
    return 0;
}
