#include <iostream>
#include "Color.h"
#include <cmath>
using namespace std;

class Bitmap{
private:
    int row;
    int col;
    char *map;
public:
    void line(int x1, int y1, int x2, int y2,  Color& c){
        double dx = x2 - x1;
        double dy = y2 - y1;
        if (x1 == x2) {
            int x = x1;
            for (int y = y1; y <= y2; y++) {
                map[y*row+x]=color(c);
            }
            return;
        }
        double de = fabs(dy/dx);
        double error = 0;
        int y = y1;
        for (int x = x1; x <= x2; x++) {
            map[y*row+x]=color(c);
            error += de;
            if (error >= 0.5) {
                y += (dy>0)?1:(-1);
                error -= 1;
            }
        }
    }

    char color(Color & c){
        uint32_t m=c.getValue();
        if (m==0xFF000000)
            return 'R';
        if (m==0x00FF0000)
            return 'G';
        if (m==0x0000FF00)
            return 'B';
        if (m==0xFFFFFF00)
            return 'w';
        if (m==0x00000000)
            return 'b';
    }

    void horizLine(int x1, int x2, int y, Color & c){
        for(int i=0; i<x2-x1; i++){
            map[y*row+x1+i]=color(c);
        }
    }

    void vertLine(int x, int y1, int y2, Color&c){
        for(int i=y1; i<=y2; i++){
            map[i*row+x]=color(c);
        }
    }

    void fillRect(int x, int y, int w, int h, Color& c){
        for(int i=x; i<=x+w; i++) {
            for (int j = y; j <= y + h; j++){
                map[j*row+i] = color(c);
            }
        }
    }

    void drawRect(int x, int y, int w, int h, Color& c){
        for(int i=x; i<=x+w; i++) {
            map[y*row+i] = color(c);
        }
        for(int i=x; i<=x+w; i++) {
            map[(y+h)*row+i] = color(c);
        }
        for(int i=y; i<=y+h; i++) {
            map[i*row+x] = color(c);
        }
        for(int i=y; i<=y+h; i++) {
            map[i*row+x+w] = color(c);
        }
    }


    void ellipse(int x, int y, int w, int h, Color& c){
        int j1 = y;
        int j2 = y;
        double de = 0;
        double error1 = 0;
        double error2 = 0;
        for(int i =x - w/2; i < x; i++){
            map[i+j1*row] = color(c);
            map[i+j2*row] = color(c);
            //de = fabs(sqrt(pow(h,2) / 4 - h * h / w / w * x * x) - yc);
            de = fabs(sqrt(pow((y + h / 2.0), 2)) - (pow((y + h / 2.0 ), 2) * pow(i, 2) / pow((x + w / 2.0), 2)));
            error1 += de;
            error2 -= de;
            if (error1 >= 0.5) {
                j1 += 1;
                error1 -= 1;
            }
            if (error2 <= -0.5){
                j2 -= 1;
                error2 += 1;
            }
        }

        for(int i = x ; i <= x + w/2; i++){
            map[i+j1*row] = color(c);
            map[i+j2*row] = color(c);
            //de = fabs(sqrt(pow(h,2) / 4 - h * h / w / w * x * x) - yc);
            de = fabs(sqrt(pow((y + h / 2.0), 2)) - (pow((y + h / 2.0 ), 2) * pow(i, 2) / pow((x + w / 2.0), 2)));
            error1 += de;
            error2 -= de;
            if (error1 >= 0.5) {
                j1 -= 1;
                error1 -= 1;
            }
            if (error2 <= -0.5){
                j2 += 1;
                error2 += 1;
            }
        }
    }

    Bitmap(int r, int c): row(r), col(c), map((char*)new char* [row*col]){
        for (int i=0; i<row*col; i++)
            map[i]=' ';
    }

    ~Bitmap(){
        delete []map;
    }

    friend ostream& operator <<(ostream& s, const Bitmap &map){
    for(int i=0, c=0; i<20; i++){
        for(int j=0; j<30; j++,c++){
            s<< map.map[c];
        }
        s<<'\n';
    }
    return s;
}
};

int main() {
    Bitmap b(30,20); // 30 pixels across, 20 pixels high, each pixel RGBA
    // top left pixel = (0,0)
    Color RED(255,0,0); // all red, no green, no blue (fully opaque)
    Color GREEN(0,255,0);
    Color BLUE(0,0,255);
    Color WHITE(255,255,255);
    Color BLACK(0,0,0);

    b.line(0,0,   19,19, RED);
    b.line(0,5,   29,10, BLUE); //Bresenham algorithm
    //https://en.wikipedia.org/wiki/Bresenham's_line_algorithm

    // https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
    //TODO: b.line(0,100, 100,50, BLUE); //Wu algorithm
    b.horizLine(0, 20, 19, GREEN); // from x=0 to x=20 at y=19
    b.vertLine(5, 0,19, GREEN); // from y = 0 to y=19 at x = 5
    b.fillRect(10,10, 4, 3,BLACK); // x = 10, y =10 w=4, h=3
    b.drawRect(10,10, 4, 3,WHITE); // x = 10, y =10 w=4, h=3
    b.ellipse(15,1, 8, 5, RED);    // ellipse centered at (15,0) w= 8, h=5
    cout << b;
    /*
R
 R
  R
   R
    R
BBB
   BBBBB
        BBBBBB
     */
}