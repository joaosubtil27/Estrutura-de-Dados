#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto Produto;

Produto *criaProduto();

Produto *buscaProduto(Produto **p, char *nome, int tam);

char *getNomeProduto (Produto *p);

float getPrecoProduto (Produto *p);

void liberaProduto (Produto *p);

#endif