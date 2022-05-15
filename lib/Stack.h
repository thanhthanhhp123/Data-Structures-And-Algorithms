#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#ifndef STACK_MAX
#define STACK_MAX 100
#endif // !STACK_MAX

#include<stdio.h>
#include <stdlib.h>

#ifdef ARRAY_STACK
typedef struct {
	int head, count;
	int stack[STACK_MAX];
} *Stack;


Stack InitializeStack() {
	Stack newstack = (Stack)malloc(sizeof(Stack));
	newstack->count = 0;
	newstack->head = 0;
	return newstack;

}
void Put(Stack stack, int data) {
	if (stack->count >= STACK_MAX)return;
	if (stack->head == STACK_MAX)stack->head = 0;
	stack->stack[stack->head++] = data;
	stack->count++;
}
int Get(Stack stack) {
	if (stack->count == 0)return NULL;
	stack->count--;
	return stack->stack[stack->head--];
}

#endif // ARRAY_STACK
#ifdef LINKED_STACK
typedef struct node {
	int data;
	struct node* next;
} *Node;
typedef struct {
	Node head; int count;
} *Stack;
Stack InitializeStack() {
	Stack newstack = (Stack)malloc(sizeof(Stack));
	newstack->head =  NULL;
	newstack->count = 0;
	return newstack;
}
void Put(Stack stack, int data) {
	Node p;
	p = (Node)malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	stack->count++;
	if (stack->head == NULL) { stack->head = p; return; }
	p->next = stack->head;
	stack->head = p;
}
int Get(Stack stack) {
	if (stack->head == NULL)return NULL;
	stack->count--;
	int tmp = (int)stack->head->data;
	Node tmpNode = stack->head;
	stack->head = stack->head->next;
	//free(tmpNode);
	return tmp;
}
#endif // LINKED_STACK
