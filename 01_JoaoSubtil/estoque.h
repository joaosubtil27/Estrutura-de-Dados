#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "item.h"

typedef struct Estoque Estoque;

Estoque *CriaEstoque();// cria um estoque e inicializa suas variaveis

void adicionaItemEstoque(Estoque *e, Item *i);// adiciona um item em um vetor no estoque

float calculaValorEstoque(Estoque *e); // calcula o valor do estoque

void imprimeEstoque(Estoque *e); // imprime o valor de estoque e as informacoes dos itens cadastrados

void LiberaEstoque(Estoque *e); // libera a menoria de um estoque

#endif