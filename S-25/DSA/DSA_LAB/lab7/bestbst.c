#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long long int data;
    struct Node* left;
    struct Node* right;
    int count;
} Node;

long long int *arr;
int a=0;
Node* root=NULL;

Node* createnode(long long int data){
    Node* newnode=malloc(sizeof(Node));
    newnode->data=data;
    newnode->right=newnode->left=NULL;
    // newnode->count=1;
    return newnode;
}

void inorder(Node * temp){
    if(!temp) return ;
    inorder(temp->left);
    arr[a++]=temp->data;
    // printf("%d",temp->data);
    inorder(temp->right);
}

void preorder(Node* temp){
    if (!temp) return ;
    printf("%lld ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void insert(long long int data){
    if(!root) {
        root=createnode(data);
        return ;
    }
    Node* temp=root;
    while(temp){
        if(data<temp->data) {
            if(temp->left) temp=temp->left;
            else {
                temp->left=createnode(data);
                break;
            }
        }
        else {
            if(temp->right) temp=temp->right;
            else {
                temp->right=createnode(data);
                break;
            }
        }
    }
}

void divide(int left,int right){
    if(left>right) return ;
    int mid=(left+right)/2;
    insert(arr[mid]);
    divide(left,mid-1);
    divide(mid+1,right);
}   

void freeT(Node* temp){
    if(!temp) return ;
    freeT(temp->left);
    freeT(temp->right);
    free(temp);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        long long int x;
        scanf("%lld",&x);
        // printf("cghjk");
        insert(x);
    }
    arr=malloc(sizeof(long long int)*n);
    // printf("hi");
    inorder(root);
    freeT(root);
    root=NULL;
    // printf("hu");
    divide(0,n-1);
    free(arr);
    // printf("hu");
    // printf("%d",root->data);
    // inorder(root);
    preorder(root);
    printf("\n");
    freeT(root);
    // return 0;
}