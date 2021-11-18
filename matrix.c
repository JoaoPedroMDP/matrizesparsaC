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
    newMatrix->cols = -1;

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

    if (row->size > matrix->cols)
    {
        matrix->cols = row->size;
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
            printf("\n");
            printRow(matrix->currentRow, matrix->cols);
            printf("\n");
            matrix->currentRow = matrix->currentRow->next;
        }
    }
}

Matrix *removeMatrix(Matrix *matrix)
{
    Row *walker = matrix->first;

    while (walker != NULL)
    {
        walker = removeRow(walker);
        matrix->size--;
    }

    return matrix->next;
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
    return matrix->size == matrix->cols;
}

void createAllRows(Matrix *toReceiveTheRows, int rowNum);
Matrix *transposeMatrix(Matrix *matrix)
{
    int col = 0;
    Row *rowWalker = matrix->first;
    Node *nodeWalker = NULL;
    Matrix *transposed = mallocMatrix();

    transposed->cols = matrix->size;

    createAllRows(transposed, matrix->cols);
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
            sumRows(first->currentRow, second->currentRow)
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

Matrix *invertMatrixElements(Matrix *matrix);
void subtractMatrixes(Matrix *first, Matrix *second)
{
    sumMatrixes(
        first,
        invertMatrixElements(second)
    );
}

void copyMatrix(Matrix *copy,Matrix* paste);
Matrix *invertMatrixElements(Matrix *matrix)
{
    Matrix *inverted = mallocMatrix();
    copyMatrix(matrix, inverted);

    resetCurrents(inverted);
    while(inverted->currentRow != NULL)
    {
        inverted->currentRow->currentNode = inverted->currentRow->first;
        while(inverted->currentRow->currentNode != NULL)
        {
            inverted->currentRow->currentNode->data = inverted->currentRow->currentNode->data * -1;
            inverted->currentRow->currentNode = inverted->currentRow->currentNode->next;
        }

        inverted->currentRow = inverted->currentRow->next;
    }

    return inverted;
}

void copyMatrix(Matrix *copy, Matrix* paste)
{
    createAllRows(paste, copy->size);
    resetCurrents(copy);resetCurrents(paste);

    while(copy->currentRow != NULL)
    {
        copyRows(copy->currentRow, paste->currentRow);
        copy->currentRow = copy->currentRow->next;
        paste->currentRow = paste->currentRow->next;
    }
}

void multiplyMatrixByRow(Matrix *matrix, Row *row, Row *results);
int multiplyMatrixes(Matrix *first, Matrix *second)
{
    if(first->cols != second->size)
    {
        printf("Voce so pode multiplicar matrizes caso o 'j' da primeira seja igual ao 'i' da segunda");
        return 0;
    }

    Matrix *result = mallocMatrix();
    createAllRows(result, first->size);
    result->cols = second->cols;
    resetCurrents(first);resetCurrents(second);resetCurrents(result);
    while(first->currentRow)
    {
        multiplyMatrixByRow(second, first->currentRow, result->currentRow);
        resetCurrents(second);
        first->currentRow = first->currentRow->next;
        result->currentRow = result->currentRow->next;
    }

    printMatrix(result);
    return 1;
}

int multiplyColumnByRow(Matrix *matrix, Row *row, int col);
void multiplyMatrixByRow(Matrix *matrix, Row *row, Row *results)
{
    int col = 0;
    for( col = 0; col < row->size; col++)
    {
        appendNode(
            results,
            createNode(
                row->row,
                col,
                multiplyColumnByRow(matrix, row, col)
                )
            );
    }
}

int multiplyColumnByRow(Matrix *matrix, Row *row, int col)
{
    int result = 0, colTracker = 0;
    Node *first = NULL, *second = NULL;

    matrix->currentRow = matrix->first;
    while(colTracker < row->size)
    {
        first = getNode(colTracker, row);
        second = getNode(col, matrix->currentRow);
        result += first->data * second->data;

        matrix->currentRow = matrix->currentRow->next;
        colTracker++;
    }

    return result;
}