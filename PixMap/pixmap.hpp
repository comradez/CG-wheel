#include <cstdio>
#include <vector>
#include <cassert>
using std::vector;
using RawMap = vector<vector<unsigned char>>;

//TODO: 把assert改为try-catch

class PixMap {
private:
    RawMap _red;
    RawMap _green;
    RawMap _blue;
    int _width, _height;
public:
    PixMap(int width = 0, int height = 0)
        : _width(width), _height(height) {
        _red  .resize(height);
        _green.resize(height);
        _blue .resize(height);
        for (int i = 0; i < height; i++) {
            _red[i]  .resize(width);
            _green[i].resize(width);
            _blue[i] .resize(width);
        }
    }
    PixMap() : PixMap(0, 0) {}
    ~PixMap() {}
    int size() const {
        return _width * _height;
    }
    void setMap(RawMap red, RawMap green, RawMap blue) {
        _red   = red;
        _green = green;
        _blue  = blue;
    }
    void drawPixel(int x, int y, int r, int g, int b) {
        //以左上角为原点，向右为x轴正方向，向下为y轴正方向
        assert(0 <= x && x < _width);
        assert(0 <= y && y < _height);
        _red[y][x]   = r;
        _green[y][x] = g;
        _blue[y][x]  = b;
    }
    void output(char* target) const {
        FILE* dst = fopen(target, "w");
        fprintf(dst, "P3\n%d %d\n%d\n", _width, _height, 255);
        for (int i = 0; i < _width; i++) {
            for (int j = 0; j < _height; j++) {
                fprintf(dst, "%d %d %d ", _red[i][j], _green[i][j], _blue[i][j]);
            }
        } fclose(dst);
    }
};
