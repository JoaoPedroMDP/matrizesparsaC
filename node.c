#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *mallocNode()
{
    Node *newNode = malloc(sizeof(Node));
    newNode->col = 0;
    newNode->row = 0;
    newNode->data = 0;
    return newNode;
}

Node *createNode(int row, int col, int data)
{
    Node *newNode = mallocNode();
    newNode->col = col;
    newNode->row = row;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void printNode(Node *node)
{
    printf(" %3d", node->data);
}

Node *removeNode(Node *node)
{
    node->data = 0;
    node->row = 0;
    node->col = 0;
    return node->next;
}

void db(char *str)
{
    printf("\n%s", str);
}

void dbint(int integ)
{
    printf("%d\n", integ);
}

Node *sumNodes(Node *first, Node *second, int col)
{
    int sum = first->data + second->data;
    if(sum == 0){
        return zeroNode;
    }

    return createNode(
        first->row,
        col,
        sum
    );
}