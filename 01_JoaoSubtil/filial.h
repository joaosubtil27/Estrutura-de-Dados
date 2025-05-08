#ifndef FILIAL_H
#define FILIAL_H

#include "estoque.h"

typedef struct Filial Filial;

Filial *CriaFilial();

float getValorFilial(Filial *f);

void imprimeFilial(Filial *f);

void liberaFilial(Filial *f);

#endif