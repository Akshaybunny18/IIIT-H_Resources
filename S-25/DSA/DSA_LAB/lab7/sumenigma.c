#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    int count;
} node ;

node *createnode(int data){
    node * newnode = (node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->right=newnode->left=NULL;
    newnode->count=1;
    return newnode;
}

node *root= NULL;

void inorder(node * root){
    if(root){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}





void main(){
    int n;
    scanf("%d",&n);
    
    

}