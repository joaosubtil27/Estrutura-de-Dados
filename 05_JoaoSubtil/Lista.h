#ifndef LISTA_h
#define LISTA_h

#define BRAVO 1
#define MANSO 0

typedef struct celula Celula;

typedef struct lista Lista;

Lista* criaLista();

void adicionaLista(Lista *l, void *dado, char id);

char getId(Celula *l);

char* getNome(Celula *l);

void* getAnimal(Celula *l);

Celula* getProx(Celula *l);

Celula* getAnt(Celula *l);

Celula* getPrim(Lista *l);

Celula* getUlt(Lista *l);

void removeLista(Lista *l, char *nome, char id);

void imprimeLista(Lista *l);

void liberaLista (Lista *l);

#endif