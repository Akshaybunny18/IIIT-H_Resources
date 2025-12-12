#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * left;
    struct node * right;
} node ;

node * root = NULL;

node * createnode (int data){
    node * newnode=malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void insert(int data){
    if(!root){
        root=createnode(data);
        return;
    }
    node * temp=root;
    while(temp){
        if(temp->data>data){
            if(!temp->left){
                temp->left=createnode(data);
                break;
            }
            else {
                temp=temp->left;
            }
        }
        else {
            if(!temp->right){
                temp->right=createnode(data);
                break;
            }
            else {
                temp=temp->right;
            }
        }
    }
}

void inorder(node * temp){
    if(!temp) return ;
    inorder(temp->left);
    printf("%d ",temp->data);
    inorder(temp->right);
}

node * delete(node * temp,int data){
    if(!temp) return NULL;
    if(temp->data>data) temp->left=delete(temp->left,data);
    else if(temp->data<data) temp->right=delete(temp->right,data);
    else{
        if(!temp->left){
            return temp->right;
        }
        else if(!temp->right){
            return temp->left;
        }
        node * t=temp->right;
        while(t->left){
            t=t->left;
        }
        temp->data=t->data;
        printf("%d--",t->data);
        temp->right=delete(temp->right,t->data);
        // int k=t->data;
        // node * l=temp->right;
        // while(l->left->data!=k){
        //     l=l->left;
        // }
        // temp->data=k;
        // l->left=l->left->right;
        return temp;
    }
}




int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        insert(x);
    }
    // inorder(root);
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d",&a);
        if(a==1){
            scanf("%d",&b);
            insert(b);
            // inorder(root);

        }
        else if(a==2){
            node * temp1=root;
            node * temp2=root;
            while(temp1->right){
                temp1=temp1->right;
            }
            while(temp2->left){
                temp2=temp2->left;
            }
            printf("%d\n",temp1->data-temp2->data);
            // int g=temp2->data;
            // root=delete(root,temp1->data);
            //             inorder(root);
            // root=delete(root,g);
            if(root->data==temp1->data){
                root=root->left;
                // printf("hi");
            }
            else{
                node* temp=root;
                while(temp->right->data!=temp1->data){
                    temp=temp->right;
                }
                temp->right=temp->right->left;

            }
            if(root->data==temp2->data){
                root=root->right;
            }
            else {
                node* temp=root;
                while(temp->left->data!=temp2->data){
                    temp=temp->left;
                }
                temp->left=temp->left->right;
            }
            // inorder(root);
        }
    }
}