#include <stdio.h>
#include <stdlib.h>

#include "item.h"
struct Item
{
    Produto *prod;
    int qnt;
};

Item *cadastraItem(Produto *p) // cria um item a partir de um produto especifico
{
    Item *i = (Item *)malloc(sizeof(Item));
    i->prod = p;

    printf("\nInsira a quantidade de produtos:\n");
    scanf("%d", &i->qnt);

    return i;
}

float calculaValorItem(Item *i) // calcula o valor de um item
{

    return i->qnt * getPrecoProduto(i->prod);
}

void imprimeItem(Item *i) // imprime as informacoes de um item
{
    printf("               Item: %s, valor unitário: %.2f, quantidade: %d\n", getNomeProduto(i->prod), getPrecoProduto(i->prod), i->qnt);
}

void liberaItem(Item *i) // libera a memoria alocada por um item
{
    free(i);
}
