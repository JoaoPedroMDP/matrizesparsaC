#include <stdio.h>
#include <stdlib.h>
#include "row.h"

Row *mallocRow(int rowNum)
{
    Row *newRow = malloc(sizeof(Row));
    newRow->next = NULL;
    newRow->first = NULL;
    newRow->last = NULL;
    newRow->size = 0;
    newRow->currentNode = NULL;
    newRow->row = rowNum;
    return newRow;
}

void appendNode(Row *row, Node *node);
Row *createRow(int rowNum)
{
    Row *newRow = mallocRow(rowNum);
    int number = 0, col = 0;
    char spacing = ' ';

    do
    {
        scanf("%d%c", &number, &spacing);
        if (number != 0)
        {
            appendNode(
                newRow,
                createNode(newRow->row, col, number)
            );
        }
        else
        {
            newRow->size++;
        }
        col++;
    } while (spacing != '\n');

    return newRow;
}

void appendNode(Row *row, Node *node)
{
    if (row->first == NULL)
    {
        row->first = node;
    }
    else
    {
        row->last->next = node;
    }

    row->last = node;
    row->size++;
}

int isLastNode(Row *row, Node *node);
Node *getNode(int rowNum, int colNum, Row *row) // TODO: uhm teoricamente não preciso desse rowNum kkkk n sei pq ele tá aqui. Mai funciona
{
    Node *walker = row->first;
    while (walker != NULL)
    {
        if (walker->row == rowNum && walker->col == colNum)
        {
            return walker;
        }
        else
        {
            walker = walker->next;
        }
    }

    return zeroNode;
}

void printRow(Row *row, int cols)
{
    Node *walker = row->first;
    int colTracker = 0;

    for (colTracker = 0; colTracker < cols; colTracker++)
    {
        printNode(
            getNode(
                row->row,
                colTracker,
                row));

        if (walker != NULL)
        {
            walker = walker->next;
        }
    }
}

void removeRow(Row *row)
{
    Node *walker = row->first;
    while (walker != NULL)
    {
        removeNode(walker);
        row->size--;
        walker = walker->next;
    }

    free(row);
}