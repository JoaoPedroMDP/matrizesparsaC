#include <stdio.h>
#include "matrixBag.h"

#define EXIT -1
#define CREATE_MATRIX 1
#define SUM_MATRIXES 2
#define SUBTRACT_MATRIXES 3
#define MULTIPLY_MATRIXES 4
#define TRANSPOSE_MATRIX 5
#define PRINT_MATRIX 6
#define SHOW_MAIN_DIAGONAL 7
#define REMOVE_MATRIX 8
#define SHOW_ALL_MATRIXES 9

/*
 * Mostra o menu
 */
void printsMenu()
{
    printf("\n------------------MENU------------------\n");
    printf("   %d) Sair\n", EXIT);
    printf("   %d) Inserir nova matriz\n", CREATE_MATRIX);
    printf("   %d) Somar matrizes\n", SUM_MATRIXES);
    printf("   %d) Subtrair matrizes\n", SUBTRACT_MATRIXES);
    printf("   %d) Multiplicar matrizes\n", MULTIPLY_MATRIXES);
    printf("   %d) Transpor matriz\n", TRANSPOSE_MATRIX);
    printf("   %d) Ver matriz\n", PRINT_MATRIX);
    printf("   %d) Diagonal principal\n", SHOW_MAIN_DIAGONAL);
    printf("   %d) Remover Matriz\n", REMOVE_MATRIX);
    printf("   %d) Mostrar todas as matrizes\n", SHOW_ALL_MATRIXES);
    printf("Escolha uma opção: ");
}

int main()
{
    int option = 0;
    Bag *bag = createBag();
    zeroNode = createNode(0, 0, 0);
    Matrix *first = NULL;
    Matrix *second = NULL;

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
            case SUM_MATRIXES:;
                first = chooseMatrix(bag);
                second = chooseMatrix(bag);
                appendMatrix(
                    bag,
                    sumMatrixes(first, second)
                );
                break;
            case SUBTRACT_MATRIXES:
                first = chooseMatrix(bag);
                second = chooseMatrix(bag);
                appendMatrix(
                    bag,
                    subtractMatrixes(first, second)
                );
                break;
            case MULTIPLY_MATRIXES:
                first = chooseMatrix(bag);
                second = chooseMatrix(bag);
                multiplyMatrixes(first, second);
                break;
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
            case REMOVE_MATRIX:;
                removeMatrixFromBag(
                    bag,
                    chooseMatrix(bag)
                );
                break;
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