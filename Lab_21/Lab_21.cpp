#define _CRT_SECURE_NO_WARNINGS

#include "framework.h"
#include "Lab_21.h"
#include <Windows.h>
#include <stdio.h>

int gold = 0;
int steps = 0;

#define N 10
#define M 15
#define WIDTH 30
#define HEIGHT 20
#define MAX_LOADSTRING 100


int map[N][M] = {
    {0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0,   0, 0, 0, 0, 3,   0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,   0, 0, 0, 0, 3,   0, 0, 0, 0, 0},
    {0, 0, 0, 3, 3,   3, 3, 0, 0, 0,   3, 3, 0, 0, 0},
    {0, 0, 0, 0, 0,   0, 3, 0, 0, 0,   3, 3, 0, 0, 0},

    {0, 0, 0, 0, 0,   0, 3, 3, 3, 0,   0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,   0, 0, 0, 3, 0,   2, 0, 0, 2, 0},
    {0, 0, 0, 0, 0,   0, 0, 2, 0, 0,   2, 0, 0, 2, 0},
    {0, 0, 0, 0, 0,   0, 2, 2, 2, 2,   2, 2, 2, 2, 0},
    {0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0}
};


// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void drawMap(HDC hdc) {
    HBRUSH hBrushEmptyCell = CreateSolidBrush(RGB(200, 200, 200));
    HBRUSH hBrushGold = CreateSolidBrush(RGB(255, 255, 0));
    HBRUSH hBrushWall = CreateSolidBrush(RGB(0, 0, 0));
    HBRUSH hBrushMan = CreateSolidBrush(RGB(0, 0, 255));

    HBRUSH brush[4] = { hBrushEmptyCell, hBrushMan, hBrushWall, hBrushGold };
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {

            int x1 = j * WIDTH;
            int x2 = (j + 1) * WIDTH;
            int y1 = i * HEIGHT;
            int y2 = (i + 1) * HEIGHT;

            RECT r = { x1, y1, x2, y2 };
            FillRect(hdc, &r, brush[map[i][j]]);
        }
    }
    for (i = 0; i < 4; i += 1)
        DeleteObject(brush[i]);

    char strC[80];
    sprintf(strC, "steps=%d  gold=%d", steps, gold);

    TCHAR  strWin[80];
    OemToChar(strC, strWin);

    HFONT hFont = CreateFont(HEIGHT, 0, 0, 0, 0, 0, 0, 0,
        DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");

    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(0, 0, 128));

    TextOut(hdc, 10, HEIGHT * N, (LPCWSTR)strWin, _tcslen(strWin));

    DeleteObject(hFont);
}


void Left() {
    for (int i = 0; i < N; i += 1) {
        for (int j = 1; j < M; j += 1) {
            if (map[i][j] == 1) {
                if (map[i][j - 1] == 0) {
                    map[i][j - 1] = 1;
                    map[i][j] = 0;
                    steps++;
                }
                else if (map[i][j - 1] == 3) {
                    map[i][j - 1] = 1;
                    map[i][j] = 0;
                    steps++;
                    gold++;
                }
            }
        }
    }
}

void Right() {
    for (int i = 0; i < N; i += 1) {
        for (int j = M - 2; j >= 0; j -= 1) {
            if (map[i][j] == 1) {
                if (map[i][j + 1] == 0) {
                    map[i][j + 1] = 1;
                    map[i][j] = 0;
                    steps++;
                }
                else if (map[i][j + 1] == 3) {
                    map[i][j + 1] = 1;
                    map[i][j] = 0;
                    steps++;
                    gold++;
                }
            }
        }
    }
}

void Up() {
    for (int i = 1; i < N; i += 1) {
        for (int j = 0; j < M; j += 1) {
            if (map[i][j] == 1) {
                if (map[i - 1][j] == 0) {
                    map[i - 1][j] = 1;
                    map[i][j] = 0;
                    steps += 1;
                }
                else if (map[i - 1][j] == 3) {
                    map[i - 1][j] = 1;
                    map[i][j] = 0;
                    steps += 1;
                    gold += 1;
                }
            }
        }
    }
}

void Down() {
    for (int i = N - 2; i >= 0; i -= 1) {
        for (int j = 0; j < M; j += 1) {
            if (map[i][j] == 1) {
                if (map[i + 1][j] == 0) {
                    map[i + 1][j] = 1;
                    map[i][j] = 0;
                    steps += 1;
                }
                else if (map[i + 1][j] == 3) {
                    map[i + 1][j] = 1;
                    map[i][j] = 0;
                    steps += 1;
                    gold += 1;
                }
            }
        }
    }
}

void Save() {
    FILE* fout = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_21\\game.txt", "wt");
    if (fout == NULL) {
        printf("Выходной файл не найден\n");
        return;
    }
    fprintf(fout, "%d ", N);
    fprintf(fout, "%d\n", M);
    int i, j;

    for (i = 0; i < N; i += 1) {
        for (j = 0; j < M; j += 1) {
            fprintf(fout, "%d ", map[i][j]);
        }
        fprintf(fout, "\n");
    }
    fprintf(fout, "%d ", steps);
    fprintf(fout, "%d", gold);

    fclose(fout);
}

void Load() {
    FILE* fin = fopen("C:\\Users\\Vika\\Desktop\\Универ\\OAiP\\Lab_21\\game.txt", "rt");
    if (fin == NULL) {
        printf("Входной файл не найден\n");
        return;
    }

    int n, m;
    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &m);

    int i, j;
    for (i = 0; i < n; i += 1) {
        for (j = 0; j < m; j += 1) {
            fscanf(fin, "%d", &map[i][j]);
        }
    }

    fscanf(fin, "%d ", &steps);
    fscanf(fin, "%d", &gold);

    fclose(fin);
}

void Right_Gold() {
    for (int i = 0; i < N; i += 1) {
        for (int j = M - 2; j >= 0; j -= 1) {
            if (map[i][j] == 1) {
                if (map[i][j + 1] == 0) {
                    map[i][j + 1] = 3;
                }
            }
        }
    }
}

void Left_Wall() {
    for (int i = 0; i < N; i += 1) {
        for (int j = 1; j < M; j += 1) {
            if (map[i][j] == 1) {
                if (map[i][j - 1] == 0) {
                    map[i][j - 1] = 2;
                }
            }
        }
    }
}

void Up_Gold() {
    for (int i = 1; i < N; i += 1) {
        for (int j = 0; j < M; j += 1) {
            if (map[i][j] == 1) {
                if (map[i - 1][j] == 0) {
                    map[i - 1][j] = 3;
                }
            }
        }
    }
}

void Down_Wall() {
    for (int i = N - 2; i >= 0; i -= 1) {
        for (int j = 0; j < M; j += 1) {
            if (map[i][j] == 1) {
                if (map[i + 1][j] == 0) {
                    map[i + 1][j] = 2;
                }
            }
        }
    }
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB21, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB21));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB21));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB21);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            
            drawMap(hdc);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_DOWN:
            Down();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_LEFT:
            Left();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP:
            Up();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT:
            Right();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x53:
            Save();
            break;
        case 0x4c:
            Load();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x52: // Клавиша R (Создать золото справа) - Задание 4
            Right_Gold();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x46: // Клавиша F (Создать стену слева) - Задание 3
            Left_Wall();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x55:
            Up_Gold();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x44:
            Down_Wall();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
