#pragma once
struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
public:
    Color(int red = 255, int green = 255, int blue = 255) :
        r(red), g(green), b(blue) {}
};