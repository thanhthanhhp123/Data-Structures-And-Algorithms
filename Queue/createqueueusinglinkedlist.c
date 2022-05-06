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

bool empty(queue *q) {
	if(q->front == NULL && q->rear == NULL) {
		return true;
	} else {
		return false;
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
}

int pop(queue *q) {
	node *p;
	int n = q->front->data;
	p = q->front;
	q->front = q->front->next;
	free(p);
	return n;
}

void display(node *l) {
	for(l; l != NULL; l=l->next) {
   		if(l == NULL) {
    		printf("Nothing");
      		break;
    	} else {
      		printf("%d ",l->data);
    	}
  }
}

int main() {
	queue *q;
	q = malloc(sizeof(queue));
	init(q);
	push(q, 10);
	display(q->front);
}
