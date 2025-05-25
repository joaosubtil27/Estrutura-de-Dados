#ifndef Lista_H
#define LSITA_H

#include "produto.h"
typedef struct Celula Celula;
typedef struct Lista Lista;

Lista *criaLista();

void InsereProdutoLista(Lista *l, Produto *p);

Produto *ApagaProdutoLista(Lista *p, char *nome);

void ImprimeLista(Lista *l);

void liberaLista(Lista *p);

#endif