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
    int cols;
};

Matrix *createMatrix();
void printMatrix(Matrix *matrix);
Matrix *removeMatrix(Matrix *matrix);
int showMainDiagonal(Matrix *matrix);
Matrix *transposeMatrix(Matrix *matrix);
Matrix *sumMatrixes(Matrix *first, Matrix *second);
Matrix *subtractMatrixes(Matrix *first, Matrix *second);
Matrix *multiplyMatrixes(Matrix *first, Matrix *second);
#endif