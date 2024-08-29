#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int data;
	struct Node* next;

}Node;

typedef struct {
	Node* top;
}NodeStack;

typedef struct {
	Node* front;
	Node* end;
}NodeQueue;

void initLLQueue(NodeQueue* q) {
	q->front = NULL;
	q->end = NULL;
	return;
}

void enqueueLL(NodeQueue* q, int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	if (q->end == NULL) {
		q->front = newNode;
		q->end = newNode;
		return;
	}
	q->end->next = newNode;
	q->end = newNode;
	return;
}

int dequeueLL(NodeQueue* q) {
	Node* temp = q->front;
	q->front = temp->next;
	int result = temp->data;
	free(temp);

	return result;
}

void initLLStack(NodeStack*s){
	s->top = NULL;
	return;
}

void pushLLStack(NodeStack*s, int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	if (s->top == NULL) {
		newNode->next = NULL;
		s->top = newNode;
		return;
	}
	newNode->next = s->top;
	s->top = newNode;

	return;
}

int popLLStack(NodeStack* s) {
	Node* temp = s->top;
	s->top = temp->next;

	int result = temp->data;
	free(temp);

	return result;
}

typedef struct {
	int elements[100];
	int frontIndex;
	int endIndex;
}Queue;

void initArrayQueue(Queue* q) {

	q->frontIndex = 0;
	q->endIndex = -1;
	return;
}

void enqueueArray(Queue* q, int value) {
	q->endIndex = q->endIndex + 1;
	q->elements[q->endIndex] = value;
	return;
}

int dequeueArray(Queue* q) {
	int result = q->elements[q->frontIndex];
	q->frontIndex = q->frontIndex + 1;

	return result;
}

typedef struct {
	int top;
	int elements[100];
}Stack;


void initArrayStack(Stack* s) {
	s->top = -1;

	return;
}

void pushArrayStack(Stack* s, int value) {

	s->top = s->top + 1;
	s->elements[s->top] = value;

	return;
}

int popArrayStack(Stack* s) {

	int result = s->elements[s->top];
	s->top = s->top - 1;

	return result;
}

int peekArrayStack(Stack* s) {
	int result = s->elements[s->top];

	return result;
}

int peekQueueArray(Queue* q) {
	int result = q->elements[q->frontIndex];
	return result;
}

void emptyStackArray(Stack* s) {
	while (s->top > -1) {
		s->elements[s->top] = 0;
		s->top = s->top - 1;
	}
	return;
}

void emptyQueueArray(Queue* q) {
	while (q->frontIndex > q->endIndex)
	{
		q->elements[q->frontIndex] = 0;
		q->frontIndex = q->frontIndex - 1;
	}
	return;
}

typedef struct {
	int data;
	struct node_t* next;
}node_t;

typedef struct {
	node_t* head;
	node_t* tail;
}LL_t;

void LL_init(LL_t* list) {
	list->head = NULL;
	list->tail = NULL;
	return;
}

void LL_add_to_head(LL_t* list, int value) {
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = value;
	if (list->head == NULL) {
		newNode->next = NULL;
		list->head = newNode;
		return;
	}
	newNode->next = list->head;
	list->head = newNode;

	return;
}

void LL_add_to_tail(LL_t* list, int value) {
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = value;
	if (list->tail == NULL) {
		newNode->next = NULL;
		list->tail = newNode;
		return;
	}
	list->tail->next = newNode;
	list->tail = newNode;

	return;
}

void LL_remove_from_head(LL_t* list) {
	if (list->head == NULL) {
		return;
	}
	node_t* temp = list->head;
	list->head = temp->next;
	return;
}

int LL_size(const LL_t* list) {
	int counter = 0;
	node_t* temp = list->head;
	while (temp != NULL) {
		temp = temp->next;
		counter++;
	}

	return counter;
}

void LL_print(const LL_t* list) {
	node_t* temp = list->head;
	if (temp == NULL) {
		return;
	}

	printf("%d", temp->data);
	temp = temp->next;

	while (temp != NULL) {
		printf("->%d", temp->data);
		temp = temp->next;
	}
	return;
}

int main() {
	//Stack s;
	//Queue q;
	NodeStack s;
	NodeQueue q;
	LL_t list;
	LL_init(&list);

	LL_add_to_head(&list, 3);
	LL_add_to_head(&list, 7);
	LL_print(&list);
	//printf("%d",LL_size(&list));

	/*int firstValue = 1;
	int secondValue = 2;
	int thirdValue = 3;
	printf("Stack\n");
	initLLStack(&s);
	pushLLStack(&s, firstValue);
	pushLLStack(&s, secondValue);
	pushLLStack(&s, thirdValue);

	printf("%d\n",popLLStack(&s));
	printf("%d\n",popLLStack(&s));
	printf("%d\n",popLLStack(&s));

	printf("Queue\n");
	initLLQueue(&q);
	enqueueLL(&q, firstValue);
	enqueueLL(&q, secondValue);
	enqueueLL(&q, thirdValue);

	printf("%d\n", dequeueLL(&q));
	printf("%d\n", dequeueLL(&q));
	printf("%d\n", dequeueLL(&q));
*/




	//initArrayStack(&s);
	//pushArrayStack(&s, firstValue);
	//pushArrayStack(&s, secondValue);
	//pushArrayStack(&s, thirdValue);

	//printf("Stack is one of abstract data types, \nwhich is well known as FILO(First Input Last Output)\n");
	//printf("\nThis is the peek of the Stack Array: ");
	//printf("%d\n", peekArrayStack(&s));

	//printf("\nStack Arrays:\n");
	//printf("%d\n", popArrayStack(&s));
	//printf("%d\n", popArrayStack(&s));
	//printf("%d\n", popArrayStack(&s));

	//emptyStackArray(&s);

	//initArrayQueue(&q);
	//enqueueArray(&q, firstValue);
	//enqueueArray(&q, secondValue);
	//enqueueArray(&q, thirdValue);

	//printf("\nQueue is one of abstract data types, \nwhich is well known as FIFO(First Input First Output)\n");
	//printf("\nThis is the peek of the Queue Array: ");
	//printf("%d\n", peekQueueArray(&q));

	//printf("\nQueue Arrays:\n");
	//printf("%d\n", dequeueArray(&q));
	//printf("%d\n", dequeueArray(&q));
	//printf("%d\n", dequeueArray(&q));



	return 0;
}

