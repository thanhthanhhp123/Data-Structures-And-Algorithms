#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#ifndef QUEUE_MAX
#define QUEUE_MAX 100
#endif // !QUEUE_MAX
#include <limits.h>
#include<stdio.h>
#include <stdlib.h>


#ifdef ARRAY_QUEUE
typedef struct {
	int head,tail,count;
	int queue[QUEUE_MAX];
} *Queue;

Queue InitializeQueue() {
	Queue newqueue = (Queue)malloc(sizeof(Queue));
	newqueue->count = 0;
	newqueue->head = 0;
	newqueue->tail = 0;
	return newqueue;

}
void Put(Queue queue,int data) {
	if (queue->count >= QUEUE_MAX)return;
	if (queue->tail == QUEUE_MAX)queue->tail = 0;
	queue->queue[queue->tail++] = data;
	queue->count++;
}
int Get(Queue queue) {
	if (queue->count == 0)return INT_MIN;
	queue->count--;
	queue->head = queue->head == QUEUE_MAX ? 0 : queue->head;
	return queue->queue[queue->head++];
}

#endif // ARRAY_QUEUE
#ifndef ARRAY_QUEUE
typedef struct node {
	int data;
	struct node* next;
} *Node;


typedef struct {
	Node head, tail; int count;
} *Queue;

Queue InitializeQueue() {
	Queue newqueue = (Queue)malloc(sizeof(Queue));
	newqueue->head = newqueue->tail = NULL;
	newqueue->count = 0;
	return newqueue;
}
void Put(Queue queue,int data) {
	Node p = (Node)malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	queue->count++;
	if (queue->head == NULL) { queue->head = queue->tail = p; return; }
	queue->tail->next = p;
	queue->tail = queue->tail->next;
}
int Get(Queue queue) {
	if (queue->head == NULL)return INT_MIN;
	queue->count--;
	int tmp = (int)queue->head->data;
	Node tmpNode = queue->head;
	queue->head = queue->head->next;
	//free(tmpNode);
	return tmp;
}
int get_(Queue queue) {
	if (queue->head == NULL)return INT_MIN;
	queue->count--;
	int tmp = (int)queue->head->data;
	queue->head = queue->head->next;
	return tmp;
}
void Print(Node start) {
	printf("\nLinked list node: ");
	for (Node node = start; node != NULL; node = node->next)printf("%d ", node->data);
}
Node Index(Node start,int inx) {
	if (start == NULL || inx < 0)return NULL;
	Node tmpNode = start;
	for (int i = 0; i < inx && inx != 0; i++)if (tmpNode != NULL )tmpNode = (tmpNode)->next; else return NULL;
	return tmpNode;
}
void PutRev(Queue queue, int num) {
	Node p = (Node)malloc(sizeof(Node));
	p->data = num;
	p->next = NULL;
	queue->count++;
	if (queue->head == NULL) { queue->head = queue->tail = p; return; }
	p->next = queue->head;
	queue->head = p;
}
Queue cpy(Queue queue) {
	Queue qnew = InitializeQueue();
	int tmpcount = queue->count;
	Node tmpNode = queue->head;
	while (queue->count > 0)
	{
		Put(qnew, get_(queue));
	}
	queue->head = tmpNode;
	queue->count = tmpcount;
	return qnew;
}
void ReverseQueue(Queue *queue) {
	Queue qnew = InitializeQueue();
	while ((*queue)->count > 0)
	{
		PutRev(qnew, Get(*queue));
	}
	*queue = qnew;
}
#pragma region deleteeeeeee
void SwapNode(Node* start, int index1, int index2) {
	if (index2 < index1) { int tmp = index1; index1 = index2; index2 = tmp; }
	if (index1 == index2)return;
	Node tmpNode = NULL;//tmp node = inx1
	Node prevNode1 = NULL, prevNode2 = Index(*start, index2 - 1), Node1 = NULL, Node2 = prevNode2->next;
	if (index1 == 0)
	{
		Node1 = *start;
	}
	else {
		prevNode1 = Index(*start, index1 - 1);
		Node1 = prevNode1->next;
	}
	if (Node1 == NULL || Node2 == NULL)
		return;
	if (prevNode1 != NULL)prevNode1->next = Node2;
	else *start = Node2;
	prevNode2->next = Node1;


	// Swap next pointers
	tmpNode = Node2->next;
	Node2->next = Node1->next;
	Node1->next = tmpNode;
}
void Sort(Queue queue) {
	int i, j, n = queue->count - 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n - i; j++) {
			int a = Index(queue->head, j)->data;
			int b = Index(queue->head, j + 1)->data;
			int tmpcount = queue->count;
			Node tmpNode = queue->head;
			queue->head = tmpNode;
			queue->count = tmpcount;
			if (a > b)
				SwapNode(&(queue->head), j, j + 1);

		}
}
#pragma endregion
#endif // LINKED_QUEUE
