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

int main()
{
    int op;

    Produto **prod = (Produto **)malloc(sizeof(Produto *)); // criacao de um vetor de ponteiros para produtos pré-castrados
    int qnt_prod = 0;

    Supermercado **sup = (Supermercado **)malloc(sizeof(Supermercado *)); // criacao de um vetor de ponteiros para supermercados
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

        if (op == 1) // pré-cadastramento de um produto
        {
            qnt_prod++;
            prod = (Produto **)realloc(prod, qnt_prod * sizeof(Produto *));

            prod[qnt_prod - 1] = criaProduto();
        }
        else if (op == 2) // cadastramento de um supermercado no sistema
        {
            qnt_sup++;

            sup = (Supermercado **)realloc(sup, qnt_sup * sizeof(Supermercado *));
            sup[qnt_sup - 1] = CriaSupermercado();
        }
        else if (op == 3) // adiciona filial a um supermercado
        {

            printf("\nInsira o nome do Supermercado:\n");
            char *nome_sup = leLinha();
            adicionaFilialSupermercado(buscaSupermercado(sup, nome_sup, qnt_sup));
        }
        else if (op == 4) // regista um item pré-cadastrado no sistema de uma filial do supermercado
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
        else if (op == 5) // Calcula valor da filial
        {
            printf("\nInsira o nome do Supermercado:\n");
            char *nome_sup = leLinha();

            printf("\nInsira o nome da Filial:\n");
            char *nome_fil = leLinha();

            printf("\nValor da filial: %.2f\n", calculaValorFilial(buscaFilial(buscaSupermercado(sup, nome_sup, qnt_sup), nome_fil)));
        }
        else if (op == 6) // Calcula o valor do supermercado
        {
            printf("\nInsira o nome do Supermercado:\n");
            char *nome_sup = leLinha();

            Supermercado *s = buscaSupermercado(sup, nome_sup, qnt_sup);
            calculaValorSupermercado(s);

            printf("\nValor do supermercado: %.2f\n", getValorSupermercado(s));
        }
        else if (op == 7) // Imprime relatorio geral dos supermercados
        {
            printf("\n--------------------------------\n");
            for (int i = 0; i < qnt_sup; i++)
            {
                imprimeSupermercado(sup[i]);
                printf("--------------------------------\n");
            }
        }
        else if (op == 8) // fim do programa
        {
            break;
        }
        else // condicao para valores invalidos (x<1 && x>8)
        {
            printf("\nValor invalido!\n");
        }
    }
    for (int i = 0; i < qnt_sup; i++)
    { // liberacao da memoria dinamica alocada do supermercado
        liberaSupermercado(sup[i]);
    }
    free(sup);

    for (int i = 0; i < qnt_prod; i++)
    { // liberacao da memoria dinamica alocada dos produtos pré-cadastrados
        liberaProduto(prod[i]);
    }
    free(prod);
}
