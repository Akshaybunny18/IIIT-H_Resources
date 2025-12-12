#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include <limits.h>


int cmp(const void*a,const void *b){
    // return *(int *)a-*(int* )b;
    const int *p1 = (const int *)a;
    const int *p2 = (const int *)b;

    if(p1[0]!=p2[0])
        return p1[0]-p2[0];
    return p1[1]-p2[1];
}

// structure of the tree node
typedef struct node {
    int data;
    // int st;
    // int end;
    struct node* left;
    struct node* right;
    int ht;
}node ;

int y;
int no=0;
node * rooot=NULL;
// int flg=1;
// function prototyping
struct node* create(int); // Creates a new tree node with the given data and returns it
void insert(struct node*, int); // Inserts a new node in the AVL tree and returns the root of the tree
struct node* delete(struct node*, int); // Deletes *one* occurrence of the given data from the AVL tree, does nothing if the data is not found and returns the root of the tree
struct node* search(struct node*, int); // Searches for the given data in the AVL tree, returns the node if found, NULL otherwise
struct node* rotate_left(struct node*); // Rotates the tree rooted at the given node to the left and returns the new root
struct node* rotate_right(struct node*); // Rotates the tree rooted at the given node to the right and returns the new root
int balance_factor(struct node*); // returns the balance factor of the given node
int height(struct node*); // returns the height of the given node
  
struct node* create(int data) {
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
    assert(new_node != NULL);
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

//  node * root=NULL;


void inorder(node *cur) {
    if (!cur) return;
    inorder(cur->left);
    printf("%d ", cur->data);
    inorder(cur->right);
}

node* successor(node *temp, int data) {
    if (!temp) return NULL;

    if (temp->right) {
        temp = temp->right;
        while (temp->left) temp = temp->left;
        return temp;
    }

    node *succ = NULL, *cur = rooot;
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

struct node* rotate_left(struct node* root) {
    struct node* right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;
  
    // update the heights of the nodes
    root->ht = height(root);
    right_child->ht = height(right_child);
  
    // return the new node after rotation
    return right_child;
}
  
struct node* rotate_right(struct node* root) {
    struct node* left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;
  
    // update the heights of the nodes
    root->ht = height(root);
    left_child->ht = height(left_child);
  
    // return the new node after rotation
    return left_child;
}
 
int balance_factor(struct node* root) {
    int lh, rh;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    return lh - rh;
}
  
int height(struct node* root) {
    int lh, rh;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    if (lh > rh)
        return (lh);
    return (rh);
}
  
 
struct node* delete(struct node* root, int x) {
    if (root == NULL) {
        return NULL;
    }
 
    if (x < root->data) {
        root->left = delete(root->left, x);
    } else if (x > root->data) {
        root->right = delete(root->right, x);
    } else { // Found the node to delete
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        } else {
            // Find successor (smallest value in right subtree)
            struct node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
 
            // Replace data with successor value
            root->data = temp->data;
 
            // Delete the duplicate node from the right subtree
            root->right = delete(root->right, temp->data);
        }
    }
 
    // Update height
    root->ht = height(root);
 
    // Balance the tree
    int bf = balance_factor(root);
 
    if (bf == 2) {
        if (balance_factor(root->left) >= 0) {
            root = rotate_right(root);
        } else {
            root->left = rotate_left(root->left);
            root = rotate_right(root);
        }
    } else if (bf == -2) {
        if (balance_factor(root->right) <= 0) {
            root = rotate_left(root);
        } else {
            root->right = rotate_right(root->right);
            root = rotate_left(root);
        }
    }
 
    return root;
}
  
struct node* search(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }
  
    if (root->data == key) {
        return root;
    }
  
    if (key > root->data) {
        return search(root->right, key);
    } else {
        return search(root->left, key);
    } 
}


struct node* insert1(struct node* root, int data) {
    if (root == NULL) {
        struct node* new_node = create(data);
        // if(!rooot) rooot=new_node;
        if (new_node == NULL) {
            return NULL;
        }
        root = new_node;
    } else if (data < root->data) {
        // Insert into left subtree
        root->left = insert1(root->left, data);
        // Balance the tree
        if (balance_factor(root) == 2) {
            if (data < root->left->data) {
                root = rotate_right(root);
            } else {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    } else {
        // Insert into right subtree
        root->right = insert1(root->right, data);
 
        // Balance the tree
        if (balance_factor(root) == -2) {
            if (data >= root->right->data) {
                root = rotate_left(root);
            } else {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    }
 
    // Update height
    root->ht = height(root);
    return root;
}
  

void insert(struct node* root, int data) {
    while(1){
        if (root == NULL) {
            rooot=insert1(rooot,y);
            // printf("%d\n",y);
            no++;
            break;
        } else if (data <= root->data) {
            root=root->left;
        } else if(data>root->data){
            // root=root->right;
        // }
        // else {
            // if(!root->right){
            //     node* t=successor(rooot,root->data);
            // // printf("he");
            //     if(!t){
            //         root->data=y;
            //         break;
            //     }
            //     rooot=delete(rooot,t->data);
            //     no--;
            //     root->data=t->data;
            //     rooot=insert1(rooot,y);
            //     no++;
            //     break;
            // }
            // else if(root->right->data>=data){
                // node* t=successor(rooot,root->data);
            // printf("he");
                // if(!t){
                //     root->data=y;
                //     break;
                // }
                rooot=delete(rooot,root->data);
                no--;
                // root->data=t->data;
                rooot=insert1(rooot,y);
                no++;
                break;
            // }
            // root=root->right;
        }
    }
}



int main(){
    int n;
    // node *root=NULL;
    scanf("%d",&n);
    int arr[n][2];
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i][0]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i][1]);
    }
    qsort(arr,n,sizeof(arr[0]),cmp);
    // for(int i=0;i<n;i++){
    //     printf("%d %d\n",arr[i][0],arr[i][1]);
    // }
    // qsort(arr, n, sizeof(int), cmp);        
    // qsort(a, n, sizeof(int), cmp);
    for(int i=0;i<n;i++){
        int x;
        x=arr[i][0];
        y=arr[i][1];
        // rooot=
        insert(rooot,x);
        // printf("\nhi");
        // inorder(rooot);
    }
    printf("%d\n",no);
}
