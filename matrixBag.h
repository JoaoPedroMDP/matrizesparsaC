#ifndef __MATRIXBAG__
#define __MATRIXBAG__

#include "matrix.h"
typedef struct Bag Bag;

struct Bag
{
    Matrix *first;
    Matrix *last;
    int size;
};

Bag *createBag();
Matrix *chooseMatrix(Bag *bag);
void appendMatrix(Bag *bag, Matrix *matrix);
void showAllMatrixes(Bag *bag);

#endif