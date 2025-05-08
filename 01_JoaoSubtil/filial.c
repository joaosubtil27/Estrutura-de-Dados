#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "filial.h"

struct Filial
{
    char *nome;
    Estoque *est;
};

char *leLinha()
{
    char temp[100];
    scanf("%99[^\n]", temp);
    char *str = strdup(temp);
    return str;
}

Filial *CriaFilial()
{
    Filial *f = (Filial *)malloc(sizeof(Filial));

    printf("Insira o nome da filial:\n");
    f->nome = leLinha();
    f->est = CriaEstoque();

    return f;
}

float getValorFilial(Filial *f)
{
    return calculaValorEstoque(f->est);
}

void imprimeFilial(Filial *f)
{
    printf("             Filial: %s\n", f->nome);
    imprimeEstoque(f->est);
}

void liberaFilial(Filial *f)
{
    LiberaEstoque(f->est);
    free(f);
}
