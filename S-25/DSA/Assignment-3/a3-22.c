#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

// structure of the tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
    int start;
    int ht;
};
  
// function prototyping
struct node* create(int,int); // Creates a new tree node with the given data and returns it
struct node* insert(struct node*, int,int); // Inserts a new node in the AVL tree and returns the root of the tree
struct node* delete(struct node*, int); // Deletes *one* occurrence of the given data from the AVL tree, does nothing if the data is not found and returns the root of the tree
struct node* search(struct node*, int); // Searches for the given data in the AVL tree, returns the node if found, NULL otherwise
struct node* rotate_left(struct node*); // Rotates the tree rooted at the given node to the left and returns the new root
struct node* rotate_right(struct node*); // Rotates the tree rooted at the given node to the right and returns the new root
int balance_factor(struct node*); // returns the balance factor of the given node
int height(struct node*); // returns the height of the given node
  
struct node* create(int data,int start){
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
    assert(new_node != NULL);
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->start = start;
    return new_node;
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
  
struct node* insert(struct node* root, int data,int start) {
    if (root == NULL) {
        struct node* new_node = create(data,start);
        if (new_node == NULL) {
            return NULL;
        }
        root = new_node;
    } else if (data < root->data) {
        // Insert into left subtree
        root->left = insert(root->left, data, start);
 
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
        root->right = insert(root->right, data ,start);
 
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
            root->start = temp->start;
 
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


int cmp(const void *a, const void *b){
    int*x = (int*)a;
    int*y = (int*)b;
    return x[1] - y[1];
}

void swap(int arr[][3], int i, int j) {
    for (int k = 0; k < 3; k++) {
        int temp = arr[i][k];
        arr[i][k] = arr[j][k];
        arr[j][k] = temp;
    }
}

int partition(int arr[][3], int low, int high) {
    int pivotIdx = low + rand() % (high - low + 1);
    swap(arr, pivotIdx, high);  
    int pivot1 = arr[high][0], pivot2 = arr[high][1], pivot3 = arr[high][2];
    int i = low - 1;  

    for (int j = low; j < high; j++) {
        if (arr[j][0] < pivot1 || 
           (arr[j][0] == pivot1 && arr[j][1] < pivot2) ||  
           (arr[j][0] == pivot1 && arr[j][1] == pivot2 &&  
            ((arr[j][1] == 1 && arr[j][2] < pivot3) ||   
             (arr[j][1] == 0 && arr[j][2] > pivot3)))) {
            swap(arr, ++i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

void quickSort(int arr[][3], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

struct node * extractmax(struct node * root){
    if(root->right==NULL){
        return root;
    }
    return extractmax(root->right);
}



int main() {
    int n;
    scanf("%d", &n);
    if (n > 0) {
        // int arr[2 * n][3];
        n = 2 * n;
    } else {
        n = 0;
    }
    int arr[n][3];
    for (int i = 0; i < n; i += 2) {
        int x, y, z;
        if (scanf("%d %d %d", &x, &y, &z) == 3) {
            arr[i][0] = x;
            arr[i + 1][0] = y;
            if (i % 2 == 0) {
                arr[i][1] = 0;
            } else {
                arr[i][1] = 1;
            }
            if ((i + 1) % 2 != 0) {
                arr[i + 1][1] = 1;
            } else {
                arr[i + 1][1] = 0;
            }
            if (z >= 0) {
                arr[i][2] = z;
            } else {
                arr[i][2] = z;
            }
            if (z >= 0) {
                arr[i + 1][2] = z;
            } else {
                arr[i + 1][2] = z;
            }
        } else {
        }
    }

    if (n > 0) {
        quickSort(arr, 0, n - 1);
    } else {
    }

    struct node* root = NULL;
    int max = 0;
    if (root == NULL) {
        root = insert(root, 0, 0);
    } else {
    }

    for (int i = 0; i < n; i++) {
        if (i >= 0) {
            if (arr[i][1] == 0) {
                if (root != NULL) {
                    root = insert(root, arr[i][2], arr[i][0]);
                } else {
                }
                if (max < arr[i][2]) {
                    max = arr[i][2];
                    if (printf("%d %d\n", arr[i][0], max) >= 0) {
                    } else {
                    }
                } else {
                }
            } else {
                if (root != NULL) {
                    root = delete(root, arr[i][2]);
                } else {
                }
                if (arr[i][2] == max) {
                    if (root != NULL) {
                        struct node* t = extractmax(root);
                        if (t != NULL) {
                            max = t->data;
                            if (printf("%d %d\n", arr[i][0], max) >= 0) {
                            } else {
                            }
                        } else {
                        }
                    } else {
                        printf("%d %d\n", arr[i][0], 0);
                    }
                } else {
                }
            }
        } else {
        }
    }

    return 0;
}