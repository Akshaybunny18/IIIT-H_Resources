#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* newNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int c=1000000000;
int v=0;
int left=0,right=0;
int a,b;

int lca(struct Node* root){
    if(root==NULL){
        return -1;
    }
    if(root->data==a || root->data==b){
        return 0;
    }
    int left = lca(root->left);
    int right = lca(root->right);

    if(left!=-1 && right!=-1){
        c = left + right;
        v = root->data;
        return -1;
    }
    if(left!=-1){
        return left+1;
    }
    if(right!=-1){
        return right+1;
    }
    return -1;
}

    
struct Node* lcaa(struct Node* root, int a, int b) {
    if(root == NULL || root->data == a || root->data == b){
        return root;
    }
    struct Node* left = lcaa(root->left, a, b);
    struct Node* right = lcaa(root->right, a, b);

    if(left != NULL && right != NULL){
        return root;
    }
    return (left != NULL) ? left : right;
}


void freet(struct Node* root){
    if (root == NULL) {
        return;
    }
    freet(root->left);
    freet(root->right);
    free(root);
}


// ------------------------------------------------------
int main(){
    int n;
    scanf("%d", &n);  // Read the number of nodes
    scanf("%d %d",&a,&b);
    int parent[n+1];
    struct Node* nodes[n+1];  // Array to store all nodes

        // Read the parent array
    for (int i = 1; i <= n; i++) {
        scanf("%d", &parent[i]);
        nodes[i] = newNode(i);  // Create a node for each index
    }

    struct Node* root = NULL;

        // Construct the binary tree from the parent array
    for (int i = 1; i <= n; i++) {
        if (parent[i] == -1) {
            root = nodes[i];  // Root node has no parent
        } else {
            struct Node* parentNode = nodes[parent[i]];
            if (parentNode->left == NULL) {
                parentNode->left = nodes[i];  // Assign left child
            } else if (parentNode->right == NULL) {
                parentNode->right = nodes[i];  // Assign right child
            }
        }
    }
    lca(root);
    printf("%d\n",lcaa(root,a,b)->data);
    freet(root);
    return 0;
}