#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ITERS   200
#define MAX     300
#define ON      '@'
#define OFF     ' '

void printline(int line[], FILE *f){
    int j = 0;
    while(j < MAX){
        fprintf(f, "%c", (line[j] ? ON : OFF));
        ++j;
    }
    fprintf(f, "\n");
}

void newline(int line[], int rules[8]){
    int i, line2[MAX], index = 0;
    for(i = 0; i < MAX; ++i)
        line2[i] = line[i];

    for(i = 0; i < MAX - 2; ++i){
        int prom[3] = {line[i], line[i + 1], line[i + 2]};
        index = 0;
        for(int j = 3, k = 0; j > 0; j--, k++)
            index += prom[k] * pow(2, j - 1);
        line2[i + 1] = rules[index];
    }

    for(i = 0; i < MAX; ++i)
        line[i] = line2[i];
}

int main(){
    srand(time(NULL));
    int rules[8]  = {0, 1, 1, 1, 1, 1, 1, 0};
    int line[MAX];
    int i;
    FILE *out = fopen("out.txt", "w");
    for(i = 0; i < MAX; ++i)
        line[i] = rand()%2;
    for(i = 0; i < ITERS; ++i){
        newline(line, rules);
        printline(line, out);
    }
    fclose(out);
    return 0;
}