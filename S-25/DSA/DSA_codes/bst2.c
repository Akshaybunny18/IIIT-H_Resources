#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *root = NULL;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert1(Node *temp, int data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }
    else{
        temp = root;
        while (1) {
            //if (data == temp->data) return; 
            if (data < temp->data) {
                if (temp->left) temp = temp->left;
                else {
                    temp->left = createNode(data);
                    return;
                }
            } else {
                if (temp->right) temp = temp->right;
                else {
                    temp->right = createNode(data);
                    return;
                }
            }
        }
    }
}


void insert(int data) {
    Node *newNode = createNode(data);
    if (!root) {
        root = newNode;
        return;
    }
    Node *cur = root, *prev = NULL;
    while (cur) {
        prev = cur;
        cur = (data < cur->data) ? cur->left : cur->right;
    }
    if (data < prev->data) prev->left = newNode;
    else prev->right = newNode;
}

Node *findNode(int data) {
    Node *cur = root;
    while (cur && cur->data != data)
        cur = (data < cur->data) ? cur->left : cur->right;
    return cur;
}


void preorder(Node *cur) {
    if (!cur) return;
    printf("%d ", cur->data);
    preorder(cur->left);
    preorder(cur->right);
}

void inorder(Node *cur) {
    if (!cur) return;
    inorder(cur->left);
    printf("%d ", cur->data);
    inorder(cur->right);
}

void postorder(Node *cur) {
    if (!cur) return;
    postorder(cur->left);
    postorder(cur->right);
    printf("%d ", cur->data);
}
Node* successor(Node *temp, int data) {
    if (!temp) return NULL;

    if (temp->right) {
        temp = temp->right;
        while (temp->left) temp = temp->left;
        return temp;
    }

    Node *succ = NULL, *cur = root;
    while (cur) {
        if (data < cur->data) {
            succ = cur;
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return succ; // NULL if no successor
}

Node* predecessor(Node *temp, int data) {
    if (!temp) return NULL;

    if (temp->left) {
        temp = temp->left;
        while (temp->right) temp = temp->right;
        return temp;
    }

    Node *pred = NULL, *cur = root;
    while (cur) {
        if (data > cur->data) {
            pred = cur;
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return pred; // NULL if no predecessor
}
Node *delete(Node *cur, int data) {
    if (!cur) return cur;
    if (data < cur->data) cur->left = delete(cur->left, data);
    else if (data > cur->data) cur->right = delete(cur->right, data);
    else {
        if (!cur->left) {
            Node *temp = cur->right;
            free(cur);
            return temp;
        } else if (!cur->right) {
            Node *temp = cur->left;
            free(cur);
            return temp;
        }
        Node *succ = successor(cur,cur->data);
        cur->data = succ->data;
        cur->right = delete(cur->right, succ->data);
    }
    return cur;
}


void freeTree(Node *cur) {
    if (!cur) return;
    freeTree(cur->left);
    freeTree(cur->right);
    free(cur);
}

int main() {
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    root = delete(root, 50);
    printf("After deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}










