#include <Windows.h>
#include <stdio.h>

long rec(int n) {
	if (n == 0) {
		return 1;
	}
	long res = n * rec(n - 1);
	return res;
}

void rec1(int n) {
	printf(" %d", n);
	if (n > 1) {
		rec1(n - 2);
	}
}

void rec2(int n) {
	if (n > 1) {
		rec2(n - 2);
	}
	printf(" %d", n);
}

void rec3(int n) {
	printf(" %d", n);
	if (n > 1) {
		rec3(n - 2);
	}
	printf(" %d", n);
}

void recEGE1(int n) {
	if (n >= 1) {
		printf(" %d", n);
		recEGE1(n - 1);
		recEGE1(n - 1);
	}
}

void F1(int n) {
	if (n > 2) {
		printf("%d\n", n);
		F1(n - 3);
		F1(n - 4);
	}
}

void F2(int n) {
	if (n < 5) {
		printf("%d\n", n);
		F2(n + 1);
		F2(n + 3);
	}
}

void G3(int n);

int count = 0;

void F3(int n) {
	if (n > 0) {
		G3(n - 1);
	}
}

void G3(int n) {
	count++;
	printf("*");
	if (n > 1) {
		F3(n - 3);
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Задание 1
	int n = 4;
	long f = rec(n);
	printf("%d! = %d\n", n, f);

	// Задание 2
	rec1(11);
	printf(" rec1 finish!\n");

	rec2(11);
	printf(" rec2 finish!\n");

	rec3(11);
	printf(" rec3 finish!\n");

	// Задача 4
	recEGE1(4);

	// Задача 5
	F1(10);

	// Задача 6
	F2(1);

	// Задача 7
	F3(11);
	printf("\nКоличество * = %d", count);
}