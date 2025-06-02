#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

char *leLinha()
{
    char temp[100];
    scanf(" %99[^\n]", temp);
    return strdup(temp);
}

int main()
{
    int op;
    Produto **prod = (Produto **)malloc(sizeof(Produto *)); // criacao de um vetor de ponteiros para produtos pré-castrados
    int qnt_prod = 0;
    Lista *l = criaLista();
    while (1)
    {
        printf("\nMenu:\n");
        printf("1 - Cadastra produto\n");
        printf("2 - Insere produto na Lista\n");
        printf("3 - Retira produto da Lista\n");
        printf("4 - Imprime Lista\n");
        printf("5 - Fim do programa\n\n");

        scanf("%d\n", &op);
        if (op == 1)
        {
            qnt_prod++;
            prod = (Produto **)realloc(prod, qnt_prod * sizeof(Produto *));

            prod[qnt_prod - 1] = criaProduto();
            imprimeProduto(prod[qnt_prod - 1]);
        }
        else if (op == 2)
        {
            printf("\nInsira o nome do Produto:\n");
            char *nome_prod = leLinha();
            Produto *add = NULL;
            add = buscaProduto(prod, nome_prod, qnt_prod);
            if (add != NULL)
            {
                l = InsereProdutoLista(l, add);
            }
            else
                printf("Produto nao encontrado\n");

            free(nome_prod);
        }
        else if (op == 3)
        {
            printf("\nInsira o nome do Produto:\n");
            char *nome_prod = leLinha();
            l = ApagaProdutoLista(l, nome_prod);
            free(nome_prod);
        }
        else if (op == 4)
        {
            ImprimeLista(l);
        }
        else if (op == 5)
        {
            break;
        }
        else
        {
            printf("Valor invalido!\n");
        }
    }
    liberaLista(l);
    for (int i = 0; i < qnt_prod; i++)
    {
        liberaProduto(prod[i]);
    }
    free(prod);
    return 0;
}