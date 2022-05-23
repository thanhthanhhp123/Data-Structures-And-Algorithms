#include<stdio.h>
#include<stdlib.h>

struct BTnode {
    int data;
    struct BTnode *right;
    struct BTnode *left;
};

typedef struct BTnode node;

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
    node *p = NULL;
    p = insert(p, 3);
    insert(p, 5);
    insert(p, 1);
    insert(p, 8);
    printTree(p);
}
