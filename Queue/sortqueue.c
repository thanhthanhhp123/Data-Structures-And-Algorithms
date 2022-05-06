#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct linkedList {
	int data;
	struct linkedList *next;
};

typedef struct linkedList node;

struct Queue {
	int size;
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

bool empty(queue *q) {
	if(q->front == NULL && q->rear == NULL) {
		return true;
	} else {
		return false
	}
}

void init(queue *q) {
	q->front = NULL;
	q->rear = NULL;
}

void push(queue *q, int value) {
	node *p = createNode(value);
	if(empty(q)) {
		q->front = q->rear = p;
	} else {
		q->rear->next = p;
		q->rear = p;
	}
	q->size++;
}

int pop(queue *q) {
	node *p;
	int n = q->front->data;
	p = q->front;
	q->front = q->front->next;
	q->size--;
	free(p);
	return n;
}

void display(node *l) {
	if(l == NULL) {
		printf("\nNothing");
	} else {
		printf("%d ",l->data);
		display(l->next);
	}
}


void sort(queue *q) {
	node **p, *this;
	if(empty(q)) {
		printf("The queue is empty");
	} else {
		for(pp = &q->front; this = *pp; pp = &(*pp)->next){
        node *other = this->next;
            if (!this->next) break;
            if (this->data < other->data) continue;
            *pp = other;              
            this->next = other->next;
            other->next = this;       
        }
	}
}

int main() {
	queue *q;
	q = malloc(sizeof(struct linkedList));
	init(q);
	push(q, 10);
	push(q, 1);
	push(q, 5);
	display(q->front);
}