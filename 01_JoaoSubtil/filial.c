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

Filial *CriaFilial()
{
    Filial *f = (Filial *)malloc(sizeof(Filial));

    printf("\nInsira o nome da filial:\n");
    f->nome = leLinhaFilial();
    f->est = CriaEstoque();

    return f;
}

char *getNomeFilial(Filial *f)
{
    return f->nome;
}

Estoque *getEstoqueFilial(Filial *f){
    return f->est;
}

float calculaValorFilial(Filial *f)
{
    return calculaValorEstoque(f->est);
}

void AdicionaItemFilial(Filial *f, Item *i)
{
    adicionaItemEstoque(f->est, i);
}

void imprimeFilial(Filial *f)
{
    printf("      Filial: %s\n", f->nome);
    imprimeEstoque(f->est);
}

void liberaFilial(Filial *f)
{
    LiberaEstoque(f->est);
    free(f);
}
