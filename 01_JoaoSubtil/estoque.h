#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "item.h"

typedef struct Estoque Estoque;

Estoque *CriaEstoque();

void adicionaItemEstoque(Estoque *e, Item *i);

float calculaValorEstoque(Estoque *e);

void imprimeEstoque(Estoque *e);

void LiberaEstoque(Estoque *e);

#endif