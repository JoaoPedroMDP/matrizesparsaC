#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *mallocNode()
{
    return malloc(sizeof(Node));
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
    printf(" %d", node->data);
}

void db(char *str)
{
    printf("\n%s\n", str);
}