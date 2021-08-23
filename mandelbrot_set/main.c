#include <stdio.h>
#include <math.h>

#define w 120
#define h 30

typedef struct {double x; double y;} vec2;

int main(void){
    char gradient[] = " .':,\"!/r(l1Z4H9W8$@";
    char screen[w * h];
    for(int i = 0; i < w; i++)
        for(int j = 0; j < h; j++){
            vec2 uv = {i, j};
            uv.x = (uv.x / w - 0.6) * 4;
            uv.y = (uv.y / h - 0.5) * 2.2;
            int n, z;
            n = z = 0;
            vec2 c = {uv.x, uv.y};
            while (n < 100){
                vec2 comp = {uv.x * uv.x - uv.y * uv.y, 2 * uv.x * uv.y};
                uv.x = comp.x + c.x;
                uv.y = comp.y + c.y;
                if (abs(uv.x + uv.y) > 5) break;
                n++;
            }
            int col;
            col = n / 2.5;
            if (col < 0) col = 0;
            if (col > 19) col = 19;
            if (n == 100)
                col = 19;
            screen[i+j*w] = gradient[col];
        }
    screen[w*h] = 0;
    printf("%s", screen);
    getchar();
    return 0;
}