#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix *mallocMatrix()
{
    Matrix *newMatrix = malloc(sizeof(Matrix));
    newMatrix->first = NULL;
    newMatrix->last = NULL;
    newMatrix->next = NULL;
    newMatrix->currentRow = NULL;
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

void resetCurrents(Matrix *matrix);
void printMatrix(Matrix *matrix)
{
    resetCurrents(matrix);
    if(matrix != NULL)
    {
        while (matrix->currentRow != NULL)
        {
            printRow(matrix->currentRow, matrix->biggestRow);
            printf("\n");
            matrix->currentRow = matrix->currentRow->next;
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
            printNode(
                getNode(col, walker)
            );
            walker = walker->next;
            col++;
        }
    }

    return 1;
}

int isSquared(Matrix *matrix){
    return matrix->size == matrix->biggestRow;
}

void createAllRows(Matrix *toReceiveTheRows, int rowNum);
Matrix *transposeMatrix(Matrix *matrix)
{
    int col = 0;
    Row *rowWalker = matrix->first;
    Node *nodeWalker = NULL;
    Matrix *transposed = mallocMatrix();

    transposed->biggestRow = matrix->size;

    createAllRows(transposed, matrix->biggestRow);
    while(rowWalker != NULL)
    {
        col = 0;
        nodeWalker = rowWalker->first;
        transposed->currentRow = transposed->first;
        while(col < rowWalker->size){
            if(nodeWalker != NULL && col == nodeWalker->col)
            {
                appendNode(
                    transposed->currentRow,
                    createNode(
                        transposed->currentRow->row, transposed->currentRow->size, nodeWalker->data
                    )
                );

                nodeWalker = nodeWalker->next;
            }else{
                transposed->currentRow->size++;
            }

            transposed->currentRow = transposed->currentRow->next;
            col++;
        }

        rowWalker = rowWalker->next;
    }

    return transposed;
}

void createAllRows(Matrix *toReceiveTheRows, int rowNum)
{
    int i = 0;
    for( i = 0; i < rowNum; i++)
    {
        appendRow(
            toReceiveTheRows,
            mallocRow(i)
        );
    }
}

void sumMatrixes(Matrix *first, Matrix *second)
{
    int row = 0;
    Matrix *result = mallocMatrix();
    resetCurrents(first);resetCurrents(second);resetCurrents(result);

    while(first->currentRow != NULL)
    {
        appendRow(
            result,
            sumRows(first->currentRow, second->currentRow, row)
        );

        if(first->currentRow != NULL)
        {
            first->currentRow = first->currentRow->next;
        }

        if(second->currentRow != NULL)
        {
            second->currentRow = second->currentRow->next;
        }
        row++;
    }

    printMatrix(result);
}

void resetCurrents(Matrix *matrix)
{
    matrix->currentRow = matrix->first;
    while(matrix->currentRow != NULL)
    {
        matrix->currentRow->currentNode = matrix->currentRow->first;
        matrix->currentRow = matrix->currentRow->next;
    }
    matrix->currentRow = matrix->first;
}