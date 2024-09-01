#include <stdio.h>

typedef struct {
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

typedef struct {
	Node* top;
}NodeStack;

typedef struct {
	Node* front;
	Node* end;
}NodeQueue;

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

void initLLStack(NodeStack* s) {
	s->top = NULL;
	return;
}

void pushLLStack(NodeStack* s, int value) {
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

void initLLQueue(NodeQueue* q) {
	q->front = NULL;
	q->end = NULL;
	return;
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