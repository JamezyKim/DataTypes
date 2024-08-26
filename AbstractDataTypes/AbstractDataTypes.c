#include <stdio.h>


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


int main() {
	Stack s;

	int firstValue = 1;
	int secondValue = 2;
	int thirdValue = 3;
	initArrayStack(&s);
	pushArrayStack(&s, firstValue);
	pushArrayStack(&s, secondValue);
	pushArrayStack(&s, thirdValue);

	printf("%d\n", popArrayStack(&s));
	printf("%d\n", popArrayStack(&s));
	printf("%d\n", popArrayStack(&s));


	return 0;
}

