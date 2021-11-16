#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix *mallocMatrix()
{
    Matrix *newMatrix = malloc(sizeof(Matrix));
    newMatrix->first = NULL;
    newMatrix->last = NULL;
    newMatrix->next = NULL;
    newMatrix->size = 0;
    newMatrix->biggestRow = -1;

    return newMatrix;
}

void appendRow(Matrix *matrix, Row *row);
Matrix *createMatrix()
{
    db(">>>>>>>>>>>>>>>>>>>");
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

    if (row->size > matrix->biggestRow)
    {
        matrix->biggestRow = row->size;
    }
    matrix->last = row;
    matrix->size++;
}

void printMatrix(Matrix *matrix)
{
    if(matrix != NULL)
    {
        Row *walker = matrix->first;

        while (walker != NULL)
        {
            printRow(walker, matrix->biggestRow);
            printf("\n");
            walker = walker->next;
        }
    }
}

Row *getRow(int rowNum, Matrix *matrix);
void removeMatrix(Matrix *matrix)
{
    Row *walker = matrix->first;

    while (walker != NULL)
    {
        removeRow(walker);
        matrix->size--;
        walker = walker->next;
    }

    free(matrix);
}

Row *getRow(int rowNum, Matrix *matrix)
{
    Row *walker = matrix->first;
    int i = 0;
    for (i = 0; walker != NULL; i++)
    {
        if (i == rowNum)
        {
            return walker;
        }
        else
        {
            walker = walker->next;
        }
    }

    printf("Linha %d nao encontrada", rowNum);
    return NULL;
}

int isSquared(Matrix *matrix);
int showMainDiagonal(Matrix *matrix)
{
    if(matrix != NULL)
    {
        if(!isSquared(matrix))
        {
            printf("Apenas matrizes quadradas possuem diagonais.\n");
            return 0;
        }

        Row *walker = matrix->first;
        int col = 0;
        while(walker != NULL)
        {
            printNode(getNode(walker->row, col, walker));
            walker = walker->next;
            col++;
        }
    }

    return 1;
}

int isSquared(Matrix *matrix){
    return matrix->size == matrix->biggestRow;
}