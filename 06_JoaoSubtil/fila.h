//
//  Fila.h
//  PostoSaude
//
//  Created by Patricia Dockhorn Costa on 14/07/22.
//

#ifndef fila_h
#define fila_h

#include <stdio.h>
#include "amostra.h"

//Tipo opaco que define a Fila para testagem

typedef struct celula celula;
typedef struct fila Fila;

//Cria uma nova Fila, cujo dono tem um nome e uma idade
//Essa função gera um valor aleatório entre 0 e 1000 para simular a carga viral de uma pessoa
Fila *criaFila();

void adicionaFila(Fila *f, Amostra *a);

Amostra *removeFila(Fila *f, Amostra *a);

// Imprime os dados da Fila no formato:
// Nome do dono da Fila: Patricia, carga viral: 807, idade: 44, resultado: POSITIVO
void imprimeFila(Fila *f);

// libera todoas os dados alocados para a Fila
void liberaFila(Fila *f);

#endif
