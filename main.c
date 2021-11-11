#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/*
 * Mostra o menu
 */
void printsMenu()
{
    printf("------------------MENU------------------\n");
    printf("   1) Inserir nova matriz\n");
    printf("   2) Somar matrizes\n");
    printf("   3) Subtrair matrizes\n");
    printf("   4) Multiplicar matrizes\n");
    printf("   5) Gerar matriz transposta\n");
    printf("   6) Mostrar matriz\n");
    printf("   7) Mostrar diagonal principal\n");
    printf("   8) Remover Matriz\n");
    printf("   9) Consultar pelo conteudo\n");
    printf("   10) Sair\n");
    printf("Escolha uma opção: ");
}

int main()
{
    int option = 0;
    MatrixBag *bag = createBag();
    Matrix *toOperate = NULL;
    printsMenu();
    setbuf(stdin, 0);
    scanf("%d", &option);
    while (option != 11)
    {
        switch (option)
        {
        case 1:
            toOperate = createMatrixOption();
            insertMatrixOnBag(toOperate, bag);
            break;
        // case 2:
        //     sumMatrixesOption(bag);
        //     break;
        // case 3:
        //     subtractMatrixesOption(bag);
        //     break;
        // case 4:
        //     multiplyMatrixesOption(bag);
        //     break;
        case 5:
            toOperate = chooseMatrix(bag);
            transposeMatrix(toOperate);
            break;
        case 6:
            toOperate = chooseMatrix(bag);
            printMatrix(toOperate);
            break;
        case 7:
            toOperate = chooseMatrix(bag);
            showMainDiagonalOption(toOperate);
            break;
        case 8:
            toOperate = chooseMatrix(bag);
            removeMatrix(bag, toOperate);
            break;
        // case 9:
        //     searchByContent(bag);
        //     break;
        case 10:
            showAllMatrixes(bag);
            break;
        }
        printsMenu();
        setbuf(stdin, 0);
        scanf("%d", &option);
    }
    return 0;
}