#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>

#define MAX_LEN 80
char s[MAX_LEN];

int getNextDelim(FILE* fp, char token[]);
int getNextWord(FILE* fp, char token[], int maxLen);

char filename[] = "C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_23\\text4.txt";

char filenameIn[] = "C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_23\\text5.txt";
char filenameHTML[] = "C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_23\\text5_out.html";



void ChangeTabProc() {
	FILE* fin = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_23\\text1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	FILE* fout = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_23\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {

				if (s[i] == '\t') {
					s[i] = '%';
				}
			}
			fprintf(fout, "%s", s);
		}
	}
	fclose(fin);
	fclose(fout);
}

void ChangeToupper() {
	FILE* fin = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_23\\text2.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	FILE* fout = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_23\\out2.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {
				s[i] = toupper(s[i]);
			}
			fprintf(fout, "%s", s);
		}
	}
	fclose(fin);
	fclose(fout);
}

void PrintIfThereLetter() {
	FILE* fin = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_23\\text3.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	FILE* fout = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_23\\out3.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			int count = 0;
			int i;
			for (i = 0; s[i] != '\0'; i++) {
				if (islower(s[i]) || isupper(s[i])) {
					count++;
				}
			}
			if (count != 0) {
				s[i] = '#';
			}
			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	}
	fclose(fin);
	fclose(fout);
}

void WordsAndSeparators() {
	FILE* fin = fopen(filename, "rt");
	if (fin == NULL) {
		printf("File %s doesn't opened!\n", filename);
		return;
	}
	char token[MAX_LEN];
	int res;

	while (!feof(fin)) {
		while (getNextDelim(fin, token)) {
			printf("<DELIM>%s</DELIM>\n", token);
		}
		if (getNextWord(fin, token, MAX_LEN)) {
			printf("<WORD>%s</WORD>\n", token);
		}
	}

	fclose(fin);
}

int isalpha_my(unsigned char ch);

int getNextDelim(FILE* fp, char token[])
{
	int ch = getc(fp);
	if (ch == EOF) {
		return 0;
	}
	if (isalpha_my((unsigned char)ch)) {
		ungetc(ch, fp);
		return 0;
	}
	token[0] = (unsigned char)ch;
	token[1] = '\0';
		return 1;
}

int getNextWord(FILE* fp, char token[], int maxLen)
{
	int i = 0;
	int ch;
	while (((ch = getc(fp)) != EOF) && (i < maxLen - 1)) {
		if (!isalpha_my((unsigned char)(ch))) {
			break;
		}
		token[i++] = ch;
	}
	ungetc(ch, fp);
	token[i] = '\0';
		if (i == 0)
			return 0;
	return 1;
}

int isalpha_my(unsigned char ch) {
	if (isalpha(ch))
		return 1;
	if (ch >= 192 && ch <= 223)
		return 1;
	if (ch >= 224 && ch <= 255)
		return 1;
	return 0;
}

void Html() {
	FILE* fin = fopen(filenameIn, "rt");
	if (fin == NULL) {
		printf("File %s doesn't opened!\n", filenameIn);
		return;
	}
	FILE* fout = fopen(filenameHTML, "wt");
	if (fout == NULL) {
		fclose(fin);
		printf("File %s doesn't opened!\n", filenameHTML);
		return;
	}
	fprintf(fout, "<!DOCTYPE html>");
	fprintf(fout, "<html>");
	fprintf(fout, "<head>");
	fprintf(fout, "<meta http - equiv = \"Content-Type\" content = 	\"text/html; charset=utf-8\" />");
	fprintf(fout, "<title>HTML Document</title>");
	fprintf(fout, "</head>");
	fprintf(fout, "<body>");

	int ch;
	while ((ch = getc(fin)) != EOF) {
		fprintf(fout, "%c", ch);
		if (ch == '\n')
			fprintf(fout, "<br>");
	}

	fprintf(fout, "</body>");
	fprintf(fout, "</html>");

	fclose(fin);

	fclose(fout);
}

void PrintNumberSemicolon() {
	FILE* fin = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_23\\text6.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	FILE* fout = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_23\\out6.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			int count = 0;
			int i;
			for (i = 0; s[i] != '\0'; i++) {
				if (s[i] == ';') {
					count++;
				}
			}
			fprintf(fout, "%s %d\n", s, count);
			printf(">>%s %d<<\n", s, count);
		}
	}
	fclose(fin);
	fclose(fout);
}

void ReplaceCapitalLetters() {
	FILE* fin = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_23\\text7.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	FILE* fout = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_23\\out7.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			int i;
			for (i = 0; s[i] != '\0'; i++) {
				if (isupper(s[i])) {
					s[i] = '$';
				}
			}
			fprintf(fout, "%s\n", s);
			printf(">>%s<<\n", s);
		}
	}
	fclose(fin);
	fclose(fout);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//ChangeTabProc(); // Задание 1
	//ChangeToupper(); // Задание 2
	//PrintIfThereLetter(); // Задание 3
	//WordsAndSeparators(); // Задание 4
	//Html(); // Задача 5
	//PrintNumberSemicolon(); // Задача 6
	ReplaceCapitalLetters(); // Задание 7 (Вариант 3)

}