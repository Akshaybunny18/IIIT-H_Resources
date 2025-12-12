#include <stdio.h>
#include <stdlib.h>

typedef struct Node* Tree;
typedef Tree Set;

struct Node{
    int val;
    Tree left;
    Tree right;
    int height;
};

int max(Tree Node1, Tree Node2){
    if(!Node1 && !Node2)
        return -1;
    if(!Node1)
        return Node2->height;
    if(!Node2)
        return Node1->height;
    if(Node1->height>Node2->height)
        return Node1->height;
    else
        return Node2->height;
}

Set createSet(int val){
    Set s = (Set)malloc(sizeof(struct Node));
    s->left = NULL;
    s->right = NULL;

    s->height = 0;
    s->val = val;

    return s;
}

Tree RotateLeft(Tree root){
    Tree LNode = root->left;
    root->left = LNode->right;
    LNode->right = root;

    root->height = max(root->left,root->right)+1;
    LNode->height = max(LNode->left,LNode->right)+1;

    return LNode;
}

Tree RotateRight(Tree root){
    Tree RNode = root->right;
    root->right = RNode->left;
    RNode->left = root;

    root->height = max(root->left,root->right)+1;
    RNode->height = max(RNode->left,RNode->right)+1;

    return RNode;
}

Tree DoubleRotateLeft(Tree root){
    root->left = RotateRight(root->left);
    root = RotateLeft(root);

    return root;
}

Tree DoubleRotateRight(Tree root){
    root->right = RotateLeft(root->right);
    root = RotateRight(root);

    return root;
}

int height(Tree Node){
    if(!Node)
        return -1;
    return Node->height;
}


Tree insert(int val, Tree root){
    if(!root)
        return createSet(val);
    
    if(root->val > val){
        root->left = insert(val, root->left);
    }
    else if(root->val < val){
        root->right = insert(val, root->right);
    }
    else
        return root;
    
    root->height = max(root->left,root->right)+1;
    
    if(height(root->left) - height(root->right) < -1 || height(root->left) - height(root->right) > 1){
        if(root->left && val<root->left->val)
            root = RotateLeft(root);

        else if(root->right && val>root->right->val)
            root = RotateRight(root);

        else if(root->left && val>root->left->val)
            root = DoubleRotateLeft(root);

        else if(root->right && val<root->right->val)
            root = DoubleRotateRight(root);
    }

    return root;
}

int find(int val, Set s){
    if(!s)
        return 0;
    if(s->val == val)
        return 1;
    if(val<s->val)
        return find(val, s->left);
    else
        return find(val, s->right);
}

int main(int argc, char const *argv[])
{
    Set s = NULL;
    int arr[] = {2,5,6,3,7,3,4,5,6,2,1,4,6,8};
    for(int i = 0; i<14;i++){
        s = insert(arr[i], s);
    }

    return 0;
}
