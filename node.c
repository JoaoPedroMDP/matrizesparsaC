#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "node.h"

Node *mallocNode()
{
    Node *newNode = malloc(sizeof(Node));
    newNode->col = 0;
    newNode->row = 0;
    newNode->data = 0;
    return newNode;
}

Node *createNode(int row, int col, float data)
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
    setlocale(LC_NUMERIC, "C");
    if(node->data == 0)
    {
        printf("\033[0;31m");
        printf(" %3.2f", node->data);
        printf("\033[0m");
    }else
    {
        printf(" %3.2f", node->data);
    }
    setlocale(LC_NUMERIC, "");
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
    float sum = first->data + second->data;
    if(sum == 0){
        return zeroNode;
    }

    return createNode(
        first->row,
        col,
        sum
    );
}