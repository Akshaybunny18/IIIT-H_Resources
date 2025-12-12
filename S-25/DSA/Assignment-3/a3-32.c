#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
    // int count;
    long long int sum;
    int rc;
    int lc;
} Node;

Node* createnode (int data){
    Node * newnode=malloc(sizeof(Node));
    newnode->data=data;
    // newnode->count=1;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->rc=0;
    newnode->lc=0;
    newnode->sum=0;
    return newnode;
}

Node * root=NULL;
int nodes=0;
int min=0,max=0;
int *arr;
int m=0;


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

void insert(int data){
    if(!root){
        root=createnode(data);
    }
    else{
        Node * temp = root;
        while(temp){
            // if(temp->data==data){
            //     temp->count++;
            //     break;
            // }
            // else 
            if(data<temp->data){
                temp->lc++;
                temp->sum+=data;
                if(temp->left){
                    temp=temp->left;
                }
                else{
                    temp->left=createnode(data);
                    break;
                }
            }
            else {//if (data>temp->data){
                temp->rc++;
                if(temp->right){
                    temp=temp->right;
                }
                else{
                    temp->right=createnode(data);
                    break;
                }
            }
        }
    }
}

Node* delete(Node* temp, int data) {
    if (!temp) return NULL;
    if (data < temp->data) {
        temp->lc--;
        temp->sum-=data;
        temp->left = delete(temp->left, data);
    } else if (data > temp->data) {
        temp->rc--;
        temp->right = delete(temp->right, data);
    } else {
        // if(temp->count>1){
        //     temp->count--;
        //     return temp;
        // }
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
        Node* successorParent = temp;
        Node* successor = temp->right;
        while (successor->left) {
            successorParent = successor;
            successor = successor->left;
        }
        temp->rc-=1;//successor->count;
        Node* current = temp->right;
        if(current!=successor){
            while(current->left){
                current->sum-=successor->data*1;//successor->count;
                current->lc-=1;//successor->count;
                current=current->left;
            }
        }
        temp->data = successor->data;
        // temp->count = successor->count;
        if(successorParent==temp){
            temp->right=successor->right;
        }
        else{
            successorParent->left = successor->right;
        }
        free(successor);
    }
    return temp;
}

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

void merge(int l,int r){
    if(l>=r) return;
    int m=(l+r)/2,b[r-l+1],i=l,j=m+1,k=0;
    merge(l,m),merge(m+1,r);
    while(i<=m&&j<=r) b[k++]=arr[i]>arr[j]?arr[j++]:arr[i++];
    while(i<=m) b[k++]=arr[i++];
    while(j<=r) b[k++]=arr[j++];
    for(int i=l,k=0;i<=r;i++) arr[i]=b[k++];
}

void freeT(Node * temp){
    if(!temp) return ;
    freeT(temp->left);
    freeT(temp->right);
    free(temp);
}

void inorder(Node*temp){
    if(!temp)return ;
    inorder(temp->left);
    printf("%d\n",temp->data);
    inorder(temp->right);
}


long long int mthstrongest(int k){
    Node* curr = root;
    long long int sum=0;
    while (curr!=NULL) {
        if (curr->rc + 1 >= k && curr->rc < k){
            return sum+=curr->data+curr->sum;
        }
        else if (curr->rc >= k){
            sum+=curr->data+curr->sum;
            curr = curr->right;
        }
        else {
            k -= curr->rc + 1;
            curr = curr->left;
        }
    }
    return sum;
}   

long long int mthsmallest(int k) {
    Node* curr = root;
    long long int sum = 0;
    while (curr != NULL) {
        if (curr->lc + 1 >= k && curr->lc < k) {
            return sum += curr->data + curr->sum;
        } else if (curr->lc >= k) {
            curr = curr->left;
        } else {
            sum += curr->data + curr->sum;
            k -= curr->lc + 1;
            curr = curr->right;
        }
    }
    return sum;
}


int main(){
    int n;
    scanf("%d %d",&n,&m);
    int kk=n;
    arr=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    merge(0,n-1);
    sortinsert(0,n-1);
    // inorder(root);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int a,p,r;
        scanf("%d",&a);
        if(a==1){
            scanf("%d",&p);
            kk++;
            insert(p);
        }
        else if(a==2){
            scanf("%d",&p);
            root=delete(root,p);
            kk--;
        }
        else if(a==3){
            scanf("%d %d",&p,&r);
            delete(root,p);
            insert(r);
        }
        // printf("n is %d\n",kk);
        long long int sum=mthstrongest(kk-m+1);
        long long int sum1=mthsmallest(m);
        // inorder(root);
        // printf("\n");
        if(sum1==sum){
            printf("%lld\n",sum);
        }
        else{
            printf("%lld\n",sum1);
        }
    }
}