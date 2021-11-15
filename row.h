#ifndef __ROW__
#define __ROW__

#include "node.h"
typedef struct Row Row;

struct Row
{
    Node *first;
    Node *last;
    Row *next;
    int size;
};

void advanceRowWalker(Row *walker);
Row *readRowFromInput(int row);
void printRow(Row *row, int matrixWidth);
Node *getNodeByCoordinates(Row *nodeRow, int row, int col);

#endif