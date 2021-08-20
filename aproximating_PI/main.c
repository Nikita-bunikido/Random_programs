#include <stdio.h>
#include <limits.h>
#include <math.h>

#define ran(f, t) (f+rand()%(abs(f)+t))
#define r 200

main(){
    srand(1);
    int circle, total, i, _x, _y;
    circle = total = i = _x = _y = 0;
    double pi;
    while (LONG_MAX - 1 > i++){
        _x = ran(-r, r);
        _y = ran(-r, r);
        ++total;
        circle += (sqrt(_x * _x + _y * _y) < r) ? 1 : 0;
        pi = 4.0 * ((double)circle / total);
        if(!(i % 100000))
            printf("%.8g\n", pi);
    }
    return 0;
}