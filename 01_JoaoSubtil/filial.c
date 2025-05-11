#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "filial.h"

struct Filial
{
    char *nome;
    Estoque *est;
};

char *leLinhaFilial()
{
    char temp[100];
    scanf(" %99[^\n]", temp);
    return strdup(temp);
}

Filial *CriaFilial() // cria um filial
{
    Filial *f = (Filial *)malloc(sizeof(Filial));

    printf("\nInsira o nome da filial:\n");
    f->nome = leLinhaFilial();
    f->est = CriaEstoque();

    return f;
}

char *getNomeFilial(Filial *f) // retorna o nome da filial
{
    return f->nome;
}

Estoque *getEstoqueFilial(Filial *f) // retorna o estoque da filial
{
    return f->est;
}

float calculaValorFilial(Filial *f) // calcula valor da filial
{
    return calculaValorEstoque(f->est);
}

void AdicionaItemFilial(Filial *f, Item *i) // adiciona um produto ao estoque de uma filial
{
    adicionaItemEstoque(f->est, i);
}

void imprimeFilial(Filial *f) // imprime as informacoes da filial e dos itens no estoque
{
    printf("      Filial: %s\n", f->nome);
    imprimeEstoque(f->est);
}

void liberaFilial(Filial *f) // libera a memoria de uma filial
{
    LiberaEstoque(f->est);
    free(f);
}
