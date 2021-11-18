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

void showAllMatrixes(Bag *bag)
{
    Matrix *walker = bag->first;
    int i = 0;

    for (i = 0; walker != NULL; i++)
    {
        printf("\nMatriz %d", i);
        printMatrix(walker);
        printf("\n");
        walker = walker->next;
    }
}

int isFirstMatrix(Bag *bag, Matrix *matrix);
int isLastMatrix(Bag *bag, Matrix *matrix);
Matrix *getPreviousMatrix(Bag *bag, Matrix *matrix);
void removeMatrixFromBag(Bag *bag, Matrix *matrix)
{
    if(matrix != NULL){

        if(isFirstMatrix(bag, matrix))
        {
            bag->first = matrix->next;
        }else{
            Matrix *previous = getPreviousMatrix(bag, matrix);
            previous->next = matrix->next;
            if(isLastMatrix(bag, matrix))
            {
                bag->last = previous;
            }
        }
        removeMatrix(matrix);
        free(matrix);

        if(bag->size == 0){
            bag->first = NULL;
            bag->last = NULL;
        }

        bag->size--;
    }
}

void replaceMatrixes(Bag *bag, Matrix *new, Matrix *old)
{
    if(isFirstMatrix(bag, old) || isLastMatrix(bag, old))
    {
        bag->first = new;
        bag->last = new;
    }else
    {
        Matrix *previous = getPreviousMatrix(bag, old);

        previous->next = new;
        new->next = old->next;
    }

    free(old);
}

int isFirstMatrix(Bag *bag, Matrix *matrix)
{
    return bag->first == matrix;
}

int isLastMatrix(Bag *bag, Matrix *matrix)
{
    return bag->last == matrix;
}

Matrix *getPreviousMatrix(Bag *bag, Matrix *matrix)
{
    Matrix *walker = bag->first;

    while(walker != NULL)
    {
        if(walker->next == matrix)
        {
            return walker;
        }else{
            walker = walker->next;
        }
    }

    printf("Nao foi encontrada a matriz anterior");
    return NULL;
}
