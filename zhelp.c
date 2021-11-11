#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_ITEMS 5

typedef struct Node Node; // Para poder utilizar o tipo "Node" dentro do próprio Node
typedef struct List List; // Para padronizar mesmo

// NODE NODE NODE NODE NODE NODE
// NODE NODE NODE NODE NODE NODE
// NODE NODE NODE NODE NODE NODE
struct Node
{
    int content;
    Node *next;
};

/*
 * Cria um novo nó
 */
Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->content = data;
    return newNode;
}

/*
 * Cria um novo nó baseado no input do usuário
 */
Node *createNodeFromUserInput()
{
    int number = 0;
    printf("Digite o numero a ser inserido: ");
    setbuf(stdin, 0);
    scanf("%d", &number);
    return createNode(number);
}

// LIST LIST LIST LIST LIST LIST
// LIST LIST LIST LIST LIST LIST
// LIST LIST LIST LIST LIST LIST
struct List
{
    Node *first;
    Node *last;

    int size;
};

/*
 * Cria uma lista vazia
 */
List *createEmptyList()
{
    return malloc(sizeof(List));
}

/*
 * Encontra o penúltimo elemento da lista
 */
Node *findPenultimate(List *list)
{
    Node *walker = list->first;
    while (walker != NULL)
    {
        if (walker->next == list->last)
        {
            return walker;
        }

        walker = walker->next;
    }

    return walker;
}

/*
 * Verifica se um elemento é o primeiro da lista
 */
int isFirstElement(List *list, Node *node)
{
    return (list->first == node) || (list->size == 0);
}

/*
 * Verifica se um elemento é o último da lista
 */
int isLastElement(List *list, Node *node)
{
    return list->last == node;
}

/*
 * Verifica se a lista já alcançou o máximo de elementos
 */
int listIsFull(List *list)
{
    return list->size == MAX_LIST_ITEMS;
}

/*
 * Verifica se a lista está vazia
 */
int listIsEmpty(List *list)
{
    return list->size == 0;
}

/*
 * Remove o primeiro nó da lista
 */
int popFirst(List *list)
{
    int poppedContent = list->first->content;
    Node *toBePopped = list->first;

    list->first = list->first->next;
    list->size--;
    free(toBePopped);

    return poppedContent;
}

/*
 * Remove o último nó da lista
 */
int popLast(List *list)
{
    int poppedContent = list->last->content;
    Node *toBePopped = list->last, *penultimateNode = findPenultimate(list);

    penultimateNode->next = NULL;
    list->last = penultimateNode;
    list->size--;
    free(toBePopped);
    return poppedContent;
}

/*
 * Remove um nó baseado no seu conteúdo
 */
int popBasedOnContent(List *list, int contentToPop)
{
    int poppedContent = 0, found = 0;
    Node *walker = list->first, *follower = NULL;
    while (walker != NULL && found == 0)
    {
        if (walker->content == contentToPop)
        {
            found = 1;
            if (isFirstElement(list, walker))
            {
                poppedContent = popFirst(list);
            }
            else if (isLastElement(list, walker))
            {
                poppedContent = popLast(list);
            }
            else
            {
                follower->next = walker->next;
                poppedContent = walker->content;
                list->size--;
                free(walker);
            }
        }
        else
        {
            follower = walker;
            walker = walker->next;
        }
    }

    if (found == 1)
    {
        return poppedContent;
    }
    else
    {
        return -1;
    }
}

/*
 * Remove todos os elementos da lista e depois remove a lista
 */
void clearList(List *list)
{
    while (list->first != NULL)
    {
        popFirst(list);
    }
    list->last = NULL;
}

/*
 * Insere um nó no final da lista
 */
void insertNodeInLastPosition(List *list, Node *newNode)
{
    if (listIsEmpty(list))
    {
        list->first = newNode;
        list->last = newNode;
    }
    else
    {
        list->last->next = newNode;
        list->last = list->last->next;
    }
    list->size++;
}

/*
 * Insere um nó no começo da lista
 */
void insertNodeInFirstPosition(List *list, Node *newNode)
{
    if (listIsEmpty(list))
    {
        list->first = newNode;
        list->last = newNode;
    }
    else
    {
        newNode->next = list->first;
        list->first = newNode;
    }
    list->size++;
}

/*
 * Insere um nó na lista baseado em seu valor, de forma ordenada
 */
void insertNodeInSortedPosition(List *list, Node *newNode)
{
    int inserted = 0;
    Node *walker = list->first, *follower = list->first;
    if (listIsEmpty(list))
    {
        insertNodeInFirstPosition(list, newNode);
    }
    else
    {
        while (walker != NULL && inserted == 0)
        {
            if (newNode->content <= walker->content)
            {
                if (isFirstElement(list, walker))
                {
                    insertNodeInFirstPosition(list, newNode);
                    inserted = 1;
                }
                else
                {
                    inserted = 1;
                    newNode->next = follower->next;
                    follower->next = newNode;
                    list->size++;
                }
            }
            else
            {
                follower = walker;
                walker = walker->next;
            }
        }

        if (inserted == 0)
        {
            insertNodeInLastPosition(list, newNode);
        }
    }
}

/*
 * Cria a lista com os 5 elementos pedidos pela professora
 */
void fillList(List *list)
{
    int i = 0;
    Node *newNode = NULL;
    while (i < MAX_LIST_ITEMS)
    {
        newNode = createNode(i);
        insertNodeInLastPosition(list, newNode);
        i++;
    }
}

/*
 * Retorna o index de uma informação na lista
 */
int getContentIndex(List *list, int content)
{
    int index = 0;
    Node *walker = list->first;

    while (walker != NULL)
    {
        if (walker->content == content)
        {
            return index;
        }
        else
        {
            walker = walker->next;
            index++;
        }
    }

    return -1;
}

/*
 * Retorna a informação em um index
 */
int getIndexContent(List *list, int index)
{
    if (index >= MAX_LIST_ITEMS || index <= 0)
    {
        return -1;
    }

    Node *walker = list->first;
    int i = 0;
    for (i = 0; i <= index; i++)
    {
        if (i == index)
        {
            return walker->content;
        }
        else
        {
            walker = walker->next;
        }
    }
}

/*
 * Imprime a lista na tela
 */
int printsList(List *list)
{
    Node *walker = list->first;
    if (listIsEmpty(list))
    {
        printf("Lista vazia!!\n");
    }
    else
    {
        while (walker != NULL)
        {
            printf("%d", walker->content);
            if (walker->next != NULL)
            {
                printf(" -> ");
            }
            walker = walker->next;
        }
        printf("\n");
    }
}

/*
 * Mostra o menu
 */
void printMenu()
{
    printf("------------------MENU------------------\n");
    printf("   1) Criar a lista estatica\n");
    printf("   2) Liberar lista estatica\n");
    printf("   3) Inserir no inicio\n");
    printf("   4) Inserir no fim\n");
    printf("   5) Inserir no meio (ordenado)\n");
    printf("   6) Remover do inicio\n");
    printf("   7) Remover do fim\n");
    printf("   8) Remover do meio\n");
    printf("   9) Consultar pelo conteudo\n");
    printf("   10) Consultar pela posicao\n");
    printf("   11) Imprimir Lista Estatica\n");
    printf("   12) Sair\n");
}

/*
 * Entrada
 */
void main()
{
    List *list = createEmptyList();
    int option = 0, number = 0;

    // printMenu();
    setbuf(stdin, NULL);
    scanf("%d", &option);
    while (option != 12)
    {
        printf("\nOpcao %d\n", option);
        switch (option)
        {
        case 1:
            fillList(list);
            break;
        case 2:
            clearList(list);
            break;
        case 3:
            insertNodeInFirstPosition(list, createNodeFromUserInput());
            break;
        case 4:
            insertNodeInLastPosition(list, createNodeFromUserInput());
            break;
        case 5:
            insertNodeInSortedPosition(list, createNodeFromUserInput());
            break;
        case 6:
            printf("Elemento removido: %d\n", popFirst(list));
            break;
        case 7:
            printf("Elemento removido: %d\n", popLast(list));
            break;
        case 8:
            printf("Insira a informação a ser removida: ");
            setbuf(stdin, 0);
            scanf("%d", &number);
            printf("Elemento removido: %d\n", popBasedOnContent(list, number));
            break;
        case 9:
            printf("Insira a informacao a ser procurada:");
            setbuf(stdin, 0);
            scanf("%d", &number);
            printf("Informacao estava no endereco %d\n", getContentIndex(list, number));
            break;
        case 10:
            printf("Insira a posicao a ser procurada: ");
            setbuf(stdin, 0);
            scanf("%d", &number);
            printf("O endereco %d continha %d\n", number, getIndexContent(list, number));
            break;
        case 11:
            printsList(list);
            break;
        case 12:
            printf("Tchau!!!\n");
        default:
            printf("Opcao nao encontrada\n");
            break;
        }

        // printMenu();
        setbuf(stdin, 0);
        scanf("%d", &option);
    }
}