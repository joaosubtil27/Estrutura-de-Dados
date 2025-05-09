#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include "filial.h"

typedef struct Supermercado Supermercado;

Supermercado *CriaSupermercado();

void adicionaFilialSupermercado(Supermercado *s);

Filial *buscaFilial(Supermercado *s, char* nome);

char *getNomeSupermercado(Supermercado *s);

float getValorSupermercado(Supermercado *s);

void calculaValorSupermercado(Supermercado *s);

void imprimeSupermercado(Supermercado *s);

void liberaSupermercado(Supermercado *s);

#endif