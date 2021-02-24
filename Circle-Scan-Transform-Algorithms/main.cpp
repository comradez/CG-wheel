#include <iostream>
#include <algorithm>
#include "../PixMap/pixmap.hpp"
#include "../PixMap/color.hpp"
#include "../PixMap/base.hpp"
using std::swap;

void circleDraw(PixMap& pic, int cx, int cy, int x, int y, Color color) {
	pic.drawPixel( x + cx,  y + cy, color);
	pic.drawPixel(-x + cx,  y + cy, color);
	pic.drawPixel( x + cx, -y + cy, color);
	pic.drawPixel(-x + cx, -y + cy, color);
	pic.drawPixel( y + cx,  x + cy, color);
	pic.drawPixel(-y + cx,  x + cy, color);
	pic.drawPixel( y + cx, -x + cy, color);
	pic.drawPixel(-y + cx, -x + cy, color);
}

void midPointCircle(PixMap& pic, int cx, int cy, int r, Color color) {
	int x = 0, y = r;
	double d = 1.25 -  r;
	circleDraw(pic, cx, cy, x, y, color);
	while (x <= y) {
		if (d < 0) {
			d +=  2 * x + 3;
		} else {
			d += 2 * (x - y) + 5;
			y -= 1;
		} x += 1;
		circleDraw(pic, cx, cy, x, y, color);
	}
}

void DDA_test(int width, int height, char* fileName) {
    PixMap test(width, height);
    Color white(255, 255, 255);
    midPointCircle(test, 60, 100, 40, white);
	test.output(fileName);
}

int main() {
    DDA_test(256, 256, "test.ppm");
    return 0;
}