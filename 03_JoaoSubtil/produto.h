#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto Produto;

Produto *criaProduto(); // cria um produto e le os valores das variaveis relacionadas na entrada padrao

Produto *buscaProduto(Produto **p, char *nome, int tam); // busca um produto num vetor

int comparaProduto(Produto *p, char *nome);

char *getNomeProduto(Produto *p); // retorna o nome do produto

float getPrecoProduto(Produto *p); // retorna o preco do produto

char *getCodigoProduto(Produto *p); //retorna o codigo do produto

void imprimeProduto(Produto *p);

void liberaProduto(Produto *p); // libera a memoria alocada por um produto

#endif