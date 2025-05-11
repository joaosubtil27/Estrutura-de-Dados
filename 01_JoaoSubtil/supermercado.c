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

Supermercado *CriaSupermercado() // funcao que aloca um supermercado e inicializa suas variaveis
{
    Supermercado *s = (Supermercado *)malloc(sizeof(Supermercado));
    printf("\nInsira o nome do supermercado:\n");
    s->nome = leLinhaSupermercado();
    s->est_total = 0;
    s->qnt_filiais = 0;
    s->filiais = (Filial **)malloc(sizeof(Filial *));
    return s;
}

void adicionaFilialSupermercado(Supermercado *s) // adiciona uma filial no vetor de filiais do supermercado
{
    s->qnt_filiais++;

    s->filiais = (Filial **)realloc(s->filiais, s->qnt_filiais * sizeof(Filial *));
    s->filiais[s->qnt_filiais - 1] = CriaFilial();
}

Filial *buscaFilial(Supermercado *s, char *nome) // busca por uma filial no vetor
{
    for (int i = 0; i < s->qnt_filiais; i++)
    {
        if (strcmp(getNomeFilial(s->filiais[i]), nome) == 0)
            return s->filiais[i];
    }
    return NULL;
}

char *getNomeSupermercado(Supermercado *s) // retorna nome do supermercado
{
    return s->nome;
}

float getValorSupermercado(Supermercado *s) // retorna o valor do supermercado
{
    return s->est_total;
}

void calculaValorSupermercado(Supermercado *s) // calcula o valor do supermercado
{
    s->est_total = 0;

    for (int i = 0; i < s->qnt_filiais; i++)
    {
        s->est_total += calculaValorFilial(s->filiais[i]);
    }
}

Supermercado *buscaSupermercado(Supermercado **s, char *nome, int tam) // busca um supermercado num vetor
{
    for (int i = 0; i < tam; i++)
    {
        if (strcmp(getNomeSupermercado(s[i]), nome) == 0)
            return s[i];
    }
    return NULL;
}

void imprimeSupermercado(Supermercado *s) // imprime as informacoes sobre o supermercado, filiais e os produtos cadastrados em cada uma
{
    calculaValorSupermercado(s);
    printf("\nNome: %s, Estoque Total: %.2f\n\n", s->nome, s->est_total);
    for (int i = 0; i < s->qnt_filiais; i++)
    {
        imprimeFilial(s->filiais[i]);
        printf("\n");
    }
}

void liberaSupermercado(Supermercado *s) // libera a memoria alocada por um supermercado
{
    for (int i = 0; i < s->qnt_filiais; i++)
    {
        liberaFilial(s->filiais[i]);
    }
    free(s->filiais);
    free(s);
}