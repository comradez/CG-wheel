#include <iostream>
#include <algorithm>
#include "../PixMap/pixmap.hpp"
#include "../PixMap/color.hpp"
#include "../PixMap/base.hpp"
using std::swap;

void drawLine_DDA(PixMap& pic, int x0, int y0, int x1, int y1, Color color) {
    int abs_dx = abs(x1 - x0), abs_dy = abs(y1 - y0);
    if (abs_dy <= abs_dx) { //k<=1，沿x扫描
        if (x0 == x1) {
            if (y0 > y1) {
                swap(y0, y1);
            }
            for (int y = y0; y <= y1; y++) {
                pic.drawPixel(x0, y, color);
            }
        } else {
            if (x0 > x1) {
                swap(x0, x1);
            } //保证x0 < x1
            double k = (y1 - y0) * 1.0 / (x1 - x0);
            double y = y0;
            for (int x = x0; x <= x1; x++) {
                pic.drawPixel(x, round(y), color);
                y = y + k;
            }
        }
    } else {
        if (y0 == y1) {
            if (x0 > x1) {
                swap(x0, x1);
            }
            for (int x = x0; x <= x1; x++) {
                pic.drawPixel(x, y0, color);
            }
        } else {
            if (y0 > y1) {
                swap(y0, y1);
            } //保证y0 < y1
            double t = (x1 - x0) * 1.0 / (y1 - y0);
            double x = x0;
            for (int y = y0; y <= y1; y++) {
                pic.drawPixel(round(x), y, color);
                x = x + t;
            }
        }
    }
}

void drawLine_Bresenham(PixMap& pic, int x0, int y0, int x1, int y1, Color color) {
    int abs_dx = abs(x1 - x0), abs_dy = abs(y1 - y0);
    if (abs_dy <= abs_dx) {
        if (x0 == x1) {
            if (y0 > y1) {
                swap(y0, y1);
            }
            for (int y = y0; y <= y1; y++) {
                pic.drawPixel(x0, y, color);
            }
        } else {
            if (x0 > x1) {
                swap(x0, x1);
            } //保证x0 < x1
            int dx = x1 - x0, dy = y1 - y0, e = -dx;
            int x = x0, y = y0;
            for (int i = 0; i <= dx; i++) {
                pic.drawPixel(x, y, color);
                x += 1;
                e += 2 * dy;
                if (e >= 0) {
                    y += 1;
                    e -= 2 * dx;
                }
            }
        }
    } else {
        if (y0 == y1) {
            if (x0 > x1) {
                swap(x0, x1);
            }
            for (int x = x0; x <= x1; x++) {
                pic.drawPixel(x, y0, color);
            }
        } else {
            if (y0 > y1) {
                swap(y0, y1);
            } //保证y0 < y1
            int dx = x1 - x0, dy = y1 - y0, e = -dy;
            int x = x0, y = y0;
            for (int i = 0; i <= dy; i++) {
                pic.drawPixel(x, y, color);
                y += 1;
                e += 2 * dx;
                if (e >= 0) {
                    x += 1;
                    e -= 2 * dy;
                }
            }
        }
    }
}
void DDA_test(int width, int height, char* fileName) {
    PixMap test(width, height);
    Color white(255, 255, 255);
    drawLine_Bresenham(test, 10, 100, 200, 200, white);
    test.outputPPM(fileName);
}

int main() {
    DDA_test(256, 256, "test.ppm");
    return 0;
}