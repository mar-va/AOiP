#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>


void task_1() {
	char name[12];
	printf("Введите ваше имя: ");
	fgets(name, 11, stdin);
	printf("Приветствую вас, %s\n", name);
}

void task_2() {
	printf("Введите символ: ");
	int ch = getchar();

	for (int i = ch; i <= ch + 19; i++) {
		printf("%c (%d)\n", i, i);
	}
	printf("\n");
}

void task_3() {
	printf("Введите символ: ");
	int ch_1 = getchar();

	for (int j = ch_1; j >= ch_1 - 29; j--) {
		printf("%c (%d)\n", j, j);
	}
}

void task_4() {
	char s[100];
	printf("Введите строку: ");
	fgets(s, 99, stdin);

	printf("\nВы ввели строку s = \"%s\"\n", s);

	int count = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') {
			count++;
		}
	}
	printf("В строке s %d пробела", count);
}

void task_5() {
	char s[100];
	printf("Введите строку: ");
	fgets(s, 99, stdin);

	printf("\nВы ввели строку s = \"%s\"\n", s);

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') {
			s[i] = '#';
		}
	}
	printf("Строка после обработки = \"%s\"\n", s);
}

void task_6_1() {
	char s[100];
	printf("Введите строку: ");
	fgets(s, 99, stdin);

	printf("\nВы ввели строку s = \"%s\"\n", s);

	for (int i = 0; i < strlen(s); i++) {
		if (isdigit(s[i])) {
			s[i] = '$';
		}
	}
	printf("Строка после обработки = \"%s\"\n", s);
}

int IsDigitMy(char c) {
	if (c >= 0 && c <= 9) {
		return 1;
	}
	return 0;
}

void task_6_2() {
	char s[100];
	printf("Введите строку: ");
	fgets(s, 99, stdin);

	printf("\nВы ввели строку s = \"%s\"\n", s);

	for (int i = 0; i < strlen(s); i++) {
		if (IsDigitMy(s[i])) {
			s[i] = '$';
		}
	}
	printf("Строка после обработки = \"%s\"\n", s);
}

void task_7_1() {
	char s[100];
	printf("Введите строку: ");
	fgets(s, 99, stdin);

	printf("\nВы ввели строку s = \"%s\"\n", s);

	for (int i = 0; i < strlen(s); i++) {
		s[i] = toupper(s[i]);
	}
	printf("Строка после обработки = \"%s\"\n", s);
}

int toUpperAll(char c) {
	int new_ch;
	if (c >= 'a' && c <= 'z') {
		new_ch = 'A' + (c - 'a');
	}
	if (c >= 'а' && c <= 'п') {
		new_ch = 'А' + (c - 'а');
	}
	if (c >= 'р' && c <= 'я') {
		new_ch = 'Р' + (c - 'р');
	}
	if (c == 'ё') {
		new_ch = 'Ё';
	}
	return new_ch;
}

void task_7_2() {
	char s[100];
	printf("Введите строку: ");
	fgets(s, 99, stdin);

	printf("\nВы ввели строку s = \"%s\"\n", s);

	for (int i = 0; i < strlen(s); i++) {
		s[i] = toUpperAll(s[i]);
	}
	printf("Строка после обработки = \"%s\"\n", s);
}

int StrLenMy(char* str) {
	int len = 0;

	while (str[len] != '\0') {
		len++;
	}
	return len;
}

void StrCpyMy(char* str1, char* str2) {
	for (int i = 0; str1[i] != '\0'; i++) {
		str1[i] = str2[i];
	}
}

void StrCatMy(char* str1, char* str2) {
	int i = 0;
	do {
		i++;
	} while (str1[i] != '\0');

	for (int k = 0; str2[k] != '\0'; k++) {
		str1[i] = str2[k];
		i++;
	}
}

void DZ_2(char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (isdigit(str[i])) {
			str[i] = 'X';
		}
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*task_1();
	task_2();
	task_3();
	task_4();
	task_5();
	task_6_1();
	task_6_2();
	task_7_1();
	task_7_2();*/

	// Задание 9
	char s[10] = "Hello";
	printf("%d\n", StrLenMy(s));

	// Задание 11
	char str_1[] = "Hello world!";
	char str_2[15];
	printf("%s\n", str_1);
	printf("%s\n", str_2);
	StrCpyMy(str_2, str_1);
	printf("%s\n", str_2);

	// Задание 12
	char s1[20] = "<>";
	char s2[20] = "Cat";
	printf("s1 = %s, s2 = %s\n", s1, s2);
	StrCatMy(s1, s2);
	printf("s1 = %s, s2 = %s\n", s1, s2);

	// Домашнее задание (часть 2)
	char string[] = "10GHjfb56fjbg";
	printf("%s\n", string);
	DZ_2(string);
	printf("%s\n", string);
}