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

MatrixBag *createBag();
Matrix *getMatrixByIndex(MatrixBag *bag, int index);
Matrix *createMatrixOption();
void insertMatrixOnBag(Matrix *newMatrix, MatrixBag *bag);
void printMatrix(Matrix *matrix);
Matrix *chooseMatrix(MatrixBag *bag);
Matrix *newEmptyMatrix();
void showMainDiagonal(Matrix *matrix);
void showMainDiagonalOption(Matrix *matrix);
void removeMatrix(MatrixBag *bag, Matrix *matrix);
void transposeMatrix(Matrix *matrix);
void showAllMatrixes(MatrixBag *bag);
#endif