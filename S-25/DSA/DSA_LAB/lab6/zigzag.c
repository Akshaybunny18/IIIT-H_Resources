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
Node **q;
int limit = 1000000;
int front = -1, rear = -1;

int *stack;
int index = -1;

// Stack functions
int pop() {
    if (index == -1) {
        return -1;
    }
    return stack[index--];
}

int push(int data) {
    if (index == limit - 1) {
        return -1;
    }
    stack[++index] = data;
    return 0;
}

int topelementstack() {
    if (index == -1) {
        return -1;
    }
    return stack[index];
}

int isemptystack() {
    return index == -1;
}

int size() {
    return index + 1;
}

int isfullstack() {
    return index == limit - 1;
}

// Queue functions
void enqueue(Node *temp) {
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % limit;
    q[rear] = temp;
}

Node *dequeue() {
    Node *temp = q[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % limit;
    }
    return temp;
}

int isempty() {
    return front == -1;
}

int isfull() {
    return (rear + 1) % limit == front;
}

// Level order traversal
void levelorder(Node *root) {
    if (root == NULL) {
        return;
    }
    enqueue(root);
    while (!isempty()) {
        Node *temp = dequeue();
        if (prev != temp->level) {
            while (!isemptystack()) {
                int v = pop();
                printf("%d ", v);
            }
        }
        if (temp->level % 2 == 0) {
            printf("%d ", temp->data);
        } else {
            push(temp->data);
            prev = temp->level;
        }
        if (temp->left != NULL) {
            enqueue(temp->left);
        }
        if (temp->right != NULL) {
            enqueue(temp->right);
        }
        free(temp);
    }
    while (!isemptystack()) {
        int v = pop();
        printf("%d ", v);
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
        q = (Node **)malloc(limit * sizeof(Node *));
        stack = (int *)malloc(limit * sizeof(int));
        root = NULL;
        lmax = 0;
        l = 1;
        k = 0;
        prev = 0;
        front = -1;
        rear = -1;
        index = -1;
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

        // Perform level order traversal
        levelorder(root);
        //freeT(root);
        free(q);
        free(stack);
    }

    return 0;
}