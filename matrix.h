#ifndef __MATRIX__
#define __MATRIX__

#include "row.h"

typedef struct Matrix Matrix;
typedef struct MatrixBag MatrixBag;

struct MatrixBag
{
    Matrix *firstMatrix;
    Matrix *lastMatrix;
    int size;
};

struct Matrix
{
    Row *firstRow;
    Row *lastRow;
    Matrix *next;
    int size;
    int biggestRow;
};
#endif