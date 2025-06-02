#ifndef Lista_H
#define LSITA_H

#include "produto.h"
typedef struct Lista Lista;

Lista *criaLista();

Lista *InsereProdutoLista(Lista *l, Produto *p);

Lista *ApagaProdutoLista(Lista *p, char *nome);

void ImprimeLista(Lista *l);

void liberaLista(Lista *p);

#endif