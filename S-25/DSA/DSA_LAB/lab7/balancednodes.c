#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    long long int data;
    struct Node* left;
    struct Node* right;
    int count;
} Node;


Node **stack;
int index=0,max=100000;


int isempty(){
    if(!index) return 1;
    else return 0;
}

int isfull(){
    if(index==max-1) return 1;
    else return 0;
}

int push(Node* val){
    if(isfull()){
        return 0;
    }
    stack[++index]=val;
    return 1;
}

Node* pop(){
    if(isempty()){
        return stack[0];
    }
    return stack[index--];
}




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
    printf("%d ",temp->data);
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


void freeT(Node* temp){
    if(!temp) return ;
    freeT(temp->left);
    freeT(temp->right);
    free(temp);
}
int k=0;
int count(Node*temp){
    if(!temp) return 0;

    int left=count(temp->left);
    int right=count(temp->right);

    if(abs(left-right)>1) k=1;

    return (left>right?left:right) + 1;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    Node* nodes[n+1];
    stack=malloc(sizeof(Node)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        // insert(arr[i]);
        nodes[i]=createnode(i);

    }

    for(int i=0;i<n;i++){
        if(arr[i]==-1) root=nodes[i];
        else {
            Node* temp=nodes[arr[i]];
            if(!temp->left) temp->left=nodes[i];
            else if(!temp->right) temp->right=nodes[i];
        }
    }
    // root=createnode(arr[n-1]);
    // push(root);
    // // printf("huhjkl");
    // for(int i=n-2;i>=0;i--){
    //     if(isempty() || stack[index]->data<=arr[i]){
    //         stack[index]->right = createnode(arr[i]);  
    //         push(stack[index]->right);  
    //     }
    //     else {
    //         Node* temp=NULL;
    //         while(!isempty() && stack[index]->data>arr[i]){
    //             temp=pop();
    //         }
    //         temp->left=createnode(arr[i]);
    //         push(temp->left);
    //     }
    // }
    count(root);
    // inorder(root);
    // preorder(root);
    if(k) printf("Not balanced\n");
    else printf("Balanced\n");
    return 0;
}
