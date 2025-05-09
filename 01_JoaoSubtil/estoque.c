#include <stdlib.h>
#include <stdio.h>

#include "estoque.h"

struct Estoque
{
    float valor;
    Item **itens;
    int qnt_itens;
};

Estoque *CriaEstoque()
{
    Estoque *e = (Estoque *)malloc(sizeof(Estoque));

    e->itens = (Item **)malloc(sizeof(Item *));
    e->valor = 0;
    e->qnt_itens = 0;
    return e;
}

void adicionaItemEstoque(Estoque *e, Item *i)
{
    e->qnt_itens++;
    e->itens = (Item **)realloc(e->itens, e->qnt_itens * sizeof(Item *));
    e->itens[e->qnt_itens - 1] = i;
}

float calculaValorEstoque(Estoque *e)
{
    e->valor = 0;
    for (int i = 0; i < e->qnt_itens; i++)
    {
        e->valor += calculaValorItem(e->itens[i]);
    }
    return e->valor;
}

void imprimeEstoque(Estoque *e)
{
    printf("      Estoque: %.2f\n", calculaValorEstoque(e));
    for (int i = 0; i < e->qnt_itens; i++)
    {
        imprimeItem(e->itens[i]);
    }
}

void LiberaEstoque(Estoque *e)
{
    for (int i = 0; i < e->qnt_itens; i++)
    {
        liberaItem(e->itens[i]);
    }
    free(e->itens);
    free(e);
}
