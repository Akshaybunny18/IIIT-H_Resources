#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    int datacount;
    struct node *left;
    struct node *right;
} Node;


Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->datacount = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int k=0;


Node *insert(Node *root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }else if(data > root->data){
        root->right = insert(root->right, data);
    }
    else{
        root->datacount++;
    }
    return root;
}

void count(Node * head){
    if(head!=NULL){
        count(head->right);
        k++;
        count(head->left);
    }
}



Node *search(Node* root,int data){
    while(root){
        if(data==root->data) {
            return root->left;
        }
        else root = (data<root->data)?root->left:root->right ;
    }
    return NULL;
}

Node *search1(Node* root,int data){
    while(root){
        if(data==root->data) {
            return root->right;
        }
        else root = (data<root->data)?root->left:root->right ;
    }
    return NULL;
}

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    Node *root=NULL;
    for(int i=0;i<x;i++){
        int a;
        scanf("%d",&a);
        root=insert(root,a);
    }
    for(int i=0;i<y;i++){
        int a;
        scanf("%d",&a);
        if(a==1){
            int b;
            scanf("%d",&b);
            root=insert(root,b);
        }
        else if(a==2){
            int b;
            scanf("%d",&b);
            k=0;
            count(search(root,b));
            printf("%d\n",k);
        }
        else if(a==3){
            int b;
            scanf("%d",&b);
            k=0;
            count(search1(root,b));
            printf("%d\n",k);
        }
    }

}