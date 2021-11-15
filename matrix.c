#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix *mallocMatrix()
{
    return malloc(sizeof(Matrix));
}

void appendRow(Matrix *matrix, Row *row);
Matrix *createMatrix()
{
    Matrix *newMatrix = mallocMatrix();
    char keepInsertion = 'S';
    do
    {
        appendRow(newMatrix, createRow(newMatrix->size));
        printf("Continuar inserindo? S/n");
        scanf("%c", &keepInsertion);
    } while (keepInsertion == 'S' || keepInsertion == 's');

    return newMatrix;
}

void appendRow(Matrix *matrix, Row *row)
{
    if (matrix->first == NULL)
    {
        matrix->first = row;
    }
    else
    {
        matrix->last->next = row;
    }

    if(row->size > matrix->biggestRow)
    {
        matrix->biggestRow = row->size;
    }

    matrix->last = row;
    matrix->size++;
}

void printMatrix(Matrix *matrix)
{
    Row *walker = matrix->first;

    while(walker != NULL)
    {
        printRow(walker, matrix->biggestRow);
        printf("\n");
        walker = walker->next;
    }
}