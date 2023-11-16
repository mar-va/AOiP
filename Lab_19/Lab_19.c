#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

int evaluations[1000];
int *pa;
int count;

int *temp;
int count_temp;

int *incomes;
int count_incomes;

void load() {
	FILE* fin = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_19\\in1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	fscanf(fin, "%d", &count);
	for (int i = 0; i < count; i += 1) {
		fscanf(fin, "%d", &evaluations[i]);
	}

	fclose(fin);
}

void SaveResult() {
	float arithmetic_mean;
	float amount = 0;

	for (int i = 0; i < count; i += 1) {
		amount += evaluations[i];
	}
	arithmetic_mean = amount / count;

	int count_suitable_elements = 0;

	for (int i = 0; i < count; i += 1) {
		if (evaluations[i] > arithmetic_mean) {
			count_suitable_elements += 1;
		}
	}

	FILE* fout = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_19\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", count_suitable_elements);
	for (int i = 0; i < count; i += 1) {
		if (evaluations[i] > arithmetic_mean) {
			fprintf(fout, "%d ", evaluations[i]);
		}
	}

	fclose(fout);
}

void load2() {
	FILE* fin = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_19\\in1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}
	fscanf(fin, "%d", &count);

	pa = (int*)malloc(sizeof(int) * count);

	for (int i = 0; i < count; i += 1) {
		fscanf(fin, "%d", &pa[i]);
	}
	fclose(fin);
}

void SaveResult2() {
	float arithmetic_mean;
	float amount = 0;

	for (int i = 0; i < count; i += 1) {
		amount += pa[i];
	}
	arithmetic_mean = amount / count;

	int count_suitable_elements = 0;

	for (int i = 0; i < count; i += 1) {
		if (pa[i] > arithmetic_mean) {
			count_suitable_elements += 1;
		}
	}

	FILE* fout = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_19\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", count_suitable_elements);
	for (int i = 0; i < count; i += 1) {
		if (pa[i] > arithmetic_mean) {
			fprintf(fout, "%d ", pa[i]);
		}
	}

	fclose(fout);
}

void load3() {
	FILE* fin = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_19\\in3.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}
	fscanf(fin, "%d", &count_temp);

	temp = (int*)malloc(sizeof(int) * count_temp);

	for (int i = 0; i < count_temp; i += 1) {
		fscanf(fin, "%d", &temp[i]);
	}
	fclose(fin);
}

void SaveResult3() {
	float arithmetic_mean;
	float amount = 0;

	for (int i = 0; i < count_temp; i += 1) {
		amount += temp[i];
	}
	arithmetic_mean = amount / count_temp;

	int count_suitable_elements = 0;

	for (int i = 0; i < count_temp; i += 1) {
		if (temp[i] < arithmetic_mean && temp[i] > 0) {
			count_suitable_elements += 1;
		}
	}

	FILE* fout = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_19\\out3.txt", "wt");
	if (fout == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", count_suitable_elements);
	for (int i = 0; i < count_temp; i += 1) {
		if (temp[i] < arithmetic_mean && temp[i] > 0) {
			fprintf(fout, "%d ", temp[i]);
		}
	}
	fclose(fout);
}

void load4() {
	FILE* fin = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_19\\in4.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}
	fscanf(fin, "%d", &count_incomes);

	incomes = (int*)malloc(sizeof(int) * count_incomes);

	for (int i = 0; i < count_incomes; i += 1) {
		fscanf(fin, "%d", &incomes[i]);
	}
	fclose(fin);
}

void SaveResult4() {
	int max_income = 0;
	float high_income;

	for (int i = 0; i < count_incomes; i += 1) {
		if (max_income < incomes[i]) {
			max_income = incomes[i];
		}
	}

	high_income = max_income * 2 / 3;

	int count_suitable_elements = 0;

	for (int i = 0; i < count_incomes; i += 1) {
		if (incomes[i] >= high_income) {
			count_suitable_elements += 1;
		}
	}

	FILE* fout = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_19\\out4.txt", "wt");
	if (fout == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", count_suitable_elements);
	for (int i = 0; i < count_incomes; i += 1) {
		if (incomes[i] >= high_income) {
			fprintf(fout, "%d ", incomes[i]);
		}
	}
	fclose(fout);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("--------------------- ЗАДАЧА 1 ---------------------\n");
	load();
	SaveResult();

	printf("--------------------- ЗАДАЧА 2 ---------------------\n");
	load2();
	SaveResult2();
	free(pa);

	printf("--------------------- ЗАДАЧА 3 ---------------------\n");
	load3();
	SaveResult3();
	free(temp);

	printf("--------------------- ЗАДАЧА 4 ---------------------\n");
	load4();
	SaveResult4();
	free(incomes);
}