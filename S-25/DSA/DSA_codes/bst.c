#include <stdio.h>
#include <stdlib.h>

int index=-1,limit=128;
int *stack;
int pop(){
    if(index==-1){
        printf("Stack is empty\n");
        return -1;
    }
    return stack[index--];
}


int count = 0;
struct lr{
    int l;
    int r;
};

struct lr a;

void noofpossbt(int n){
    if(n == 0){
        a.l = 0;
        a.r = 0;
        count++;
        return;
    }
    a.l++;
    noofpossbt(n-1);
    a.r++;
    noofpossbt(n-1);
}

int push(int data){
    if(index==limit-1){
        printf("Stack is full\n");
        return -1;
    }
    stack[++index]=data;
    return 0;
}

int topelement(){
    if(index==-1){
        printf("Stack is empty\n");
        return -1;
    }
    return stack[index];
}

int isempty(){
    if(index==-1){
        return 1;
    }
    return 0;
}

int size(){
    return index+1;
}

int isfull(){
    if(index==limit-1){
        return 1;
    }
    return 0;
}


typedef struct node {
    int data;
    int datacount;
    struct node *left;
    struct node *right;
} Node;


Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->datacount = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }else if(data > root->data){
        root->right = insert(root->right, data);
    }
    else{
        root->datacount++;
    }
    return root;
}

Node *search(Node *root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    if(data < root->data){
        return search(root->left, data);
    }
    return search(root->right, data);
}

// search function 

Node *minValueNode(Node *node){
    Node *current = node;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}

Node *maxValueNode(Node *node){
    Node *current = node;
    while(current && current->right != NULL){
        current = current->right;
    }
    return current;
}

void inorder(Node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

Node *deleteNode(Node *root, int data){
    if(root == NULL){
        return root;
    }
    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }else{
        if(root->datacount > 1){
            root->datacount--;
            return root;
        }
        if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderstack(Node * head){
    stack=(int *)malloc(sizeof(int)*limit);
    Node *current=head;
    while(1){
        while(current!=NULL){
            push(current->data);
            current=current->left;
        }
        if(isempty()){
            break;
        }
        current=search(head,pop());
        printf("%d ",current->data);
        current=current->right;
    }
    printf("\n");
    free(stack);
    return;
}


void freehead(Node *head){
    if(head==NULL){
        return;
    }
    freehead(head->left);
    freehead(head->right);
    free(head);
    return;
}

void postorderstack(Node * head){
    stack=(int *)malloc(sizeof(int)*limit);
    Node *current=head;
    Node *prev=NULL;
    do{
        while(current!=NULL){
            push(current->data);
            current=current->left;
        }
        while(current==NULL && !isempty()){
            current=search(head,topelement());
            if(current->right==NULL || current->right==prev){
                printf("%d ",current->data);
                prev=current;
                pop();
                current=NULL;
            }
            else{
                current=current->right;
            }
        }
    }
    while(!isempty());
    printf("\n");
    free(stack);
    return;
}

int main(){
    Node *root = NULL;
    Node *newNode = (Node *)malloc(sizeof(Node));
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    // inorder(root);
    // printf("\n");
    // preorder(root);
    // printf("\n");
    // postorder(root);
    // printf("\n");
    // inorderstack(root);
    freehead(root);
    scanf("%d", &k);
    noofpossbt(k-1);
    printf("%d\n", count);
    return 0;
    //inorder means 
}