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
#endif