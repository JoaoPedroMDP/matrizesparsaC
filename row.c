#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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
    float number = 0.0;
    int col = 0;
    char spacing = ' ';

    do
    {
        setlocale(LC_NUMERIC, "C");
        scanf("%f%c", &number, &spacing);
        setlocale(LC_NUMERIC, "");
        if (number != 0.0)
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

Row *removeRow(Row *row)
{
    Node *walker = row->first;
    while (walker != NULL)
    {
        walker = removeNode(walker);
        row->size--;
    }

    return row->next;
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

void copyRows(Row *copy, Row *paste)
{
    while(copy->currentNode != NULL)
    {
        appendNode(
            paste,
            createNode(
                copy->currentNode->row,
                copy->currentNode->col,
                copy->currentNode->data
                )
            );

        copy->currentNode = copy->currentNode->next;
    }
}