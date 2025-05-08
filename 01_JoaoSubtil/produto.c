#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "produto.h"

struct Produto
{
    char *nome;
    float preco;
};

char *leLinha()
{
    char temp[100];
    scanf("%99[^\n]", temp);
    char *str = strdup(temp);
    return str;
}

Produto *criaProduto()
{
    Produto *p = (Produto *)malloc(sizeof(Produto));

    printf("\nInsira o nome do produto:\n");
    p->nome = leLinha();

    printf("\nInsira o preco do produto:\n");
    scanf("%f\n", &p->preco);

    return p;
}

Produto *buscaProduto(Produto **p, char *nome, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (strcmp(p[i]->nome, nome) == 0)
            return p[i];
    }
}

char *getNomeProduto(Produto *p)
{
    return p->nome;
}

float getPrecoProduto(Produto *p)
{
    return p->preco;
}

void liberaProduto (Produto *p){
    free(p);
}