#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int n = 3;
int m = 4;
int arr[10][10];

void print() {
	for (int i = 0; i < n; i += 1) {
		printf("\n");
		for (int j = 0; j < m; j += 1) {
			printf("%3d ", arr[i][j]);
		}
	}
	printf("\n");
}

void fillArrayIx10() {
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < m; j += 1) {
			arr[i][j] = i * 10 + j;
		}
	}
}

void fillArrayZero() {
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < m; j += 1) {
			arr[i][j] = 0;
		}
	}
}

void fillArrayRand0_9() {
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < m; j += 1) {
			arr[i][j] = rand() % 10;
		}
	}
}

void OddIncrease10() {
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < m; j += 1) {
			if (arr[i][j] % 2 == 1) {
				arr[i][j] *= 10;
			}
		}
	}
}

void Share10() {
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < m; j += 1) {
			if (arr[i][j] % 10 == 0) {
				arr[i][j] /= 10;
			}
		}
	}
}

void fillArrayScanf() {
	int number;
	int count = 0;
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < m; j += 1) {
			scanf_s("%d", &number);
			arr[i][j] = number;
		}
	}
}

void save() {
	FILE* fout = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_20\\Lab_20_1.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался\n");
		return;
	}
	fprintf(fout, "%d ", n);
	fprintf(fout, "%d\n", m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fprintf(fout, "%3d ", arr[i][j]);
		}
		fprintf(fout, "\n");
	}
	fclose(fout);
}

void load() {
	FILE* fin = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_20\\Lab_20_1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	fscanf(fin, "%d", &n);
	fscanf(fin, "%d", &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(fin, "%d", &arr[i][j]);
		}
	}
	fclose(fin);
}


void deleteRow(int delRow) {
	for (int i = delRow; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr[i + 1][j];
		}
	}
	n -= 1;
}

void addColumn() {
	int column;
	printf("Введите номер дублируемого столбца: ");
	scanf_s("%d", &column);

	for (int i = 0; i < n; i += 1) {
		arr[i][m] = arr[i][column];
	}
	m += 1;
}

void ZeroLeftHigherMin() {
	int min = arr[0][0];
	int xmin = 0;
	int ymin = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] < min) {
				min = arr[i][j];
				xmin = i;
				ymin = j;
			}
		}
	}
	for (int i = xmin + 1; i < n; i += 1) {
		if (arr[i][ymin] % 2 == 1) {
			arr[i][ymin] = 0;
		}
	}
	for (int j = ymin - 1; j >= 0; j -= 1) {
		if (arr[xmin][j] % 2 == 1) {
			arr[xmin][j] = 0;
		}
	}
}

void delRowHasEven() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 2 == 0) {
				deleteRow(i);
				break;
			}
		}
	}
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int command;
	int row;

	do {
		printf("Выберите нужную вам операцию: \n");
		printf("1. Заполнить значениями i * 10 + j\n");
		printf("2. Заполнить нулями\n");
		printf("3. Заполнить случайными значениями\n");
		printf("4. Все нечетные числа увеличить в 10 раз\n");
		printf("5. Все кратные 10 уменьшить в 10 раз\n");
		printf("6. Ввод массива с клавиатуры\n");
		printf("7. Сохранение массива в файл и его загрузка из готового файла\n");
		printf("8. Загрузка массива из готового файла\n");
		printf("9. Удаление заданной строки массива\n");
		printf("10. Дублирование заданного столбца массива\n");
		printf("11. Замена всех элементов левее и ниже min на 0 (Вариант 4)\n");
		printf("12. Удаление всех строк массива в которых есть четные элементы (Вариант 4)\n");
		printf("\n");
		printf("-1. Выйти из программы\n");
		printf("Выбранная операция >>> ");
		scanf_s("%d", &command);

		switch (command)
		{
		case(1):
			fillArrayIx10();
			print();
			printf("\n");
			break;
		case(2):
			fillArrayZero();
			print();
			printf("\n");
			break;
		case(3):
			fillArrayRand0_9();
			print();
			printf("\n");
			break;
		case(4):
			OddIncrease10();
			print();
			printf("\n");
			break;
		case(5):
			Share10();
			print();
			printf("\n");
			break;
		case(6):
			fillArrayScanf();
			print();
			printf("\n");
			break;
		case(7):
			save();
			break;
		case(8):
			load();
			print();
			break;
		case(9):
			printf("Введите номер удаляемой строки: ");
			scanf_s("%d", &row);
			deleteRow(row);
			print();
			printf("\n");
			break;
		case(10):
			addColumn();
			print();
			printf("\n");
			break;
		case(11):
			// Вариант 4
			ZeroLeftHigherMin();
			print();
			printf("\n");
			break;
		case(12):
			// Вариант 4
			delRowHasEven();
			print();
			printf("\n");
			break;
		default:
			break;
		}
		printf("--------------------------------------------------\n");
	} while (command != -1);
}