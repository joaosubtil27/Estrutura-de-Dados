#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "produto.h"

struct Produto
{
    char *nome;
    float preco;
};

char *leLinhaProduto()
{
    char temp[100];
    scanf(" %99[^\n]", temp);
    return strdup(temp);
}

Produto *criaProduto() // cria um produto e le os valores das variaveis relacionadas na entrada padrao
{
    Produto *p = (Produto *)malloc(sizeof(Produto));

    printf("\nInsira o nome do produto:\n");
    p->nome = leLinhaProduto();

    printf("\nInsira o preco do produto:\n");
    scanf("%f", &p->preco);

    return p;
}

Produto *buscaProduto(Produto **p, char *nome, int tam) // busca um produto num vetor
{
    for (int i = 0; i < tam; i++)
    {
        if (strcmp(p[i]->nome, nome) == 0)
            return p[i];
    }
    return NULL;
}

char *getNomeProduto(Produto *p) // retorna o nome do produto
{
    return p->nome;
}

float getPrecoProduto(Produto *p) // retorna o preco do produto
{
    return p->preco;
}

void liberaProduto(Produto *p) // libera a memoria alocada por um produto
{
    free(p);
}