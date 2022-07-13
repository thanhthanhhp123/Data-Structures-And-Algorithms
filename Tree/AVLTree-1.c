#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int findMax(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

struct BTnode {
    int data;
    struct BTnode *right;
    struct BTnode *left;
    int height;
};

typedef struct BTnode node;

int getHeight(node *t) {
    if(t == NULL) {
        return 0;
    } else {
        return 1 + findMax(getHeight(t->left), getHeight(t->right));
    }
}

node *createNode(int value) {
    node *p = malloc(sizeof(struct BTnode));
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

node *insert(node* node, int key) 
{ 
    if (node == NULL) return createNode(key); 
  
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key);    
  
    return node; 
} 

node *rightRotate(node *t) {
    node *x = t->left;
    t->left = x->right;
    x->right = t;
    t->height = 1 + findMax(getHeight(t->left), getHeight(t->right));
    x->height = 1 + findMax(getHeight(x->left), getHeight(x->right));
    return x;
}

node *leftRotate(node* root) {
    node* y = root->right;
    root->right = y->left;
    y->left = root;
    root->height = 1 + findMax(getHeight(root->left), getHeight(root->right));
    y->height = 1 + findMax(getHeight(y->left), getHeight(y->right));
    return y;
}

void printTree(node *root) 
{ 
    if (root != NULL) 
    { 
        printTree(root->left); 
        printf("%d \n", root->data); 
        printTree(root->right); 
    } 
}

int main() {
    
}