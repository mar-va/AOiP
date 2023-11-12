#include <Windows.h>
#include <stdio.h>
#include "framework.h"
#include "Image.h"

void Image0(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 4, color);
    SelectObject(hdc, hPen);
    POINT triangle[4];
    triangle[0].x = cx;
    triangle[0].y = cy + 20;
    triangle[1].x = cx + 20;
    triangle[1].y = cy - 20;
    triangle[2].x = cx - 20;
    triangle[2].y = cy - 20;
    triangle[3].x = cx;
    triangle[3].y = cy + 20;

    Polyline(hdc, triangle, 4);
    DeleteObject(hPen);
}

void Image1(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 4, color);
    SelectObject(hdc, hPen);

    POINT triangle[4] = {
        cx, cy - 20,
        cx + 20, cy + 20,
        cx - 20, cy + 20,
        cx, cy - 20
    };
    Polyline(hdc, triangle, 4);
    DeleteObject(hPen);
}

void Vertical_Image0(HDC hdc) {
    int x = 250;
    int y = 50;
    int i = 0;
    do {
        Image0(hdc, x, y, RGB(140, 120, 140));
        y += 70;
        i += 1;
    } while (i < 6);
}

void Horizontal_Image0(HDC hdc) {
    int x = 300;
    int y = 40;
    int i = 0;
    do {
        Image0(hdc, x, y, RGB(50, 60, 70));
        x += 50;
        i += 1;
    } while (i < 6);
}

void ColStr_Image0(HDC hdc) {
    int x, j;
    int y = 50;
    int i = 0;
    do {
        x = 100;
        j = 0;
        do {
            Image0(hdc, x, y, RGB(180, 80, 210));
            x += 50;
            j++;
        } while (j < 8);
        y += 70;
        i += 1;
    } while (i < 6);
}

void Vertical_Grad_Image0(HDC hdc) {
    int x = 700;
    int y = 50;
    int i = 0;
    char g = 0;
    do {
        Image0(hdc, x, y, RGB(g, 0, 0));
        y += 50;
        g += 40;
        i += 1;
    } while (i < 6);
}

void Horizontal_Grad_Image0(HDC hdc) {
    int x = 40;
    int y = 600;
    int i = 0;
    char g = 0;
    do {
        Image0(hdc, x, y, RGB(0, 100, g));
        x += 50;
        g += 30;
        i += 1;
    } while (i < 6);
}

void ColStr_Grad_Image0(HDC hdc) {
    int x, j;
    int y = 40;
    int i = 0;
    char g = 0;
    char r;
    do {
        x = 800;
        j = 0;
        r = 0;
        do {
            Image0(hdc, x, y, RGB(r, g, 20));
            x += 50;
            r += 35;
            j += 1;
        } while (j < 8);
        y += 50;
        g += 35;
        i += 1;
    } while (i < 6);
}

void Image2(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);

    POINT rhomb[5] = {
        cx, cy - 20,
        cx + 20, cy,
        cx, cy + 20,
        cx - 20, cy,
        cx, cy - 20
    };
    Polyline(hdc, rhomb, 5);
    DeleteObject(hPen);
}
void Image3(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);

    POINT image[5] = {
        cx - 20, cy - 20,
        cx, cy,
        cx + 20, cy - 20,
        cx, cy + 20,
        cx - 20, cy - 20
    };

    Polyline(hdc, image, 5);
    DeleteObject(hPen);
}

void Image4(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);

    POINT image[6] = {
        cx - 40, cy + 60,
        cx - 40, cy - 20,
        cx + 40, cy - 20,
        cx, cy,
        cx + 40, cy + 20,
        cx - 40, cy + 20
    };

    Polyline(hdc, image, 6);
    DeleteObject(hPen);
}

void Image5(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);

    POINT image[6] = {
        cx - 20, cy - 20,
        cx, cy,
        cx + 20, cy - 20,
        cx + 20, cy + 20,
        cx - 20, cy + 20,
        cx - 20, cy - 20
    };

    Polyline(hdc, image, 6);
    DeleteObject(hPen);
}

void Image6(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);

    POINT image[8] = {
        cx - 40, cy - 40,
        cx - 20, cy,
        cx, cy - 40,
        cx + 20, cy,
        cx + 40, cy - 40,
        cx + 30, cy + 40,
        cx - 30, cy + 40,
        cx - 40, cy - 40
    };

    Polyline(hdc, image, 8);
    DeleteObject(hPen);
}

void Image7(HDC hdc, int cx, int cy, COLORREF color_pen, COLORREF color_brush) {
    HPEN hPen = CreatePen(PS_SOLID, 3, color_pen);
    SelectObject(hdc, hPen);
    HBRUSH hBrush = CreateHatchBrush(HS_DIAGCROSS, color_brush);
    SelectObject(hdc, hBrush);
    POINT star[17]{
        cx, cy - 80,
        cx + 20, cy - 40,
        cx + 40, cy - 40,
        cx + 40, cy - 20,
        cx + 80, cy,
        cx + 40, cy + 20,
        cx + 40, cy + 40,
        cx + 20, cy + 40,
        cx, cy + 80,
        cx - 20, cy + 40,
        cx - 40, cy + 40,
        cx - 40, cy + 20,
        cx - 80, cy,
        cx - 40, cy - 20,
        cx - 40, cy - 40,
        cx - 20, cy - 40,
        cx, cy - 80
    };

    Polygon(hdc, star, 17);
    DeleteObject(hBrush);
}