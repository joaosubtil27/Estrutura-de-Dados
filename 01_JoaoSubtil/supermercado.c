#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "supermercado.h"

struct Supermercado
{
    char *nome;
    Filial **filiais;
    float est_total;
    int qnt_filiais;
};


char *leLinhaSupermercado()
{
    char temp[100];
    scanf(" %99[^\n]", temp);
    return strdup(temp);
}


Supermercado *CriaSupermercado()
{
    Supermercado *s = (Supermercado *)malloc(sizeof(Supermercado));
    printf("\nInsira o nome do supermercado:\n");
    s->nome = leLinhaSupermercado();
    s->est_total = 0;
    s->qnt_filiais = 0;
    s->filiais = (Filial **)malloc(sizeof(Filial *));
    return s;
}

void adicionaFilialSupermercado(Supermercado *s)
{
    s->qnt_filiais++;

    s->filiais = (Filial **)realloc(s->filiais, s->qnt_filiais * sizeof(Filial *));
    s->filiais[s->qnt_filiais - 1] = CriaFilial();
}

Filial *buscaFilial(Supermercado *s, char *nome)
{
    for (int i = 0; i < s->qnt_filiais; i++)
    {
        if (strcmp(getNomeFilial(s->filiais[i]), nome) == 0)
            return s->filiais[i];
    }
    return NULL;
}

char *getNomeSupermercado(Supermercado *s)
{
    return s->nome;
}

float getValorSupermercado(Supermercado *s)
{
    return s->est_total;
}

void calculaValorSupermercado(Supermercado *s)
{
    s->est_total = 0;

    for (int i = 0; i < s->qnt_filiais; i++)
    {
        s->est_total += calculaValorFilial(s->filiais[i]);
    }
}

void imprimeSupermercado(Supermercado *s)
{   calculaValorSupermercado(s);
    printf("\nNome: %s, Estoque Total: %.2f\n\n", s->nome, s->est_total);
    for(int i=0; i<s->qnt_filiais; i++){
        imprimeFilial(s->filiais[i]);
        printf("\n");
    }
}

void liberaSupermercado(Supermercado *s)
{
    for (int i = 0; i < s->qnt_filiais; i++)
    {
        liberaFilial(s->filiais[i]);
    }
    free(s->filiais);
    free(s);
}