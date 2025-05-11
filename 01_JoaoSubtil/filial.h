#ifndef FILIAL_H
#define FILIAL_H

#include "estoque.h"

typedef struct Filial Filial;

Filial *CriaFilial(); // cria um filial

char *getNomeFilial(Filial *f); // retorna o nome da filial

Estoque *getEstoqueFilial(Filial *f); // retorna o estoque da filial

float calculaValorFilial(Filial *f); // calcula valor da filial

void AdicionaItemFilial(Filial *f, Item *i); // adiciona um produto ao estoque de uma filial

void imprimeFilial(Filial *f); // imprime as informacoes da filial e dos itens no estoque

void liberaFilial(Filial *f); // libera a memoria de uma filial

#endif