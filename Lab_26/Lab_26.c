#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

struct Node {
	int data;
	struct Node* next;
};


struct Node* first = NULL;

void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d) -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->next = first;
	newNode->data = value;

	first = newNode;
}

int deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
	return value;
}

int contains(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void clearList() {
	while (first != NULL)
	{
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

// «¿ƒ¿Õ»≈ 2
int sum() {
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		s += ptr->data;
		ptr = ptr->next;
	}
	return s;
}

// «¿ƒ¿Õ»≈ 3
int evenNumbers() {
	struct Node* ptr = first;
	int e = 0;
	while (ptr != NULL) {
		if (ptr->data % 2 == 0) {
			e++;
		}
		ptr = ptr->next;
	}
	return e;
}

// «¿ƒ¿Õ»≈ 4
void OddNumberX10() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data % 2 == 1) {
			ptr->data = ptr->data * 10;
		}
		ptr = ptr->next;
	}
}

// «¿ƒ¿Õ»≈ 5
void ElementIX100(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index == i) {
			ptr->data = ptr->data * 100;
			return;
		}
		ptr = ptr->next;
		index++;
	}
}

// «¿ƒ¿Õ»≈ 6
void LeftIX10(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index < i) {
			ptr->data = ptr->data * 10;
		}
		else {
			break;
		}
		ptr = ptr->next;
		index++;
	}
}

// «¿ƒ¿Õ»≈ 7
void RightIX10(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index > i) {
			ptr->data = ptr->data * 10;
		}
		ptr = ptr->next;
		index++;
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(9);
	printList();

	RightIX10(1);
	printList();

	LeftIX10(2);
	printList();

	printf("sum = %d\n", sum());
	printf("even numbers = %d\n", evenNumbers());

	OddNumberX10();
	printList();

	ElementIX100(2);
	printList();

	clearList();
	printList();
	printf("sum = %d\n", sum());
	printf("even numbers = %d\n", evenNumbers());

	{
		int x;
		scanf("%d", &x);
	}

}