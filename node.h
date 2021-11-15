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

Node *zeroNode;

Node *createNode(int row, int col, int data);
void printNode(Node *node);

void db(char *str);
#endif