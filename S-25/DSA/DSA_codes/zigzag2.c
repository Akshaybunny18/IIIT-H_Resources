#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int datacount;
    struct node *left;
    struct node *right;
    int level;
} Node;

int lmax = 0;
int l = 1;
Node *root = NULL;
int k = 0;
int prev = 0;

// Queue and Stack
// Node **q;
int limit = 1000000;
// int front = -1, rear = -1;

Node **stack;
Node **stack1;
int index1 = -1;
int index = -1;

// Stack functions
void push(Node *temp) {
    if (index == limit - 1) {
        return; // Stack is full
    }
    stack[++index] = temp;
}

void push1(Node *temp) {
    if (index1 == limit - 1) {
        return; // Stack is full
    }
    stack1[++index1] = temp;
}

Node *pop() {
    if (index == -1) {
        return NULL; // Stack is empty
    }
    return stack[index--];
}

Node *pop1() {
    if (index1 == -1) {
        return NULL; // Stack is empty
    }
    return stack1[index1--];
}

Node *topelementstack() {
    if (index == -1) {
        return NULL;
    }
    return stack[index];
}

Node *topelementstack1() {
    if (index1 == -1) {
        return NULL;
    }
    return stack1[index1];
}

int isemptystack() {
    return index == -1;
}

int isemptystack1() {
    return index1 == -1;
}

int size() {
    return index + 1;
}

int size1() {
    return index1 + 1;
}

int isfullstack() {
    return index == limit - 1;
}

int isfullstack1() {
    return index1 == limit - 1;
}

// Queue functions
// void enqueue(Node *temp) {
//     if (front == -1) {
//         front = 0;
//     }
//     rear = (rear + 1) % limit;
//     q[rear] = temp;
// }

// Node *dequeue() {
//     Node *temp = q[front];
//     if (front == rear) {
//         front = -1;
//         rear = -1;
//     } else {
//         front = (front + 1) % limit;
//     }
//     return temp;
// }

// int isempty() {
//     return front == -1;
// }

// int isfull() {
//     return (rear + 1) % limit == front;
// }

// Level order traversal

// void levelorder(Node *root) {
//     if (root == NULL) {
//         return;
//     }
//     enqueue(root);
//     while (!isempty()) {
//         Node *temp = dequeue();
//         if (prev != temp->level) {
//             while (!isemptystack()) {
//                 Node *v = pop();
//                 printf("%d ", v->data);
//             }
//         }
//         if (temp->level % 2 == 0) {
//             printf("%d ", temp->data);
//         } else {
//             push(temp);
//             prev = temp->level;
//         }
//         if (temp->left != NULL) {
//             enqueue(temp->left);
//         }
//         if (temp->right != NULL) {
//             enqueue(temp->right);
//         }
//     }
//     while (!isemptystack()) {
//         Node *v = pop();
//         printf("%d ", v->data);
//     }
//     printf("\n");
// }

// Zigzag level order traversal using Node** stacks
void levelorderzigzag(Node *root) {
    if (root == NULL) return;

    push(root); // Push the root node to stack

    while (!isemptystack() || !isemptystack1()) {
        // Process nodes in the current level (left to right)
        while (!isemptystack()) {
            Node *temp = pop();
            printf("%d ", temp->data);

            // Push children to stack1 (right to left)
            if (temp->left != NULL) {
                push1(temp->left);
            }
            if (temp->right != NULL) {
                push1(temp->right);
            }
            free(temp);
        }

        // Process nodes in the current level (right to left)
        while (!isemptystack1()) {
            Node *temp = pop1();
            printf("%d ", temp->data);

            // Push children to stack (left to right)
            if (temp->right != NULL) {
                push(temp->right);
            }
            if (temp->left != NULL) {
                push(temp->left);
            }
            free(temp);
        }
    }
    printf("\n");
}

// Create a new node
Node *createNode(int data, int level) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->datacount = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->level = level;
    if (level > lmax) {
        lmax = level;
    }
    return newNode;
}

// Insert a node into the tree
void insert(Node *temp, int data) {
    while (1) {
        if (data < temp->data) {
            if (temp->left) {
                temp = temp->left;
                l++;
            } else {
                temp->left = createNode(data, temp->level + 1);
                return;
            }
        } else {
            if (temp->right) {
                temp = temp->right;
                l++;
            } else {
                temp->right = createNode(data, temp->level + 1);
                return;
            }
        }
    }
}

void inorder(Node *temp) {
    if (temp == NULL) {
        return;
    }
    inorder(temp->left);
    printf("%d %d\n", temp->data, temp->level);
    inorder(temp->right);
}

void freeT(Node *temp) {
    if (temp == NULL) {
        return;
    }
    freeT(temp->left);
    freeT(temp->right);
    free(temp);
}

int main() {
    int x;
    scanf("%d", &x);

    // Allocate memory for queue and stack once
    

    for (int i = 0; i < x; i++) {
        //q = (Node **)malloc(limit * sizeof(Node *));
        stack = (Node **)malloc(limit * sizeof(Node *));
        stack1 = (Node **)malloc(limit * sizeof(Node *));
        root = NULL;
        lmax = 0;
        l = 1;
        k = 0;
        prev = 0;
        // front = -1;
        // rear = -1;
        index = -1;
        index1 = -1;

        int a;
        scanf("%d", &a);
        int arr[a];
        for (int j = 0; j < a; j++) {
            scanf("%d", &arr[j]);
        }

        if (a == 1) {
            root = createNode(arr[0], 0);
            printf("%d\n", arr[0]);
        } else if (a > 1) {
            int min = arr[0];
            int max = arr[0];
            root = createNode(arr[0], 0);
            Node *temp1 = root; // Pointer to the minimum node
            Node *temp2 = root; // Pointer to the maximum node

            for (int j = 1; j < a; j++) {
                if (arr[j] < min) {
                    temp1->left = createNode(arr[j], temp1->level + 1);
                    temp1 = temp1->left;
                    min = arr[j];
                } else if (arr[j] > max) {
                    temp2->right = createNode(arr[j], temp2->level + 1);
                    temp2 = temp2->right;
                    max = arr[j];
                } else {
                    insert(root, arr[j]);
                }
            }
        }

        // Perform zigzag level order traversal
        levelorderzigzag(root);
        //freeT(root);
        free(stack);
        free(stack1);
    }

    // Free memory for queue and stack
    //free(q);
    

    return 0;
}