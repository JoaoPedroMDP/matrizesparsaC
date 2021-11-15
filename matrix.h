#ifndef __MATRIX__
#define __MATRIX__

#include "row.h"

typedef struct Matrix Matrix;
struct Matrix
{
    Row *first;
    Row *last;
    Matrix *next;
    int size;
    int biggestRow;
};

Matrix *createMatrix();
void printMatrix(Matrix *matrix);

#endif