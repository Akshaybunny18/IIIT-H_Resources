#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
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
    

// struct Node *root= NULL;

void inorder(struct Node * root){
    if(root){
        inorder(root->left);
        if(root->left && !root->right )root->left->count=22;
        else if(!root->left && root->right)root->right->count=22;
        // else root->count=11;
        // printf("%d ",root->data);
        inorder(root->right);
    }
}


void inoorder(struct Node * root){
    if(!root) return;
    inoorder(root->left);
    if(root->count==22)printf("%d ",root->data);
    inoorder(root->right);
}

int main(){
    int n;
    scanf("%d",&n);
    int parent[n];
    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &parent[i]);
        nodes[i] = newNode(i); // Create a node for each index
    }
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            root = nodes[i];  // Root node has no parent
        } else {
            struct Node* parentNode = nodes[parent[i]];
            if (i<parent[i]) {
                parentNode->left = nodes[i];  // Assign left child
            } else  {
                parentNode->right = nodes[i];  // Assign right child
            }
        }
    }
    // inorder(root);
    // inorder(root->left);
    if(root) root->count=22;
    inorder(root);
    inoorder(root);
    printf("\n");
}