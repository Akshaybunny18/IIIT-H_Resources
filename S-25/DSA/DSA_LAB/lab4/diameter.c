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

void freet(struct Node* root){
    if (root == NULL) {
        return;
    }
    freet(root->left);
    freet(root->right);
    free(root);
}

int dia=0;

int diameter(struct Node* root) {
    if (root == NULL) return 0;
    
    int leftHeight = diameter(root->left);
    int rightHeight = diameter(root->right);
    
    if (leftHeight + rightHeight > dia) {
        dia = leftHeight + rightHeight;
    }
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// ------------------------------------------------------
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        dia=0;
        int n;
        scanf("%d", &n);  // Read the number of nodes

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
        if(root==NULL){
            printf("0\n");
            return 0;
        }
    
        diameter(root);
        printf("%d\n",dia);
        freet(root);
    }
    return 0;
}