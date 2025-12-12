#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
    long long int lsum;
    int ht;
    int lc;
    long long int rsum;
    int rc;
} node;

struct node* create(int);
struct node* insert(struct node*, int);
struct node* delete(struct node*, int);
struct node* search(struct node*, int);
struct node* rotate(struct node*, int); // Single rotate function with direction parameter
int balancefactor(struct node*);
int height(struct node*);

struct node* create(int data) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    assert(newnode != NULL);
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->lsum = 0;
    newnode->rsum = 0;
    newnode->ht = 1;
    newnode->lc = 0;
    newnode->rc = 0;
    return newnode;
}

long long subtreesum(node* root) {
    if (!root) {
        return 0;
    }
    return root->data + root->lsum + root->rsum;
}

int subtreecount(node* root) {
    if (!root) {
        return 0;
    }
    return 1 + root->lc + root->rc;
}

void updatenode(node* n) {
    if (!n) {
        return;
    }
    
    n->ht = height(n);
    
    if (n->left) {
        n->lc = subtreecount(n->left);
        n->lsum = subtreesum(n->left);
    } else {
        n->lc = 0;
        n->lsum = 0;
    }
    
    if (n->right) {
        n->rc = subtreecount(n->right);
        n->rsum=subtreesum(n->right);
    } else {
        n->rc = 0;
        n->rsum=0;
    }
}

struct node* rotate(struct node* root, int direction) {
    struct node* child;
    if (direction == 0) { // Left rotation
        child = root->right;
        root->right = child->left;
        child->left = root;
    } else { // Right rotation
        child = root->left;
        root->left = child->right;
        child->right = root;
    }
  
    updatenode(root);
    updatenode(child);
  
    return child;
}

int balancefactor(struct node* root) {
    int lh, rh;
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL) {
        lh = 0;
    } else {
        lh = 1 + root->left->ht;
    }
    if (root->right == NULL) {
        rh = 0;
    } else {
        rh = 1 + root->right->ht;
    }
    return lh - rh;
}
  
int height(struct node* root) {
    int lh, rh;
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL) {
        lh = 0;
    } else {
        lh = 1 + root->left->ht;
    }
    if (root->right == NULL) {
        rh = 0;
    } else {
        rh = 1 + root->right->ht;
    }
    if (lh > rh) {
        return lh;
    }
    return rh;
}
  
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        struct node* newnode = create(data);
        if (newnode == NULL) {
            return NULL;
        }
        root = newnode;
    } else if (data < root->data) {
        root->lc++;
        root->lsum += data;
        root->left = insert(root->left, data);
        
        
    } else {
        root->rc++;
        root->rsum+=data;
        root->right = insert(root->right, data);
    }
    updatenode(root);  

    if (balancefactor(root) == 2) {
        if (data < root->left->data) {
            root = rotate(root, 1); // Right rotation
        } else {
            root->left = rotate(root->left, 0); // Left rotation
            root = rotate(root, 1); // Right rotation
        }
    }

    if (balancefactor(root) == -2) {
        if (data >= root->right->data) {
            root = rotate(root, 0); // Left rotation
        } else {
            root->right = rotate(root->right, 1); // Right rotation
            root = rotate(root, 0); // Left rotation
        }
    }
    
    root->ht = height(root);
    return root;
}
  
struct node* delete(struct node* root, int x) {
    if (!root) {
        return NULL;
    }
 
    if (x < root->data) {
        root->lc--;
        root->lsum -= x;
        root->left = delete(root->left, x);
    } else if (x > root->data) {
        root->rc--;
        root->rsum-=x;
        root->right = delete(root->right, x);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        } else {
            struct node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
 
            root->data = temp->data;
 
            root->right = delete(root->right, temp->data);
        }
    }
 
    root->ht = height(root);
    updatenode(root);
 
    int bf = balancefactor(root);
 
    if (bf == 2) {
        if (balancefactor(root->left) >= 0) {
            root = rotate(root, 1); // Right rotation
        } else {
            root->left = rotate(root->left, 0); // Left rotation
            root = rotate(root, 1); // Right rotation
        }
    } else if (bf == -2) {
        if (balancefactor(root->right) <= 0) {
            root = rotate(root, 0); // Left rotation
        } else {
            root->right = rotate(root->right, 1); // Right rotation
            root = rotate(root, 0); // Left rotation
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

long long int mthsmallest(node* root, int k) {
    node* curr = root;
    long long int sum = 0;
    while (curr != NULL) {
        if (curr->lc + 1 == k) {
            return sum += curr->data + curr->lsum;
        } else if (curr->lc >= k) {
            curr = curr->left;
        } else {
            sum += curr->data + curr->lsum;
            k -= curr->lc + 1;
            curr = curr->right;
        }
    }
    return sum;
}

long long int mthstrongest(node* root, int k) {
    node* curr = root;
    long long int sum = 0;
    while (curr != NULL) {
        if (curr->rc + 1 >= k ) {
            return sum += curr->data + curr->lsum;
        } else if (curr->rc >= k) {
            sum += curr->data + curr->lsum;
            curr = curr->right;
        } else {
            k -= curr->rc + 1;
            curr = curr->left;
        }
    }
    return sum;
}

int main() {
    int n, t, m;
    scanf("%d %d", &n, &m);
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        root = insert(root, t);
    }
    int q, a, p, r;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d", &p);
            n++;
            root = insert(root, p);
        } else if (a == 2) {
            scanf("%d", &p);
            root = delete(root, p);
            n--;
        } else if (a == 3) {
            scanf("%d %d", &p, &r);
            root = delete(root, p);
            root = insert(root, r);
        }
        long long int sum1 = mthsmallest(root, m);
        // long long int sum = mthstrongest(root, n - m + 1);
        // printf("%lld %lld\n", sum1, sum);
        printf("%lld\n", sum1);
    }
}