#ifndef ITEM_H
#define ITEM_H

#include "produto.h"

typedef struct Item Item;

Item *cadastraItem(Produto *p);

float calculaValorItem(Item *i);

void imprimeItem(Item *i);

void liberaItem(Item *i);

#endif