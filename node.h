#ifndef __NODE__
#define __NODE__

typedef struct Node Node;
struct Node
{
    int row;
    int col;
    int data;
    Node *next;
};
#endif