#ifndef __NODE__
#define __NODE__

typedef struct Node Node;
struct Node
{
    int row;
    int col;
    float data;
    Node *next;
};

Node *zeroNode;

Node *createNode(int row, int col, float data);
void printNode(Node *node);
Node *removeNode(Node *node);

Node *sumNodes(Node *first, Node *second, int col);

void db(char *str);
void dbint(int integ);
#endif