#ifndef FILIAL_H
#define FILIAL_H

#include "estoque.h"

typedef struct Filial Filial;

Filial *CriaFilial();

char *getNomeFilial(Filial *f);

Estoque *getEstoqueFilial(Filial *f);

float calculaValorFilial(Filial *f);

void AdicionaItemFilial(Filial *f, Item *i);

void imprimeFilial(Filial *f);

void liberaFilial(Filial *f);

#endif