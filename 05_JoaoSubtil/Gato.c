#include "Gato.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define BRAVO 1
#define MANSO 0

struct gato
{
    int nivel;
    char *nome;
};

Gato *inicGato(char *nome, int nivel)
{
    Gato *c = (Gato *)malloc(sizeof(Gato));
    c->nivel = nivel;
    c->nome = strdup(nome);

    return c;
}

void imprimeGato(Gato *c)
{
printf("- Nome do cat: %s\n", c->nome);
}

void atribuiNivelAgressividadeGato(Gato *c, int nivel){
c->nivel = nivel;
}

char *getNomeGato(Gato *c)
{
    return c->nome;
}

int getNivelGato(Gato *c)
{
    return c->nivel;
}

void liberaGato(Gato *c)
{   free(c->nome);
    free(c);
}
