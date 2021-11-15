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

Node *createNode(int row, int col, int data);
void advanceNodeWalker(Node *walker);
void printZeroNode();
void printNode(Node *node);
void db();
void dbint(int num);
void dbout();
void dbin();
#endif