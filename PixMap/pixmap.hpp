#include <cstdio>
#include <vector>
using std::vector;

class PixMap {
private:
    vector<vector<unsigned char>> _red;
    vector<vector<unsigned char>> _green;
    vector<vector<unsigned char>> _blue;
    int _width, _height;
public:
    PixMap(int width = 0, int height = 0)
        : _width(width), _height(height) {
        _red.resize(height);
        _green.resize(height);
        _blue.resize(height);
        for (int i = 0; i < height; i++) {
            _red[i].resize(width);
            _green[i].resize(width);
            _blue[i].resize(width);
        }
    }
    PixMap() : PixMap(0, 0) {}
    ~PixMap() {}
    int size() const {
        return _width * _height;
    }
    void setMap(vector<vector<unsigned char>> red  ,
                vector<vector<unsigned char>> green, 
                vector<vector<unsigned char>> blue) {
        _red   = red;
        _green = green;
        _blue  = blue;
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
