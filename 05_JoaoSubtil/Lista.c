#include "Lista.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Cachorro.h"
#include "Gato.h"

#define BRAVO 1
#define MANSO 0

struct celula
{
    void *animal;
    char id;
    Celula *prox, *ant;
};

struct lista
{
    Celula *prim, *ult;
};

Lista *criaLista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

void adicionaLista(Lista *l, void *dado, char id)
{
    if (dado != NULL)
    {
        Celula *nova = (Celula *)malloc(sizeof(Celula));
        nova->prox = NULL;
        nova->ant = NULL;
        nova->animal = dado;
        nova->id = id;

        if (l->prim == NULL)
        {
            l->prim = nova;
            l->ult = nova;
        }
        else
        {
            l->ult->prox = nova;
            nova->ant = l->ult;
            l->ult = nova;
        }
    }
}
char getId(Celula *l)
{
    return l->id;
}

char *getNome(Celula *l)
{
    if (l->id == 'c')
        return getNomeCachorro(l->animal);
    else if (l->id == 'g')
        return getNomeGato(l->animal);
    else
        return NULL;
}

void *getAnimal(Celula *l)
{
    return l->animal;
}

Celula *getProx(Celula *l)
{
    return l->prox;
}

Celula *getAnt(Celula *l)
{
    return l->ant;
}

Celula *getPrim(Lista *l)
{
    return l->prim;
}

Celula *getUlt(Lista *l)
{
    return l->ult;
}

void removeLista(Lista *l, char *nome, char id)
{
    Celula *aux = l->prim;
    while (1)
    {
        if (aux->id == id && strcmp(getNome(aux), nome) == 0)
        {
            if (aux == l->prim)
            {
                l->prim = aux->prox;
            }
            else if (aux == l->ult)
            {
                l->ult = aux->ant;
                aux->ant->prox = NULL;
            }
            else
            {
                aux->prox->ant = aux->ant;
                aux->ant->prox = aux->prox;
            }

            free(aux);
            break;
        }
        aux = aux->prox;
    }
}

void imprimeLista(Lista *l)
{
    Celula *aux = l->prim;
    while (1)
    {

        if (aux->id == 'c')
            imprimeCachorro(aux->animal);
        else if (aux->id == 'g')
            imprimeGato(aux->animal);

        if (aux->prox == NULL)
            break;
        aux = aux->prox;
    }
}

void liberaLista(Lista *l)
{
    Celula *aux = l->prim;
    while (aux != NULL)
    {
        Celula *prox = aux->prox;
        free(aux);
        aux = prox;
    }
    free(l);
}