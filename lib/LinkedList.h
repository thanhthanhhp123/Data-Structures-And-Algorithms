#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node* next;
} *Node;
//DONE: Insert function 


int Append(Node *start, int index,int data) {
	Node tempNode = (Node)malloc(sizeof(Node));
	tempNode->data = data;
	if (index == 0) { tempNode->next = (*start); (*start) = tempNode; return; }
	Node tmp = *start;
	for (int i = 1; index > -1 ? i < index : tmp->next != NULL; i++)tmp = tmp->next;
	tempNode->next = tmp->next == NULL ? NULL : tmp->next;
	tmp->next = tempNode;
}

//DONE: Find function

Node Find(Node start, int data) {
	for (Node n = start; n != NULL ; n = n->next)if (n->data == data)return n;
	return NULL;
}

//DONE: Index function -> pointer
Node Index(Node start, int index) {
	for (int i = 0; i <= index && start->next != NULL; i++) { if (start->next != NULL)start = start->next; 
	if (i == index)return start;}
	return NULL;
	
}

//DONE: Delete function (pop, delete = find)

int Pop(Node start, int index) {
	for (int i = 0; i <= index && start->next != NULL; i++) {
		if (i == index-1) {

			start->next = start->next->next;
			//free(start);
			return 1;
		}
		if (start->next != NULL)start = start->next;
		
	}
	return 0;
}

int Remove(Node start, Node item){
	for (Node temp = start; temp->next != NULL; temp = temp->next)
	{
		if (temp->next == item) {
			temp->next = item->next;
			item->next = NULL;
			//free(item);
			return 1;
		}
	}
	return 0;
}
/// <summary>
/// Print linked list
/// </summary>
void Print(Node start) {
	printf("\nLinked list node: ");
	for (Node node = start; node != NULL; node = node->next)printf("%d ", node->data);
}


/// <summary>
/// Create a new linked list with int type
/// </summary>
/// <param name="length:">length of the list</param>
/// <param name="randRange:"> max random input, 0 to manually type</param>
/// <returns>Return the first node</returns>
Node LinkedList(int length, int randRange) {
	
	int inx = 0;
	Node nodeZero = (Node)malloc(sizeof(Node));
	nodeZero->next = NULL;

	if (randRange == 0) { printf("[%d]:", inx++); scanf("%d", &nodeZero->data); }
	else nodeZero->data = rand() % randRange;
	if (length > 1) {
		Node nodeOne = (Node)malloc(sizeof(Node));
		nodeZero->next = nodeOne;
		nodeOne->next = NULL;
		if (randRange == 0) { printf("[%d]:", inx++); scanf("%d", &nodeOne->data); }
		else nodeOne->data = rand() % randRange;

		for (int i = 0; i < length-2; i++)
		{
			Node nodeN = (Node)malloc(sizeof(Node));
			if (randRange == 0) { printf("[%d]:", inx++); scanf("%d", &nodeN->data); }
			else nodeN->data = rand() % randRange;
			nodeOne->next = nodeN;
			nodeN->next = NULL;
			nodeOne = nodeN;
		}
	}
	return nodeZero;
}
