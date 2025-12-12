#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int left,right,dia=0;

int diameter(struct Node* root) {
    if (root == NULL) return 0;
    
    int leftHeight = diameter(root->left);
    int rightHeight = diameter(root->right);
    
    if (leftHeight + rightHeight > dia) {
        dia = leftHeight + rightHeight;
    }
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void longleft(struct Node* root,int t) {
    if (root == NULL) {
        if(t>left)left=t;
        return ;
    }
    longleft(root->left,t+1);
    longleft(root->right,t+1);
}

void longright(struct Node* root,int t) {
    if (root == NULL) {
        if(t>right)right=t;
        return ;
    }
    longright(root->right,t+1);
    longright(root->left,t+1);
}

void freeT(struct Node* root){
    if (root == NULL) {
        return;
    }
    freeT(root->left);
    freeT(root->right);
    free(root);
}

int main(){
    int c;
    scanf("%d", &c);  
    for(int i=0;i<c;i++){
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
        //inorder(root);
        //printf("\n");
        if(root==NULL){
            printf("0\n");
            continue;
        }
        left=0;
        right=0;
        dia=0;
        diameter(root);
        if (root->left) longleft(root->left,0);
        if (root->right) longright(root->right,0);
        printf("%d\n",dia);
        //printf("%d\n",left+right);
        freeT(root);
    } 
}