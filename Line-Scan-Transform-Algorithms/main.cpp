#include <iostream>
#include <algorithm>
#include <pixmap.hpp>
#include <color.hpp>
#include <base.hpp>
using std::swap;
void drawLine_DDA(PixMap& pic, int x0, int y0, int x1, int y1, Color color) {
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
}

void drawLine_Bresenham(PixMap& pic, int x0, int y0, int x1, int y1, Color color) {
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
}
void DDA_test(int width, int height, char* fileName) {
    PixMap test(width, height);
    Color white(255, 255, 255);
    drawLine_Bresenham(test, 50, 10, 100, 200, white);
    test.output(fileName);
}

int main() {
    DDA_test(256, 256, "test.ppm");
    return 0;
}