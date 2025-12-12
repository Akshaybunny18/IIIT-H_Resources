#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
    int count;
    int children;
    int level;
    int rc;
    int lc;
} Node;

Node* createnode (int data,int l){
    Node * newnode=malloc(sizeof(Node));
    newnode->data=data;
    newnode->level=l;
    newnode->count=1;
    newnode->children=0;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->rc=0;
    newnode->lc=0;
    return newnode;
}

Node * root=NULL;
int nodes=0;
int min=0,max=0;
int *arr;
Node **stack;
int index=-1,limit=1000;
int front=-1,rear=-1;
Node** q;
int flag=0;

int compare(const void *a, const void *b) {
    return (*(int *)a > *(int *)b); //-
}

int isemptyq(){
    return front ==-1 && rear ==-1; 
}

int isfullq(){
   return  (rear+1)%limit==front;
}

int enq(Node* temp){
    if(isfullq()) return 0;
    else if(isemptyq()){
        front = rear=0;
        q[rear]=temp;
        return 1;
    }
    else 
    if(!isfullq()){
        rear=(rear+1)%limit;
        q[rear]=temp;
        return 1;
    }
    return 0;
}

Node* dq(){
    if(isemptyq()) return NULL;
    else if(front==rear){
        int t=rear;
        front=rear=-1;
        return q[t];
    }
    else {
        int t = front;
        front=(front+1)%limit;
        return q[t];
    }
}

int isempty(){
    return index==-1;
}

int isfull(){
    return index==limit;
}

Node * pop(){
    if(isempty()){
        return NULL;
    }
    return stack[index--];
}

int push(Node* data){
    if(isfull()){
        return -1;
    }
    stack[++index]=data;
    return 1;
}

void display(){
    for(int i=0;i<=index;i++){
        printf("%d ",(stack[i])->data);
    }
}

void insert(int data){
    if(!root){
        root=createnode(data,0);
    }
    else{
        Node * temp = root;
        while(temp){
            if(temp->data==data){
                temp->count++;
                break;
            }
            else if(data<temp->data){
                temp->children++;
                temp->lc++;
                int l=temp->level;
                if(temp->left){
                    temp=temp->left;
                }
                else{
                    temp->left=createnode(data,l+1);
                    break;
                }
            }
            else if (data>temp->data){
                temp->rc++;
                temp->children++;
                int l=temp->level;
                if(temp->right){
                    temp=temp->right;
                }
                else{
                    temp->right=createnode(data,l+1);
                    break;
                }
            }
        }
    }
}

void levelorder(Node * temp){
    if(!temp) return ;
    front=rear=-1;
    enq(temp);
    while(!isemptyq()){
        Node * t = dq();
        if(t->left) enq(t->left);
        if(t->right) enq(t->right);
        printf("%d ",t->data);
    }

}


Node* delete(Node* temp, int data) {
    if (!temp) return NULL;

    // Decrement children count before making recursive calls
    temp->children--;  

    if (data < temp->data) {
        temp->lc--;
        temp->left = delete(temp->left, data);
    } 
    else if (data > temp->data) {
        temp->rc--;
        temp->right = delete(temp->right, data);
    } 
    else { 
        // Node with only one child or no child
        temp->rc--;
        if (!temp->left) {
            Node* newNode = temp->right;
            free(temp);
            return newNode;
        } 
        else if (!temp->right) {
            Node* newNode = temp->left;
            free(temp);
            return newNode;
        }

        // Node with two children: Find in-order successor (smallest in right subtree)
        Node* successor = temp->right;
        while (successor->left) {
            successor = successor->left;
        }

        // Copy the successor's value to current node
        temp->data = successor->data;

        // Delete the successor node
        temp->right = delete(temp->right, successor->data);
    }

    return temp;
}

// Node* delete(Node * temp,int data){
//     if(!temp) return NULL;
//     if(data<temp->data) {
//         temp->children--;
//         temp->left=delete(temp->left,data);
//     }
//     else if(data>temp->data){
//         temp->children--;
//         temp->right=delete(temp->right,data);
//     }
//     else{
//         // if(temp->count>1 && 0){
//         //     temp->count--;
//         //     return temp;
//         // }
//         // else
//         if(!temp->right){
//             Node* newnode = temp->left;
//             free(temp);
//             return newnode;
//         }
//         else if(!temp->left){
//             Node* newnode=temp->right;
//             free(temp);
//             return newnode;
//         }
//         // temp->children--;
//         Node* newnode = temp->right;
//         // Node * t;
//         while(newnode->left) {
//             // newnode->children--;
//             // t=new;
//             newnode=newnode->left;
//         }
//         // temp->count=new->count;
//         // temp->children-=new->count;
//         temp->data=newnode->data;
//         temp->children--;
//         temp->right=delete(temp->right,newnode->data);
//         return temp;
//         // Node * temp3=temp;
//         // if(!temp->right->left){
//         //     temp->right=temp->right->right;
//         // }
//         // else{
//         //     t->left=new->right;
//         // }
//         // // else{
//         // //     temp=temp->right;
//         // //     // temp->children-=new->count;
//         // //     Node * temp2;
//         // //     while(temp->left==new->data){
//         // //         temp->children-=new->count;
//         // //         temp2=temp;
//         // //         temp=temp->left;
//         // //     }
//         // //     temp2->left=NULL;
//         // // }
//         // return temp3;
//     }
// }

Node* predecessor(int data){
    Node * temp=root;
    Node* temp1=NULL;
    while(temp){
        if(data==temp->data) break;
        else if(data<temp->data) temp=temp->left;
        else{
            temp1=temp;
            temp=temp->right;
        }
    }
    if(!temp) return NULL;
    else if(!temp->left) return temp1;
    else{
        temp=temp->left;
        while(temp->right) temp=temp->right;
        return temp;
    }
    return NULL;
}

Node * successor(int data){
    Node * temp=root;
    Node* temp1=NULL;
    while(temp){
        if(data==temp->data){
            break;
        }
        else if(data<temp->data){
            temp1=temp;
            temp=temp->left;
        }
        else{
            // temp1=temp;
            temp=temp->right;
        }
    }
    if(!temp) return NULL;
    else if(!temp->right) return temp1;
    else{
        temp=temp->right;
        while(temp->left) temp=temp->left;
        return temp;
    }
    return NULL;   
}

void sortinsert(int l,int r){
    if(l<=r){
        int m=(l+r)/2;
        insert(arr[m]);
        sortinsert(l,m-1);
        sortinsert(m+1,r);
    }
}

void inorder(Node*temp){
    if(!temp)return ;
    inorder(temp->left);
    printf("%d-%d-%d-%d ",temp->data,temp->level,temp->rc,temp->count);
    inorder(temp->right);
}

void swapnodes(Node *temp){
    if(!temp) return;
    Node * temp1=temp->left;
    temp->left=temp->right;
    temp->right=temp1;
    swapnodes(temp->left);
    swapnodes(temp->right);
}

void merge(int l,int r){
    if(l>=r) return;
    int m=(l+r)/2,b[r-l+1],i=l,j=m+1,k=0;
    merge(l,m),merge(m+1,r);
    while(i<=m&&j<=r) b[k++]=arr[i]>arr[j]?arr[j++]:arr[i++];
    while(i<=m) b[k++]=arr[i++];
    while(j<=r) b[k++]=arr[j++];
    for(int i=l,k=0;i<=r;i++) arr[i]=b[k++];
}

void me13(int l, int r) {
    if (r - l < 2) return;
    int m = l + (r - l) / 1.3, b[r - l + 1], i = l, j = m, k = 0;
    me13( l, m), me13( m, r);
    while (i < m && j < r) b[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    while (i < m) b[k++] = arr[i++];
    while (j < r) b[k++] = arr[j++];
    for (i = 0; i < k; i++) arr[l + i] = b[i];
}

void checkbstsame(Node* temp1,Node*temp2){
    if(flag==1){
        return;
    }
    if(!temp1 && !temp2){
        return ;
    }
    else if(!temp1 || !temp2 ){
        flag=1;
        return;
    }
    else if(temp1 && temp2){
        if(temp1->data!=temp2->data) {
            flag=1;
            return;
        }
        checkbstsame(temp1->left,temp2->left);
        checkbstsame(temp1->right,temp2->right);
    }
}

void paths(Node* temp){
    if(!temp) return ;
    push(temp);
    if(!temp->right && !temp->right) {
        display();
        printf("\n");
        // index=0;
        pop();
        return;
    }
    paths(temp->left);
    paths(temp->right);
    pop();
}

int mthstrongest(int m) {
    Node *curr = root;
    while (curr != NULL) {
        if (curr->rc >= m) {
            curr = curr->right;
        } else if (curr->rc + curr->count >= m) {
            return curr->data;
        } else {
            m -= (curr->rc + curr->count);
            curr = curr->left;
        }
    }
    return -1; // m is larger than total nodes
}
//level order
//qsort
//stack
//queue
// bst bt
// target recah with -ve addition and multipliacation

void freeT(Node * temp){
    if(!temp) return ;
    freeT(temp->left);
    freeT(temp->right);
    free(temp);
}

void postorder(Node * temp){
    if(!temp) return;
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->data);
}

void preorder(Node* temp){
    if(!temp) return ;
    printf("%d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

Node* find(int data){
    Node * temp=root;
    while(temp){
        if(data==temp->data){
            return temp;
        }
        else if(data<temp->data){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return NULL;
}

void print(int *a,int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}


int main(){
    int n;
    scanf("%d",&n);
    arr=malloc(sizeof(int)*n);
    q=malloc(sizeof(Node*)*n);
    stack=malloc(sizeof(Node*)*n);
    limit=n+1;
    root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(min>arr[i]) min=arr[i];
        if(max<arr[i]) max=arr[i];
    }
    // rand();
    // srand(time(NULL));
    // qsort(arr, n, sizeof(int), compare);
    // print(arr,n);
    // merge(0,n-1);
    // print(arr,n);
    me13(0,n-1);
    print(arr,n);
    // for(int i=n-1;i>=0;i++){
    //     int k
    //     int k= rand()%n;
    //     k= rand()%(i+1);
    //     int t = arr[i];
    //     arr[i]=arr[k];
    //     arr[k]=t;
    // }

    // for(int i=0;i<n;i++){
    //     insert(arr[i]);
    // }
    sortinsert(0,n-1);
    // delete(root,12);
    inorder(root);
    printf("\n");
    levelorder(root);
    printf("\n");
    paths(root);
    checkbstsame(root,root->right);
    printf("%d",flag);
    freeT(root);
    free(q);
    free(stack);
    free(arr);
}





