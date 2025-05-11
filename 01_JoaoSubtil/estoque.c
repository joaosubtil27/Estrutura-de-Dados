#include <stdlib.h>
#include <stdio.h>

#include "estoque.h"

struct Estoque
{
    float valor;
    Item **itens;
    int qnt_itens;
};

Estoque *CriaEstoque() // cria um estoque e inicializa suas variaveis
{
    Estoque *e = (Estoque *)malloc(sizeof(Estoque));

    e->itens = (Item **)malloc(sizeof(Item *));
    e->valor = 0;
    e->qnt_itens = 0;
    return e;
}

void adicionaItemEstoque(Estoque *e, Item *i) // adiciona um item em um vetor no estoque
{
    e->qnt_itens++;
    e->itens = (Item **)realloc(e->itens, e->qnt_itens * sizeof(Item *));
    e->itens[e->qnt_itens - 1] = i;
}

float calculaValorEstoque(Estoque *e) // calcula o valor do estoque
{
    e->valor = 0;
    for (int i = 0; i < e->qnt_itens; i++)
    {
        e->valor += calculaValorItem(e->itens[i]);
    }
    return e->valor;
}

void imprimeEstoque(Estoque *e) // imprime o valor de estoque e as informacoes dos itens cadastrados
{
    printf("      Estoque: %.2f\n", calculaValorEstoque(e));
    for (int i = 0; i < e->qnt_itens; i++)
    {
        imprimeItem(e->itens[i]);
    }
}

void LiberaEstoque(Estoque *e) // libera a menoria de um estoque
{
    for (int i = 0; i < e->qnt_itens; i++)
    {
        liberaItem(e->itens[i]);
    }
    free(e->itens);
    free(e);
}
