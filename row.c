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

Node *getNode(int colNum, Row *row)
{
    Node *walker = row->first;
    while (walker != NULL)
    {
        if (walker->col == colNum)
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
            getNode(colTracker,row)
        );

        if (walker != NULL && walker->col == colTracker)
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

Row *sumRows(Row *first, Row *second)
{
    Node *a = NULL, *b = NULL,*sum = NULL;
    Row *result = mallocRow(first->row);
    int col = 0;
    while(col < first->size)
    {
        a = getNode(col, first);
        b = getNode(col, second);

        sum = sumNodes(
                a,
                b,
                col
            );

        if(sum->data != 0)
        {
            appendNode(
                result,
                sum
            );
        }else{
            result->size++;
        }

        col++;
    }

    return result;
}