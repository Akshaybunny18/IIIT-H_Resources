#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    bool data;
    struct Node* left;
    struct Node* right;
    int count;
};


struct Node* newNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}
    
struct Node* root=NULL;
// struct Node *root= NULL;

// int k=0;
int buses=0;

int inorder(struct Node* root) {
    if (!root) return 0; // Base case

    int leftPassengers = inorder(root->left);
    int rightPassengers = inorder(root->right);
    if(leftPassengers>0)leftPassengers=1;
    if(rightPassengers>0)rightPassengers=1;

    int totalPassengers = leftPassengers + rightPassengers ;

    if (totalPassengers >= 2 ) {
        buses++;
        // return 0;
    }
    if(totalPassengers>=2) totalPassengers=1;
    return totalPassengers + root->data;
}
// void inf()
void freeT(struct Node* temp){
    if(!temp) return ;
    freeT(temp->left);
    freeT(temp->right);
    free(temp);
}

int main(){
    int n;
    scanf("%d",&n);
    int *parent = (int*)malloc(sizeof(int)*(n+1));
    struct Node** nodes=(struct Node**)malloc(sizeof(struct Node*)*(n+1));

    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        nodes[i]=newNode(k);
    }

    for(int i=1;i<=n;i++){
        scanf("%d",&parent[i]);
        // insert(arr[i]);
        // nodes[i]=createnode(i);

    }

    for(int i=1;i<=n;i++){
        if(parent[i]==-1) root=nodes[i];
        else {
            struct Node* temp=nodes[parent[i]];
            if(!temp->left) temp->left=nodes[i];
            else if(!temp->right) temp->right=nodes[i];
        }
    }
    free(nodes);
    free(parent);
    root->data=0;
    int k=inorder(root);
    // printf("%d %d\n",k,buses);
    freeT(root);
    if(k>0)buses++;
    printf("%d",buses);
    // root->count=calcinorder(root);
    // nbuses(root);
    // printf("%d",count);

}