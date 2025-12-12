#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    int datacount;
    struct node *left;
    struct node *right;
    int level;
} Node;

int lmax=0;int l=1;
Node *root=NULL;
int k=0;
int flag=0;

Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->datacount = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}



// Node *insert(Node *root, int data){
//     if(root == NULL){
//         return createNode(data);
//     }
//     if(data < root->data){
//         root->left = insert(root->left, data);
//         l++;
//     }else if(data > root->data){
//         root->right = insert(root->right, data);
//         l++;
//     }
//     else{
//         root->datacount++;
//     }
//     return root;
// }



void insert(Node *temp,int data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }
    temp = root;
    while (1) {
        if (data < temp->data) {
            if (temp->left) {
                temp = temp->left;
            }
            else {
                temp->left = createNode(data);
                return;
            }
        } else {
            if (temp->right) {
                temp = temp->right;
            }
            else {
                temp->right = createNode(data);
                return;
            }
        }
    }
}


Node* suc(Node *temp,int data){
    if(temp==NULL){
        //printf("0\n");
    }
    else{
        if(temp->right!=NULL){
            temp = temp->right;
            while(temp->left!=NULL){
                temp = temp->left;
            }
            return temp;
        }
    }
        Node *succ = NULL;
        Node *temp1 = root;
        while(temp1!=NULL){
            if(data<temp1->data){
                succ = temp1;
                temp1 = temp1->left;
            }
            else if(data>temp1->data){
                temp1 = temp1->right;
            }
            else break;
        }
        return succ;
}


Node* pre(Node *temp,int data){
    if(temp==NULL){
        //printf("0\n");
    }
    else{
        if(temp->left!=NULL){//
            temp = temp->left;//
            while(temp->right!=NULL){
                temp = temp->right;
            }
            return temp;
        }
    }
        Node *succ = NULL;
        Node *temp1 = root;
        while(temp1!=NULL){
            if(data<temp1->data){
                temp1 = temp1->left;
            }
            else if(data>temp1->data){
                succ = temp1;
                temp1 = temp1->right;//
            }
            else{
                break;
            }
        }
        return succ;
}


Node *search(Node* head,int data){
    while(head){
        if(data==head->data) {
            return head;
        }
        else head = (data<head->data)?head->left:head->right ;
    }
    return NULL;
}



int main(){
    int x;
    scanf("%d",&x);
    int max=-1000000000,min=1000000000;

    for(int i=0;i<x;i++){
        int b;
        scanf("%d",&b);

        insert(root,b);
        if(b>max) max=b;
        if(b<min) min=b;
    }
    int t;


    scanf("%d",&t);
    
    // printf("hi");

    // int o=0;
    // printf("%d",o);

    Node * maxnode=search(root,max);
    Node * minnode=search(root,min);
    //printf("%d %d\n",suc(minnode,minnode->data)->data,pre(maxnode,maxnode->data)->data);
    //target(maxnode,minnode);
    Node * s=minnode;
    Node* l=maxnode;

    while(s->data!=l->data || l==NULL || s==NULL){
        if(s->data+l->data==t) {
            k=22;
            break;
        }
        else if(s->data+l->data<t){
            s = suc(s,s->data);
        }
        else if(s->data+l->data>t){
            l = pre(l,l->data);
        }
        //printf("k");
    }

    if(k==22){
        printf("1\n");
    }
    else {
        printf("0\n");
    }
}