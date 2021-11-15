#include <stdio.h>
#include <stdlib.h>
#include "matrixBag.h"

Bag *mallocBag()
{
    return malloc(sizeof(Bag));
}

Bag *createBag()
{
    Bag *newBag = mallocBag();
    newBag->first = NULL;
    newBag->last = NULL;
    newBag->size = 0;

    return newBag;
}

Matrix *getMatrixByIndex(Bag *bag, int matrixIndex);
Matrix *chooseMatrix(Bag *bag)
{
    int matrix = 0;
    printf("Selecione uma matrix (a primeira matriz eh indexada por 0)");
    scanf("%d", &matrix);
    return getMatrixByIndex(bag, matrix);
}

Matrix *getMatrixByIndex(Bag *bag, int matrixIndex)
{
    Matrix *walker = bag->first;
    int i = 0;
    for (i = 0; walker != NULL; i++)
    {
        if (i == matrixIndex)
        {
            return walker;
        }
        else
        {
            walker = walker->next;
        }
    }

    printf("Matriz nao encontrada!\n");
    return NULL;
}

void appendMatrix(Bag *bag, Matrix *matrix)
{
    if (bag->first == NULL)
    {
        bag->first = matrix;
    }
    else
    {
        bag->last->next = matrix;
    }

    bag->last = matrix;
    bag->size++;
}