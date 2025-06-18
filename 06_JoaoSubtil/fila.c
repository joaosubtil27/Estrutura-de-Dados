//
//  Fila.h
//  PostoSaude
//
//  Created by Patricia Dockhorn Costa on 14/07/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
struct celula
{
    Amostra *amstr;
    celula *atras;
};
// Tipo opaco que define a Fila para testagem
struct fila
{
    celula *inicio;
    celula *fim;
};

// Cria uma nova Fila, cujo dono tem um nome e uma idade
// Essa função gera um valor aleatório entre 0 e 1000 para simular a carga viral de uma pessoa
Fila *criaFila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->fim = NULL;
    f->inicio = NULL;
    return f;
}

void adicionaFila(Fila *f, Amostra *a)
{
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->amstr = a;
    nova->atras = NULL;

    if (f->fim == NULL && f->inicio == NULL)
    {
        f->fim = nova;
        f->inicio = nova;
    }
    else if (retornaIdade(nova->amstr) < 60)
    {
        f->fim->atras = nova;
    }
    else if (retornaIdade(nova->amstr) >= 60)
    {
        nova->atras = f->inicio;
        f->inicio = nova;
    }
}

Amostra *removeFila(Fila *f, Amostra *a)
{
    celula *aux;
    aux = f->inicio;
    f->inicio = aux->atras;
    return aux->amstr;

}

// Imprime os dados da Fila no formato:
// Nome do dono da Fila: Patricia, carga viral: 807, idade: 44, resultado: POSITIVO
void imprimeFila(Fila *f)
{
    celula *aux = f->inicio;
    while (1)
    {
        if (aux == NULL)
            break;
        imprimeAmostra(aux->amstr);
        aux = aux->atras;
    }
}

// libera todoas os dados alocados para a Fila
void liberaFila(Fila *f)
{
    celula *aux = f->inicio;
    celula *prox = aux;
    ;
    while (aux !=NULL)
    {
        prox = aux->atras;
        liberaAmostra(aux->amstr);
        free(aux);
        aux = prox;
    }
    free(f);
}
