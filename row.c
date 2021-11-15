#include <stdio.h>
#include <stdlib.h>
#include "row.h"

void insertNodeOnRow(Row *row, Node *newNode);
int rowIsEmpty(Row *row);

void advanceRowWalker(Row *walker)
{
    if (walker->next != NULL)
    {
        walker = walker->next;
    }
}

Row *newEmptyRow()
{
    Row *newRow = malloc(sizeof(Row));
    newRow->first = NULL;
    newRow->last = NULL;
    newRow->next = NULL;
    newRow->size = 0;
    return newRow;
}

Row *readRowFromInput(int row)
{
    int number = 0, col = 0;
    char spacing = ' ';
    Row *newRow = newEmptyRow();
    Node *newNode = NULL;

    do
    {
        scanf("%d%c", &number, &spacing);
        if (number != 0)
        {
            newNode = createNode(row, col, number);
            insertNodeOnRow(newRow, newNode);
        }
        else
        {
            newRow->size++;
        }
        col++;
    } while (spacing != '\n');

    return newRow;
}

/*
 * Verifica se a linha está vazia
 */
int rowIsEmpty(Row *row)
{
    return row->first == NULL;
}

/*
 * Insere um nó no final da linha
 */
void insertNodeOnRow(Row *row, Node *newNode)
{
    if (rowIsEmpty(row))
    {
        row->first = newNode;
    }
    else
    {
        row->last->next = newNode;
    }
    row->last = newNode;
    row->size++;
}

/*
 * Nem sempre o número da coluna atual é igual o do último nodo não-nulo
 */
int isZeroNode(int currentCol, int currentNodeCol)
{
    return currentCol != currentNodeCol;
}

int isNotTheLast(int currentCol, int colNum)
{
    return currentCol < colNum;
}

/*
 * Imprime a linha na tela
 * A ideia é sempre incrementar o número da coluna que vai ser printada
 * O que não vale para o nodo. O nodo só irá passar para o próximo caso o número
 * da coluna atual é igual ao número da coluna do nodo atual. Se isso for
 * verdadeiro, então mostra-se o conteúdo do nodo atual e passa-se para o próximo
 * Se for falso, mostro um '0' na tela e incremento o numero da coluna
 */
void printRow(Row *row, int matrixWidth)
{
    int col = 0;
    Node *walker = row->first;
    while (col < matrixWidth)
    {
        if (walker != NULL && col == walker->col)
        {
            printNode(walker);
            advanceNodeWalker(walker);
        }
        else
        {
            printZeroNode();
        }

        col++;
    }
    printf("\n");
    // }
}

/*
 * Encontra o penúltimo elemento da linha
 */
Node *findPenultimate(Row *row)
{
    Node *walker = row->first;
    while (walker != NULL)
    {
        if (walker->next == row->last)
        {
            return walker;
        }

        advanceNodeWalker(walker);
    }

    return walker;
}

/*
 * Verifica se um elemento é o primeiro da linha
 */
int isFirstElement(Row *row, Node *node)
{
    return (row->first == node) || (row->size == 0);
}

Node *getNodeByCoordinates(Row *nodeRow, int row, int col)
{
    Node *walker = nodeRow->first;
    while (walker != NULL)
    {
        if (walker->row == row && walker->col == col)
        {
            return walker;
        }

        walker = walker->next;
    }

    return NULL;
}