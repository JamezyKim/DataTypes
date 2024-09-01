#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool sameListAreEqualReturnTrue();
bool differentListAreEqualReturnTrue();
bool differentSizeAreEqualReturnTrue();
bool multipleListsLL_remove_from_tailReturnTrue();
bool multipleListsLL_print_reverseReturnzero();
bool singleListsLL_remove_from_tailReturnTrue();
bool zeroListsLL_remove_from_tailReturnTrue();
bool singleListsLL_print_reverseReturnzero();
bool multipleListsTo_arrayReturnEqualValue();
bool multipleListsArray_to_listEqualValue();

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
		list->tail = newNode;
		return;
	}
	newNode->next = list->head;
	list->head = newNode;

	return;
}

void LL_add_to_tail(LL_t* list, int value) {
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = value;
	newNode->next = NULL;

	if (list->tail == NULL) {
		newNode->next = NULL;
		list->tail = newNode;
		list->head = newNode;
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
		printf("The list is empty\n");
		return;
	}

	printf("%d", temp->data);
	temp = temp->next;

	while (temp != NULL) {
		printf("->%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}

void LLnode_free(node_t* node) {
	if (node != NULL) {
		free(node);
		return;
	}
}

void LL_free(LL_t* list) {
	if (list != NULL) {
		free(list);
		return;
	}
}

int LL_remove_from_tail(LL_t* list) {

	node_t* tempFromTail = list->tail;
	node_t* tempFromHead = list->head;
	if (tempFromTail == NULL) {
		return 0;
	}
	int returnTailValue = list->tail->data;


	if (tempFromHead == tempFromTail) {

		list->head = NULL;
		list->tail = NULL;
		free(tempFromTail);
		return returnTailValue;
	}

	while (tempFromHead->next != tempFromTail) {
		tempFromHead = tempFromHead->next;
	}

	tempFromHead->next = NULL;
	
	list->tail = tempFromHead;


	free(tempFromTail);


	return returnTailValue;
}

bool are_equal(LL_t* firstList,LL_t*secondList) {

	node_t* firstTempHead = firstList->head;
	node_t* secondTempHead = secondList->head;

	bool isEqual = false;
	int firstNodeCounter = LL_size(firstList);
	int secondNodeCounter = LL_size(secondList);

	if (firstNodeCounter != secondNodeCounter) {
		return isEqual;
	}

	while (0<firstNodeCounter) {
		if (firstTempHead->data != secondTempHead->data) {
			return isEqual;
		}
		firstTempHead = firstTempHead->next;
		secondTempHead = secondTempHead->next;
		firstNodeCounter--;
	}
	isEqual = true;



	return isEqual;
}

int* LL_print_reverse(LL_t* list) {

	node_t* tempFromTail = list->tail;
	node_t* tempFromHead = list->head;
	int* arr = (int*)malloc(sizeof(int));
	int* reversedArr = (int*)malloc(sizeof(int));
	int counter = 0;

	if (tempFromTail == NULL) {
		return NULL;
	}

	while (tempFromHead != NULL) {
		arr[counter] = tempFromHead->data;
		tempFromHead = tempFromHead->next;
		counter++;
	}

	for (int i = counter -1; i >= 0; i--) {
		printf("%d", arr[i]);
		reversedArr[counter - i - 1] = arr[i];
	}

	return reversedArr;
}

LL_t* array_to_list(int* arr,int size) {
	LL_t* list = (LL_t*)malloc(sizeof(LL_t));
	LL_init(list);
	int counter = 0;
	while (counter < size) {
		LL_add_to_tail(list, arr[counter]);
		counter++;
	}

	return list;
}

int* to_array(LL_t* list) {
	int* arr = (int*)malloc(sizeof(int));
	int counter = 0;
	node_t* temp = list->head;


	if (temp == list->tail && temp != NULL) {
		arr[0] = list->head->data;
		return arr;
	}
	while (temp != NULL) {
		arr[counter] = temp->data;
		temp = temp->next;
		counter++;
	}
	temp = NULL;
	free(temp);

	return arr;
}

bool multipleNodesLL_sizeReturnTrue() {
	//arrange
	LL_t firstList;
	bool isEqual = false;
	LL_init(&firstList);

	LL_add_to_head(&firstList, 4);
	LL_add_to_head(&firstList, 5);
	LL_add_to_head(&firstList, 6);

	int expectedResult = 3;
	//act

	int actualResult = LL_size(&firstList);

	//assert
	if (expectedResult == actualResult) {
		isEqual = true;
	}
	else {
		isEqual = false;
	}
	return isEqual;
}


int main() {
	//Stack s;
	//Queue q;
	//NodeStack s;
	//NodeQueue q;
	LL_t firstList;
	LL_t secondList;
	node_t  node;
	node_t* newNode = (node_t*)malloc(sizeof(node_t));

	int arr[3] = { 1,2,3 };
	//are_equal
	printf("multipleNodesLL_sizeReturnTrue: %d\n", multipleNodesLL_sizeReturnTrue());
	printf("sameListAreEqualReturnTrue: %d\n",sameListAreEqualReturnTrue());
	printf("differentListAreEqualReturnTrue: %d\n", differentListAreEqualReturnTrue());
	printf("differentSizeAreEqualReturnTrue: %d\n", differentSizeAreEqualReturnTrue());

	//remove_from_tail
	printf("multipleListsLL_remove_from_tailReturnTrue: %d\n", multipleListsLL_remove_from_tailReturnTrue());
	printf("singleListsLL_remove_from_tailReturnTrue: %d\n", singleListsLL_remove_from_tailReturnTrue());
	printf("zeroListsLL_remove_from_tailReturnTrue: %d\n", zeroListsLL_remove_from_tailReturnTrue());


	//LL_print_reverse
	printf("multipleListsLL_print_reverseReturnzero: %d\n", multipleListsLL_print_reverseReturnzero());
	printf("singleListsLL_print_reverseReturnzero: %d\n", singleListsLL_print_reverseReturnzero());

	//to_array
	printf("multipleListsTo_arrayReturnEqualValue: %d\n", multipleListsTo_arrayReturnEqualValue());

	//arry_to_list
	printf("multipleListsArray_to_listEqualValue: %d\n", multipleListsArray_to_listEqualValue());

	return 0;
}

bool multipleListsArray_to_listEqualValue() {
	//arrange
	LL_t expectedList;
	LL_init(&expectedList);
	int* arr = (int*)malloc(sizeof(int));
	arr[0] = 1;
	arr[1] = 7;
	arr[2] = 9;
	LL_add_to_tail(&expectedList, 1);
	LL_add_to_tail(&expectedList, 7);
	LL_add_to_tail(&expectedList, 9);

	//act
	LL_t* actualResult = array_to_list(arr,3);

	//assert
	return are_equal(actualResult, &expectedList);

}

bool multipleListsTo_arrayReturnEqualValue() {
	//arrange
	LL_t list;
	LL_init(&list);
	LL_add_to_head(&list, 3);
	LL_add_to_head(&list, 7);
	LL_add_to_head(&list, 1);
	int expectedResult[3] = { 1,7,3 };


	//act
	int* actualResult = to_array(&list);

	//assert
	for (int i = 0; i < 3; i++) {
		if (expectedResult[i] != actualResult[i]) {
			return false;
		}
	}
	return true;
}

bool singleListsLL_print_reverseReturnzero() {
	// arrange
	LL_t list;
	bool isEqual = false;
	LL_init(&list);

	LL_add_to_head(&list, 3);

	int expectedResult = 3;

	//act
	int* result = LL_print_reverse(&list);
	int actualResult = *result;

	//assert
	if (expectedResult == actualResult) {
		isEqual = true;
	}
	else {
		isEqual = false;
	}
	//free(result);
	return isEqual;
}

bool multipleListsLL_print_reverseReturnzero() {
	// arrange
	LL_t list;
	bool isEqual = true;
	LL_init(&list);

	LL_add_to_head(&list, 3);
	LL_add_to_head(&list, 6);
	LL_add_to_head(&list, 1);

	int expectedResult[] = {3,6,1};

	//act

	int* actualResult = LL_print_reverse(&list);

	//assert
	for (int i = 0; i < 3; i++) {
		if (expectedResult[i] != actualResult[i]) {
			isEqual = false;
			break;
		}
	}
	//free(actualResult);
	return isEqual;
}

bool multipleListsLL_remove_from_tailReturnTrue() {
	// arrange
	LL_t list;
	bool isEqual = false;
	LL_init(&list);

	LL_add_to_head(&list, 3);
	LL_add_to_head(&list, 6);
	LL_add_to_head(&list, 1);

	int expectedResult = 3;

	//act
	int actualResult = LL_remove_from_tail(&list);

	//assert

	printf("%d\n", expectedResult);
	printf("%d\n", actualResult);


	if (expectedResult == actualResult) {
		return true;
	}
	else {
		return false;
	}
}

bool singleListsLL_remove_from_tailReturnTrue() {
	// arrange
	LL_t list;
	bool isEqual = false;
	LL_init(&list);

	LL_add_to_head(&list, 3);

	int expectedResult = 3;

	//act
	int actualResult = LL_remove_from_tail(&list);

	//assert

	printf("%d\n", expectedResult);
	printf("%d\n", actualResult);


	if (expectedResult == actualResult) {
		return true;
	}
	else {
		return false;
	}
}

bool zeroListsLL_remove_from_tailReturnTrue() {
	// arrange
	LL_t list;
	bool isEqual = false;
	LL_init(&list);

	int expectedResult = 0;

	//act
	int actualResult = LL_remove_from_tail(&list);

	//assert

	printf("%d\n", expectedResult);
	printf("%d\n", actualResult);


	if (expectedResult == actualResult) {
		return true;
	}
	else {
		return false;
	}
}

bool sameListAreEqualReturnTrue() {
	//arrange
	LL_t firstList;
	LL_t secondList;

	LL_init(&firstList);
	LL_init(&secondList);

	LL_add_to_head(&firstList, 4);
	LL_add_to_head(&firstList, 5);
	LL_add_to_head(&firstList, 6);

	LL_add_to_head(&secondList, 4);
	LL_add_to_head(&secondList, 5);
	LL_add_to_head(&secondList, 6);

	bool expectedResult = true;

	//act

	bool actualResult = are_equal(&firstList, &secondList);

	//assert
	if (expectedResult == actualResult) {
		return true;
	}
	else {
		return false;
	}

}

bool differentListAreEqualReturnTrue() {
	//arrange
	bool isEqual = false;
	LL_t firstList;
	LL_t secondList;

	LL_init(&firstList);
	LL_init(&secondList);

	LL_add_to_head(&firstList, 2);
	LL_add_to_head(&firstList, 4);
	LL_add_to_head(&firstList, 5);

	LL_add_to_head(&secondList, 5);
	LL_add_to_head(&secondList, 5);
	LL_add_to_head(&secondList, 5);

	bool expectedResult = false;

	//act
	bool actualResult = are_equal(&firstList, &secondList);

	//assert
	if (expectedResult == actualResult) {
		isEqual = true;
		return isEqual;
	}
	else {
		isEqual = false;
		return isEqual;
	}

}



bool differentSizeAreEqualReturnTrue() {
	//arrange
	bool isEqual = false;
	LL_t firstList;
	LL_t secondList;

	LL_init(&firstList);
	LL_init(&secondList);

	LL_add_to_head(&firstList, 2);
	LL_add_to_head(&firstList, 4);
	LL_add_to_head(&firstList, 5);

	LL_add_to_head(&secondList, 2);
	LL_add_to_head(&secondList, 4);
	LL_add_to_head(&secondList, 5);
	LL_add_to_head(&secondList, 5);

	bool expectedResult = false;

	//act
	bool actualResult = are_equal(&firstList, &secondList);

	//assert
	if (expectedResult == actualResult) {
		isEqual = true;
		return isEqual;
	}
	else {
		isEqual = false;
		return isEqual;
	}

}