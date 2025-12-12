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

void inorder(struct Node * root){
    if(root!=NULL){
        //printf("hi\n");
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

long long int sum=0;

void maxsum(struct Node *root, long long int t) {
    if (root == NULL) return;
    t += root->data; 
    if (t > sum) sum = t;  // Update max sum at every node
    maxsum(root->left, t);
    maxsum(root->right, t);
}


int main(){
    struct Node* root = NULL;
    int n,x,z;
    scanf("%d", &x);  // Read the number of nodes

    for(int j=0;j<x;j++){
        scanf("%d",&n);
        int parent[n+1],value[n+1];
        struct Node* nodes[n+1];  // Array to store all nodes

        // Read the parent array
        for (int i = 1; i <= n; i++) {
            scanf("%d", &parent[i]);
            //nodes[i] = newNode(i);  // Create a node for each index
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&value[i]);
            nodes[i]=newNode(value[i]);
        }

        // Construct the binary tree from the parent array
        for (int i = 1; i <= n; i++) {
            if (parent[i] == -1) {
                root = nodes[i];  // Root node has no parent
                //printf("%d",root->data);
            } 
            else {
                struct Node* parentNode = nodes[parent[i]];
                if (parentNode->left == NULL) {
                    parentNode->left = nodes[i];  // Assign left child
                } else if (parentNode->right == NULL) {
                    parentNode->right = nodes[i];  // Assign right child
                }
            }
        }
        //inorder(root);
        sum=root->data;
        maxsum(root,0);
        printf("%lld\n",sum);
    }
}
