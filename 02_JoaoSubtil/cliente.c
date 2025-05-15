#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{

    int nlinhas, ncolunas, op;
    Matriz *mat;
    while (1)
    {
        printf("\nMenu\n");
        printf("1 - Inicializar uma matriz\n");
        printf("2 - Inserir valores da matriz\n");
        printf("3 - Imprima matriz\n");
        printf("4 - Calcula transposta\n");
        printf("5 - Calcula produto\n");
        printf("6 - Encerrar programa\n\n");

        scanf("%d\n", &op);

        if (op == 1)
        {
            printf("Insira a quantidade de linhas e colunas:\n");
            scanf("%d %d\n", &nlinhas, &ncolunas);
            mat = inicializaMatriz(nlinhas, ncolunas);
        }

        else if (op == 2)
        {
            int elem;
            for (int i = 0; i < recuperaNLinhas(mat); i++)
            {
                for (int j = 0; j < recuperaNColunas(mat); j++)
                {

                    scanf("%d ", &elem);
                    modificaElemento(mat, i, j, elem);
                }
            }
        }

        else if (op == 3)
        {
            imprimeMatriz(mat);
        }

        else if (op == 4)
        {
            Matriz *transp = transposta(mat);
            imprimeMatriz(transp);
            destroiMatriz(transp);
        }

        else if (op == 5)
        {
            printf("Insira a quantidade de linhas e colunas da segunda matriz:\n");
            int nlinhas2, ncolunas2;
            Matriz *mat2;
            scanf("%d %d\n", &nlinhas2, &ncolunas2);
            if (ncolunas == nlinhas2)
            {
                mat2 = inicializaMatriz(nlinhas2, ncolunas2);
                int elem;
                for (int i = 0; i < recuperaNLinhas(mat2); i++)
                {
                    for (int j = 0; j < recuperaNColunas(mat2); j++)
                    {

                        scanf("%d ", &elem);
                        modificaElemento(mat2, i, j, elem);
                    }
                }
                Matriz *prod = multiplicacao(mat, mat2);
                imprimeMatriz(prod);

                destroiMatriz(prod);
                destroiMatriz(mat2);
            }
            else
                printf("Valor invalido!\n");
        }

        else if (op == 6)
        {
            break;
        }

        else
            printf("Valor invalido! %d\n", op);
    }
    destroiMatriz(mat);
    return 0;
}
