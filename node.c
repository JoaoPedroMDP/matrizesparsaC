#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/*
 * Cria um novo nó
 */
Node *createNode(int row, int col, int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    newNode->row = row;
    newNode->col = col;
    return newNode;
}

void printZeroNode()
{
    printf("0 ");
}

void printNode(Node *node)
{
    printf("%d ", node->data);
}

void dbin()
{
    printf("<[");
}

void dbout()
{
    printf("]>");
}

void dbint(int num)
{
    printf("\n>>%d<<\n", num);
}