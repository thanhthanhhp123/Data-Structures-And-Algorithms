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

int countNode(node *t) {
    if(t == NULL) {
        return 0;
    } else {
        return 1 + countNode(t->left) + countNode(t->right);
    }
}

bool isLeafNode(node *t) {
    if(t->left == NULL && t->right == NULL) {
        return true;
    } else {
        return false;
    }
}

int treeLevel(node *t) {
    if(t == NULL)  {
        return -1;
    } else {
        return 1 + fmax(treeLevel(t->left), treeLevel(t->right));
    }
}

void deleteNode(node *t, int value) {
    if(t == NULL) {
        return;
    } else {
        if(value < t->data) {
            deleteNode(t->left, value);
        } else if(value > t->data) {
            deleteNode(t->right, value);
        } else {
            node *p = t;
            if(t->left == NULL) {
                t = t->right;
            } else if(->right == NULL) {
                t = t->left;
            }
            free(p);
        }
    }
}

int main() {
    node *p = NULL;
    p = insert(p, 3);
    insert(p, 5);
    insert(p, 1);
    insert(p, 8);
    printTree(p);
    printf("%d ",countNode(p));
}