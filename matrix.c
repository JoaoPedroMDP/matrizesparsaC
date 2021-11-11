#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/*Cria uma bolsa vazia de matrizes*/
MatrixBag *createBag()
{
    MatrixBag *newBag = malloc(sizeof(MatrixBag));
    newBag->firstMatrix = NULL;
    newBag->lastMatrix = NULL;
    newBag->size = 0;
    return newBag;
}

int bagIsEmpty(MatrixBag *bag)
{
    return bag->size == 0;
}

/* Procura por uma matriz de acordo com o index dela.
 * NÂO PROCESSA OFFSET DE INPUT DO USUÁRIO, 
 * Se mandar 4 vai procurar pelo 4 começando do 0, e não pelo 3 começando do 0
 */
Matrix *getMatrixByIndex(MatrixBag *bag, int index)
{
    int i;
    Matrix *finder = bag->firstMatrix;
    for (i = 0; i < bag->size; i++)
    {
        if (i == index)
        {
            return finder;
        }
        else
        {
            finder = finder->next;
        }
    }
    printf("Endereço não encontrado");
    return NULL;
}

int matrixIsEmpty(Matrix *matrix)
{
    return matrix->size == 0;
}

void updateBiggestRow(Matrix *matrix, Row *newRow)
{
    if (newRow->size > matrix->biggestRow)
    {
        matrix->biggestRow = newRow->size;
    }
}

void insertRowInMatrix(Matrix *matrix, Row *newRow)
{
    if (matrixIsEmpty(matrix))
    {
        matrix->firstRow = newRow;
    }
    else
    {
        matrix->lastRow->next = newRow;
    }
    matrix->lastRow = newRow;
    matrix->size++;

    updateBiggestRow(matrix, newRow);
}

Matrix *createMatrixOption()
{
    char keepReading = 'S';

    Matrix *newMatrix = newEmptyMatrix();

    while (keepReading == 'S' || keepReading == 's')
    {
        //  O tamanho da matriz é definido pelo numero de linhas, portanto posso usar o tamanho
        // para dizer qual linha está sendo inserida no momento
        Row *newRow = readRowFromInput(newMatrix->size);
        insertRowInMatrix(newMatrix, newRow);
        printf("Continuar inserindo? S/n");
        scanf("%c", &keepReading);
    }

    return newMatrix;
}

Matrix *newEmptyMatrix()
{
    Matrix *newMatrix = malloc(sizeof(Matrix));
    newMatrix->firstRow = NULL;
    newMatrix->lastRow = NULL;
    newMatrix->next = NULL;
    newMatrix->size = 0;
    newMatrix->biggestRow = 0;

    return newMatrix;
}

void printMatrix(Matrix *matrix)
{
    Row *row = matrix->firstRow;
    while (row != NULL)
    {
        printRow(row, matrix->biggestRow);
        row = row->next;
    }
}

Matrix *chooseMatrix(MatrixBag *bag)
{
    int wantedMatrix = 0;
    printf("Digite o numero da matriz. Lembre-se que a primeira matriz eh a 0: ");
    setbuf(stdin, 0);
    scanf("%d", &wantedMatrix);
    return getMatrixByIndex(bag, wantedMatrix);
}

void insertMatrixOnBag(Matrix *newMatrix, MatrixBag *bag)
{
    if (bagIsEmpty(bag))
    {
        bag->firstMatrix = newMatrix;
    }
    else
    {
        bag->lastMatrix->next = newMatrix;
    }
    bag->lastMatrix = newMatrix;
    bag->size++;
}

int matrixIsSquared(Matrix *matrix)
{
    return matrix->biggestRow == matrix->size;
}

void showMainDiagonal(Matrix *matrix)
{
    Row *walker = matrix->firstRow;
    Node *toShow = NULL;
    int row = 0, col = 0;
    while (row < matrix->size)
    {
        toShow = getNodeByCoordinates(walker, row, col);
        if (toShow == NULL)
        {
            printZeroNode();
        }
        else
        {
            printNode(toShow);
        }
        col++;
        row++;
        walker = walker->next;
    }
}

void showMainDiagonalOption(Matrix *matrix)
{
    if (matrixIsSquared(matrix))
    {
        showMainDiagonal(matrix);
    }
    else
    {
        printf("Somente matrizes quadradas tem diagonais");
    }
}

Matrix *iterateUntilNext(MatrixBag *bag, Matrix *matrix)
{
    Matrix *walker = bag->firstMatrix;
    while (walker->next != matrix)
    {
        walker = walker->next;
    }

    return walker;
}

void removeFromBeginning(MatrixBag *bag, Matrix *matrix)
{
    bag->firstMatrix = bag->firstMatrix->next;
}

void removeFromEnd(MatrixBag *bag, Matrix *matrix)
{
    bag->lastMatrix = iterateUntilNext(bag, bag->firstMatrix);
}

void removeFromMiddle(MatrixBag *bag, Matrix *matrix)
{
    Matrix *previousMatrix = iterateUntilNext(bag, matrix);
    previousMatrix->next = matrix->next;
}

void removeMatrix(MatrixBag *bag, Matrix *matrix)
{
    if (matrix == bag->firstMatrix)
    {
        removeFromBeginning(bag, matrix);
    }
    else if (matrix == bag->lastMatrix)
    {
        removeFromEnd(bag, matrix);
    }
    else
    {
        removeFromMiddle(bag, matrix);
    }
    free(matrix);
    bag->size--;
}

void showAllMatrixes(MatrixBag *bag)
{
    int i = 0;
    Matrix *walker = bag->firstMatrix;
    while (walker != NULL)
    {
        printf("Matriz %d:\n", i);
        printMatrix(walker);
        printf("\n");
        walker = walker->next;
    }
}

// void transposeMatrix(Matrix *matrix)
// {
//     Matrix *transposedMatrix = newEmptyMatrix();
//     Row *rowWalker = matrix->firstRow;
//     Node *colWalker = rowWalker->first;
//     int col = 0, row = 0;

//     while (row < matrix->size)
//     {
//         while (col <)
//     }
// }