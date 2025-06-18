#ifndef Gato_h
#define Gato_h

#define BRAVO 1
#define MANSO 0

typedef struct gato Gato;

Gato *inicGato(char *nome, int nivel);

void imprimeGato(Gato* c);

void atribuiNivelAgressividadeGato(Gato *c, int nivel);

char* getNomeGato(Gato* c);

int getNivelGato(Gato* c);

void liberaGato(Gato* c);

#endif