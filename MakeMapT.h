#ifndef MAKEMAPT_H
#define MAKEMAPT_H

#define FALSE 0
#define TRUE !FALSE

typedef struct {
    int xPlay;
    int yPlay;
    char replace;
    int xCur;
    int yCur;
} Player;


void printMap(int rows, int columns, char *Filename, FILE* f);

#endif