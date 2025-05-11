#ifndef ITEM_H
#define ITEM_H

#include "produto.h"

typedef struct Item Item;

Item *cadastraItem(Produto *p); // cria um item a partir de um produto especifico

float calculaValorItem(Item *i); // calcula o valor de um item

void imprimeItem(Item *i); // imprime as informacoes de um item

void liberaItem(Item *i); // libera a memoria alocada por um item

#endif