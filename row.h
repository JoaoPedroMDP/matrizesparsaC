#ifndef __ROW__
#define __ROW__

#include "node.h"
typedef struct Row Row;

struct Row
{
    Node *first;
    Node *last;
    Node *currentNode;
    Row *next;
    int size;
    int row;
};

Row *mallocRow(int rowNum);
void appendNode(Row *row, Node *node);
Row *createRow(int rowNum);
Node *getNode(int colNum, Row *row);
void printRow(Row *row, int cols);
void removeRow(Row *row);
Row *sumRows(Row *first, Row *second, int row);
#endif