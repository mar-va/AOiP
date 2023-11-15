#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

#define NUM_ELEMENTS 10

int count;
int arr[NUM_ELEMENTS];

void keyboardInput() {
    printf("count = ");
    scanf_s("%d", &count);

    printf("input %d value: ", count);
    for (int i = 0; i < count; i++) {
        scanf_s("%d", &arr[i]);
    }
}

void printElements() {
    int i = 0;
    while (i < count) {
        if (i == count - 1) {
            printf("%d\n", arr[i]);
            i += 1;
        }
        else {
            printf("%d ", arr[i]);
            i += 1;
        }
    }
}

void oddsX10() {
    for (int i = 0; i < count; i++) {
        if (arr[i] % 2 == 1) {
            arr[i] = arr[i] * 10;
        }
    }
}

void findMin() {
    int min = arr[0];
    for (int i = 1; i < count; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("min = %d\n", min);
    printf("\n");
}

void findMore10() {
    int count_ell = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] > 10) {
            count_ell += 1;
        }
    }
    printf("count elements > 10 = %d\n", count_ell);
    printf("\n");
}

void X10lastEven() {
    int index_even = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] % 2 == 0) {
            index_even = i;
        }
    }
    arr[index_even] *= 10;
}

void countEvenLeftMin() {
    int count_el = 0;
    int min = arr[0];
    int index_min;
    for (int i = 0; i < count; i++) {
        if (arr[i] < min) {
            index_min = i;
        }
    }
    for (int i = 0; i < index_min; i++) {
        if (arr[i] % 2 == 0) {
            count_el += 1;
        }
    }
    printf("count even elements left min: %d\n", count_el);
}

void oddsX10RightMin() {
    int min = arr[0];
    int index_min;
    for (int i = 0; i < count; i++) {
        if (arr[i] < min) {
            index_min = i;
        }
    }
    for (int i = arr[index_min] + 1; i < count; i++) {
        if (arr[i] % 2 == 1) {
            arr[i] *= 10;
        }
    }
}

void maxAndMin() {
    int min = arr[0];
    int max = arr[0];
    int index_min = 0;
    int index_max = 0;
    int permutation;
    for (int i = 0; i < count; i++) {
        if (arr[i] < min) {
            min = arr[i];
            index_min = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            index_max = i;
        }
    }
    printf("������ ������������ �����: %d\n", index_min);
    printf("������ ������������� �����: %d\n", index_max);
    permutation = arr[index_max];
    arr[index_max] = arr[index_min];
    arr[index_min] = permutation;
}

void evenX1() {
    for (int i = 0; i < count; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = arr[i] * (-1);
        }
    }
}

void elementsLess4() {
    for (int i = 0; i < count; i++) {
        if (arr[i] < 4) {
            arr[i] = 4;
        }
    }
}

void betweenMaxAndMinX10() {
    int min = arr[0];
    int max = arr[0];
    int index_min = 0;
    int index_max = 0;
    int start;
    int end;
    for (int i = 0; i < count; i++) {
        if (arr[i] < min) {
            min = arr[i];
            index_min = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            index_max = i;
        }
    }
    if (index_min > index_max) {
        start = index_max + 1;
        end = index_min;
    }
    else {
        start = index_min + 1;
        end = index_max;
    }
    for (int i = start; i < end; i++) {
        arr[i] = arr[i] * 10;
    }
}

void betweenFirtAndLastEvenX100() {
    int index_first_even = 0;
    int index_last_even = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] % 2 == 0) {
            index_first_even = i;
            break;
        }
    }
    for (int i = 0; i < count; i++) {
        if (arr[i] % 2 == 0) {
            index_last_even = i;
        }
    }
    for (int i = index_first_even + 1; i < index_last_even; i++) {
        arr[i] = arr[i] * 100;
    }
}

void deleteElement(int delIndex) {
    for (int i = delIndex; i < count - 1; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
}

void insertElement(int insIndex, int value) {
    for (int i = count; i > insIndex; --i) {
        arr[i] = arr[i - 1];
    }
    count++;
    arr[insIndex] = value;
}

int findIndexMin() {
    int min = arr[0];
    int indexMin = 0;
    for (int i = 1; i < count; i++) {
        if (arr[i] < min) {
            min = arr[i];
            indexMin = i;
        }
    }
    return indexMin;
}

void SaveArray() {
    int i;

    FILE* fin = fopen("C:\\Users\\Vika\\Desktop\\������\\OAiP\\Lab_16_and_17\\in.txt", "rt");
    if (fin == NULL) {
        printf("������� ���� �� ������\n");
        return;
    }
    fscanf(fin, "%d", &count);
    for (i = 0; i < count; i += 1) {
        fscanf(fin, "%d", &arr[i]);
    }
    fclose(fin);
}

void LoadArray() {
    int i;

    FILE* fout = fopen("C:\\Users\\Vika\\Desktop\\������\\OAiP\\Lab_16_and_17\\out.txt", "wt");
    if (fout == NULL) {
        printf("�������� ���� �� ��������\n");
        return;
    }

    fprintf(fout, "%d\n", count);
    for (i = 0; i < count; i += 1) {
        fprintf(fout, "%d ", arr[i]);
    }
    fclose(fout);
}



void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int item;

    do {
        printf("------------------------------\n");
        printf("���������� �������:");
        printElements();
        printf("\n");
        printf("1. ������ ������ � ����������\n");
        printf("2. X10 ��� �������� ���������\n");
        printf("3. ����� ����������� �������\n");
        printf("4. ���������� ���������� ��������� ������ 10\n");
        printf("5. X10 ��� ���������� ������� ��������\n");
        printf("6. ������� ������ ����� ������������?\n");
        printf("7. �������� �������� ������ min �������� �� 10\n");
        printf("8. �������� ������� min � max\n");
        printf("9. ��� ������ �������� ������� �������� �� -1\n");
        printf("10. ��� �������� ������� ������� �������� ������ 4 �������� �� 4\n");
        printf("11. ��� �������� ������� ����� ������������ � ����������� ��������� � 10 ���\n");
        printf("12. ��� �������� ����� ������ � ��������� ������ ��������� � 100 ���\n");
        printf("13. �������� ��������� �������� �������\n");
        printf("14. ������� ������ �������� � �������� �����\n");
        printf("15. ������� ����������� �������\n");
        printf("16. ����� ����������� ��������� �������� 0\n");
        printf("17. ������� ��� ������ ��������\n");
        printf("18. �������������� ��� ������ ��������\n");
        printf("19. �������� � ������ �������, ������ ������������\n");
        printf("20. ������� �� ������� ��� ��������, �������� ������� ������ 4\n");
        printf("\n");
        printf("0. ����� �� ���������\n");
        printf("��������� �������� >>>>>> ");
        scanf_s("%d", &item);

        switch (item) {
        case 1:
            keyboardInput();
            break;
        case 2:
            oddsX10();
            break;
        case 3:
            findMin();
            break;
        case 4:
            findMore10();
            break;
        case 5:
            X10lastEven();
            break;
        case 6:
            countEvenLeftMin();
            break;
        case 7:
            oddsX10RightMin();
            break;
        case 8:
            maxAndMin();
            break;
        case 9:
            evenX1();
            break;
        case 10:
            elementsLess4();
            break;
        case 11:
            betweenMaxAndMinX10();
            break;
        case 12:
            betweenFirtAndLastEvenX100();
            break;
        case 13:
        {
            printf("������� ������ ���������� ��������: ");
            int index;
            scanf_s("%d", &index);

            deleteElement(index);
        }
        break;
        case 14:
        {
            int index;
            int value;
            printf("����� ����� ��������� ������ �������� ����� ��������? ������� ������: ");
            scanf_s("%d", &index);
            printf("������� �������� ������ ��������: ");
            scanf_s("%d", &value);

            insertElement(index, value);
        }
        break;
        case 15:
        {
            int index_min = findIndexMin();
            printf("index min = %d\n", &index_min);
            deleteElement(index_min);
        }
        break;
        case 16:
        {
            int index_min = findIndexMin();
            printf("index min = %d\n", &index_min);
            insertElement(index_min, 0);
        }
        break;
        case 17:
        {
            for (int i = 0; i < count; i++) {
                if (arr[i] % 2 == 0) {
                    deleteElement(i);
                }
            }
        }
        break;
        case 18:
        {
            for (int i = 0; i < count; i++) {
                if (arr[i] % 2 == 0) {
                    insertElement(i, arr[i]);
                    i++;
                }
            }
        }
        break;
        case 19:
        {
            int index_min = findIndexMin();
            int min = arr[index_min];
            insertElement(0, min);
        }
        break;
        case 20:
        {
            for (int i = 0; i < count; i++) {
                if (arr[i] < 4) {
                    deleteElement(i);
                }
            }
        }
        break;
        case 21:
            SaveArray();
            break;
        case 22:
            LoadArray();
            break;
        }
    } while (item != 0);

}