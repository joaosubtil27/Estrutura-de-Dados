#include <stdio.h>
#include <stdlib.h>

#include "item.h"
struct Item
{
    Produto *prod;
    int qnt;
};

Item *cadastraItem(Produto *p)
{
    Item *i = (Item *)malloc(sizeof(Item));
    i->prod = p;

    printf("Insira a quantidade de produtos:\n");
    scanf("%d\n", &i->qnt);

    return i;
}

float calculaValorItem(Item *i)
{

    return i->qnt * getPrecoProduto(i->prod);
}

void imprimeItem(Item *i){
    printf("                 Item: %s, valor unitário: %.2f, quantidade: %d,", getNomeProduto(i->prod), getPrecoProduto(i->prod), i->qnt);
}

void liberaItem(Item *i){
    free(i);
}
