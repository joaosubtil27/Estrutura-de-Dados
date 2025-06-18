#include "Cachorro.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define BRAVO 1
#define MANSO 0

struct cachorro
{
    int nivel;
    char *nome;
};

Cachorro *inicCachorro(char *nome, int nivel)
{
    Cachorro *c = (Cachorro *)malloc(sizeof(Cachorro));
    c->nivel = nivel;
    c->nome = strdup(nome);

    return c;
}

void imprimeCachorro(Cachorro *c)
{
printf("- Nome do dog: %s\n", c->nome);
}
void atribuiNivelAgressividadeCachorro(Cachorro *c, int nivel){
c->nivel = nivel;
}

char *getNomeCachorro(Cachorro *c)
{
    return c->nome;
}

int getNivelCachorro(Cachorro *c)
{
    return c->nivel;
}

void liberaCachorro(Cachorro *c)
{   free(c->nome);
    free(c);
}
