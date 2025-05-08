#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "produto.h"
/*
typedef struct
{
    char *nome;
    float preco;

} Produto;*/

typedef struct
{
    Produto *prod;
    int qnt;

} item_estoque;

typedef struct
{
    float valor;
    item_estoque **item;

} estoque;

typedef struct
{
    char *nome;
    estoque **est;

} Filial;

typedef struct
{
    char *nome;
    Filial **filiais;
    float est_total;
    int qnt_filiais;

} Supermercado;

char *leLinha();

Supermercado *buscaSupermercado(char *nome);
Filial *buscaFilial(Supermercado *s, char *nome);
//Produto *buscaProduto(char *nome);


void adicionaFilial(Supermercado *p);

void adicionaProdutoFilial(Filial *f);

float estoqueFilial(Filial *f);
float estoqueSupermercado(Supermercado *s);

void imprimeFilial(Filial f);

int main()
{
    int op;

    Produto **prod = (Produto**)malloc(sizeof(Produto*));
    int qnt_prod = 0;

    Supermercado **sup = (Supermercado**)malloc(sizeof(Supermercado*));
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

        scanf("%d\n", &op);

        if (op == 1)
        {
            qnt_prod++;
            prod = (Produto**)realloc(prod, qnt_prod*sizeof(Produto*));

            prod[qnt_prod-1] = leProduto();
        }
        else if (op == 2)
        {
            qnt_sup++;

            sup = (Supermercado*)realloc(sup, qnt_sup*sizeof(Supermercado));

            printf("Insira o nome:\n");
            sup[qnt_sup-1].nome = leLinha();

        }
        else if (op == 3)
        {

            printf("Insira o nome do Supermercado:\n");
            char *nome = leLinha();

            adicionaFilial(buscaSupermercado(nome));

        }
        else if (op == 4)
        {
            printf("Insira o nome do Supermercado:\n");
            char *nome_sup = leLinha();

            printf("Insira o nome da Filial:\n");
            char *nome_fil = leLinha();


        }
        else if (op == 5)
        {
        }
        else if (op == 6)
        {
        }
        else if (op == 7)
        {
        }
        else if (op == 8)
        {
            break;
        }
        else
        {
            printf("Valor invalido!\n");
        }
    }
}

char *leLinha()
{
    char temp[100];
    scanf("%99[^\n]", temp);
    char *str = strdup(temp);
    return str;
}
