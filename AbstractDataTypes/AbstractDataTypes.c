#include <stdio.h>



typedef struct {
	int element[100];
}LinkedList;

typedef struct {
	int element[100];
}LinkedPoint;

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

int main() {
	Stack s;
	Queue q;

	int firstValue = 1;
	int secondValue = 2;
	int thirdValue = 3;
	initArrayStack(&s);
	pushArrayStack(&s, firstValue);
	pushArrayStack(&s, secondValue);
	pushArrayStack(&s, thirdValue);

	printf("Stack is one of abstract data types, \nwhich is well known as FILO(First Input Last Output)\n");
	printf("\nThis is the peek of the Stack Array: ");
	printf("%d\n", peekArrayStack(&s));

	printf("\nStack Arrays:\n");
	printf("%d\n", popArrayStack(&s));
	printf("%d\n", popArrayStack(&s));
	printf("%d\n", popArrayStack(&s));



	initArrayQueue(&q);
	enqueueArray(&q, firstValue);
	enqueueArray(&q, secondValue);
	enqueueArray(&q, thirdValue);

	printf("\nQueue is one of abstract data types, \nwhich is well known as FIFO(First Input First Output)\n");
	printf("\nThis is the peek of the Queue Array: ");
	printf("%d\n", peekQueueArray(&q));

	printf("\nQueue Arrays:\n");
	printf("%d\n", dequeueArray(&q));
	printf("%d\n", dequeueArray(&q));
	printf("%d\n", dequeueArray(&q));



	return 0;
}

