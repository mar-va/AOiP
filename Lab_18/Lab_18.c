#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("----------------- ������ 1 -----------------\n");
	int a, b, c;
	int p;
	printf("������� ��� �����: ");
	scanf("%d%d%d", &a, &b, &c);
	printf("�����: %d, %d, %d\n", a, b, c);

	p = a * b * c;
	printf("%d * %d * %d =  %d\n", a, b, c, p);

	printf("----------------- ������ 2 -----------------\n");

	int a1, b1, c1;
	int p1; 

	FILE* fin = fopen("C:\\Users\\Vika\\Desktop\\������\\OAiP\\Lab_18\\in2.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������\n");
		return;
	}
	fscanf(fin, "%d%d%d", &a1, &b1, &c1);
	fclose(fin);

	printf("�����: %d, %d, %d\n", a1, b1, c1);

	p1 = a1 * b1 * c1;

	printf("%d * %d * %d =  %d\n", a1, b1, c1, p1);

	FILE* fout = fopen("C:\\Users\\Vika\\Desktop\\������\\OAiP\\Lab_18\\out2.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������\n");
		return;
	}
	fprintf(fout, "%d", p1);
	fclose(fout);

	printf("----------------- ������ 3 -----------------\n");
	int num1, num2, num3;
	int summa;
	printf("������� ��� �����: ");
	scanf("%d%d%d", &num1, &num2, &num3);
	printf("�����: %d, %d, %d\n", num1, num2, num3);

	summa = num1 + num2 + num3;
	printf("%d + %d + %d =  %d\n", num1, num2, num3, summa);

	printf("----------------- ������ 4 -----------------\n");

	int a4, b4, c4, d4, i4;
	int p4;

	FILE* fin4 = fopen("C:\\Users\\Vika\\Desktop\\������\\OAiP\\Lab_18\\in4.txt", "rt");
	if (fin4 == NULL) {
		printf("������� ���� �� ������\n");
		return;
	}
	fscanf(fin4, "%d%d%d%d%d", &a4, &b4, &c4, &d4, &i4);
	fclose(fin4);

	printf("�����: %d, %d, %d, %d, %d\n", a4, b4, c4, d4, i4);

	p4 = a4 + b4 + c4 + d4 + i4;

	printf("%d + %d + %d + %d + %d =  %d\n", a4, b4, c4, d4, i4, p4);

	FILE* fout4 = fopen("C:\\Users\\Vika\\Desktop\\������\\OAiP\\Lab_18\\out4.txt", "wt");
	if (fout4 == NULL) {
		printf("�������� ���� �� ��������\n");
		return;
	}
	fprintf(fout4, "%d", p4);
	fclose(fout4);

	printf("----------------- ������ 5 -----------------\n");

	int list[10];
	int n;
	int i;

	FILE* fin5 = fopen("C:\\Users\\Vika\\Desktop\\������\\OAiP\\Lab_18\\in5.txt", "rt");
	if (fin5 == NULL) {
		printf("������� ���� �� ������\n");
		return;
	}
	fscanf(fin5, "%d", &n);
	for (i = 0; i < n; i += 1) {
		fscanf(fin5, "%d", &list[i]);
	}
	fclose(fin5);

	printf("����� ������ list[%d] = ", n);
	for (i = 0; i < n; i += 1) {
		printf("%d ", list[i]);
	}

	summa = 0;

	for (i = 0; i < n; i += 1) {
		summa += list[i];
	}
	float sred_ar = (float)summa / n;

	printf("\n������� �������������� = %f\n", sred_ar);

	for (i = 0; i < n; i += 1) {
		if (list[i] > sred_ar) {
			list[i] *= 10;
		}
	}

	printf("����� ������ list[%d] = ", n);
	for (i = 0; i < n; i += 1) {
		printf("%d ", list[i]);
	}

	FILE* fout5 = fopen("C:\\Users\\Vika\\Desktop\\������\\OAiP\\Lab_18\\out5.txt", "wt");
	if (fout5 == NULL) {
		printf("�������� ���� �� ��������\n");
		return;
	}
	fprintf(fout5, "%d\n", n);

	for (i = 0; i < n; i += 1) {
		fprintf(fout5, "%d ", list[i]);
	}
	printf("\n");
	fclose(fout5);
	
	printf("----------------- ������ 6 -----------------\n");

	int list6[10];
	int n6;

	FILE* fin6 = fopen("C:\\Users\\Vika\\Desktop\\������\\OAiP\\Lab_18\\in6.txt", "rt");
	if (fin6 == NULL) {
		printf("������� ���� �� ������\n");
		return;
	}
	fscanf(fin6, "%d", &n6);
	for (i = 0; i < n6; i += 1) {
		fscanf(fin6, "%d", &list6[i]);
	}
	fclose(fin6);

	printf("����� ������ list[%d] = ", n6);
	for (i = 0; i < n6; i += 1) {
		printf("%d ", list6[i]);
	}

	summa = 0;

	for (i = 0; i < n6; i += 1) {
		summa += list6[i];
	}
	float sred_ar6 = (float)summa / n6;

	printf("\n������� �������������� = %f\n", sred_ar6);

	for (i = 0; i < n6; i += 1) {
		if (list6[i] < sred_ar6 && list6[i] > 1) {
			list6[i] /= 2;
		}
	}

	printf("����� ������ list[%d] = ", n6);
	for (i = 0; i < n6; i += 1) {
		printf("%d ", list6[i]);
	}

	FILE* fout6 = fopen("C:\\Users\\Vika\\Desktop\\������\\OAiP\\Lab_18\\out6.txt", "wt");
	if (fout6 == NULL) {
		printf("�������� ���� �� ��������\n");
		return;
	}
	fprintf(fout6, "%d\n", n6);

	for (i = 0; i < n6; i += 1) {
		fprintf(fout6, "%d ", list6[i]);
	}
	printf("\n");
	fclose(fout6);
}