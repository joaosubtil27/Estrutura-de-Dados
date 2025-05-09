#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "supermercado.h"

char *leLinha()
{
    char temp[100];
    scanf(" %99[^\n]", temp);
    return strdup(temp);
}

Supermercado *buscaSupermercado(Supermercado **s, char *nome, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (strcmp(getNomeSupermercado(s[i]), nome) == 0)
            return s[i];
    }
    return NULL;
}

int main()
{
    int op;

    Produto **prod = (Produto **)malloc(sizeof(Produto *));
    int qnt_prod = 0;

    Supermercado **sup = (Supermercado **)malloc(sizeof(Supermercado *));
    int qnt_sup = 0;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Cadastrar supermercado\n");
        printf("3 - Cadastrar filial\n");
        printf("4 - Cadastrar Produto na filial\n");
        printf("5 - Estoque filial\n");
        printf("6 - Estoque Supermercado\n");
        printf("7 - Relatorio final\n");
        printf("8 - Encerrar programa\n");

        scanf("%d", &op);

        if (op == 1)
        {
            qnt_prod++;
            prod = (Produto **)realloc(prod, qnt_prod * sizeof(Produto *));

            prod[qnt_prod - 1] = criaProduto();
        }
        else if (op == 2)
        {
            qnt_sup++;

            sup = (Supermercado **)realloc(sup, qnt_sup * sizeof(Supermercado *));
            sup[qnt_sup - 1] = CriaSupermercado();
        }
        else if (op == 3)
        {

            printf("\nInsira o nome do Supermercado:\n");
            char *nome_sup = leLinha();
            adicionaFilialSupermercado(buscaSupermercado(sup, nome_sup, qnt_sup));
        }
        else if (op == 4)
        {
            printf("\nInsira o nome do Supermercado:\n");
            char *nome_sup = leLinha();

            printf("\nInsira o nome da Filial:\n");
            char *nome_fil = leLinha();

            printf("\nInsira o nome do Produto:\n");
            char *nome_prod = leLinha();
            Item *i = cadastraItem(buscaProduto(prod, nome_prod, qnt_prod));
            Filial *f = buscaFilial(buscaSupermercado(sup, nome_sup, qnt_sup), nome_fil);
            AdicionaItemFilial(f, i);
        }
        else if (op == 5)
        {
            printf("\nInsira o nome do Supermercado:\n");
            char *nome_sup = leLinha();

            printf("\nInsira o nome da Filial:\n");
            char *nome_fil = leLinha();

            printf("\nValor da filial: %.2f\n", calculaValorFilial(buscaFilial(buscaSupermercado(sup, nome_sup, qnt_sup), nome_fil)));
        }
        else if (op == 6)
        {
            printf("\nInsira o nome do Supermercado:\n");
            char *nome_sup = leLinha();

            Supermercado *s = buscaSupermercado(sup, nome_sup, qnt_sup);
            calculaValorSupermercado(s);

            printf("\nValor do supermercado: %.2f\n", getValorSupermercado(s));
        }
        else if (op == 7)
        {
            printf("\n--------------------------------\n");
            for (int i = 0; i < qnt_sup; i++)
            {
                imprimeSupermercado(sup[i]);
                printf("--------------------------------\n");
            }
        }
        else if (op == 8)
        {
            break;
        }
        else
        {
            printf("\nValor invalido!\n");
        }
    }
    for(int i=0; i<qnt_sup; i++){
        liberaSupermercado(sup[i]);
    }
    free(sup);
}
