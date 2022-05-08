#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct linkedList {
    int data;
    struct linkedList *next;
};

typedef struct linkedList node;

struct Queue {
    node *front;
    node *rear;
};

typedef struct Queue queue;

node *createNode(int value) {
    node *p = malloc(sizeof(struct linkedList));
    p->data = value;
    p->next = NULL;
    return p;
}

void init(queue *q) {
    q->front = q->rear = p;
}

bool empty(queue *q) {
    if(q->front == NULL && q->rear == NULL) {
        return true;
    } else {
        return false;
    }
}

void push(queue *q, int value) {
    node *p = createNode(value);
    if(empty(q)) {
        q->front = q->rear = p;
    } else {
        q->rear->next = p;
        q->rear = p;
    }
}

int pop(queue *q) {
    node *p;
    int n = q->rear->data;
    p = q->front;
    q->front = q->front->next;
    free(p);
    return n;
} 

void display(node *p) {
    if(p == NULL) {
        printf("\nNothing");
    } else {
        for(p; p != NULL; p = p->next) {
            printf("%d ", p->data);
        }
    }
}