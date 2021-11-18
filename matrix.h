#ifndef __MATRIX__
#define __MATRIX__

#include "row.h"

typedef struct Matrix Matrix;
struct Matrix
{
    Row *first;
    Row *last;
    Row *currentRow;
    Matrix *next;
    int size;
    int biggestRow;
};

Matrix *createMatrix();
void printMatrix(Matrix *matrix);
void removeMatrix(Matrix *matrix);
int showMainDiagonal(Matrix *matrix);
Matrix *transposeMatrix(Matrix *matrix);
void sumMatrixes(Matrix *first, Matrix *second);
#endif