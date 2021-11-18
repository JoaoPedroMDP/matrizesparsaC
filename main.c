#include <stdio.h>
#include <stdlib.h>
#include "matrixBag.h"

#define EXIT -1
#define CREATE_MATRIX 1
#define TRANSPOSE_MATRIX 5
#define SOMAR_MATRIZES 2
// #define
// #define
#define PRINT_MATRIX 6
#define SHOW_MAIN_DIAGONAL 7
#define REMOVE_MATRIX 8
#define SHOW_ALL_MATRIXES 10

/*
 * Mostra o menu
 */
void printsMenu()
{
    printf("\n------------------MENU------------------\n");
    printf("   %d) Sair\n", EXIT);
    printf("   %d) Inserir nova matriz\n", CREATE_MATRIX);
    printf("   %d) Somar matrizes\n", SOMAR_MATRIZES);
    printf("   3) Subtrair matrizes\n");
    printf("   4) Multiplicar matrizes\n");
    printf("   %d) Transpor matriz\n", TRANSPOSE_MATRIX);
    printf("   %d) Ver matriz\n", PRINT_MATRIX);
    printf("   %d) Diagonal principal\n", SHOW_MAIN_DIAGONAL);
    printf("   %d) Remover Matriz\n", REMOVE_MATRIX);
    printf("   9) Consultar pelo conteudo\n");
    printf("   %d) Mostrar todas as matrizes\n", SHOW_ALL_MATRIXES);
    printf("   %d) Sair\n", EXIT);
    printf("Escolha uma opção: ");
}

int main()
{
    int option = 0;
    Bag *bag = createBag();
    zeroNode = createNode(0, 0, 0);

    printsMenu();
    setbuf(stdin, 0);
    scanf("%d", &option);
    while (option != -1)
    {
        printf("\n<<<<<%d>>>>>\n", option);
        switch (option)
        {
            case EXIT:
                printf("Ateh!");
                break;
            case CREATE_MATRIX:
                appendMatrix(
                    bag,
                    createMatrix());
                break;
             case 2:;
                 Matrix *first = chooseMatrix(bag);
                 Matrix *second = chooseMatrix(bag);
                 sumMatrixes(first, second);
                 break;
            // case 3:
            //     subtractMatrixesOption(bag);
            //     break;
            // case 4:
            //     multiplyMatrixesOption(bag);
            //     break;
            case TRANSPOSE_MATRIX:;
                Matrix *toTranspose = chooseMatrix(bag);
                replaceMatrixes(
                    bag,
                    transposeMatrix(toTranspose),
                    toTranspose
                );
                break;
            case PRINT_MATRIX:
                printMatrix(chooseMatrix(bag));
                break;
            case SHOW_MAIN_DIAGONAL:
                showMainDiagonal(chooseMatrix(bag));
                break;
            case REMOVE_MATRIX:
                removeMatrixFromBag(
                    bag,
                    chooseMatrix(bag)
                );
                break;
            case 9:
            //     searchByContent(bag);
            //     break;
            case SHOW_ALL_MATRIXES:
                showAllMatrixes(bag);
                break;
            default:
                printf("Opcao %d nao encontrada", option);
                break;
        }
        printsMenu();
        setbuf(stdin, 0);
        scanf("%d", &option);
    }
    return 0;
}