#ifndef Cachorro_h
#define Cachorro_h

#define BRAVO 1
#define MANSO 0

typedef struct cachorro Cachorro;

Cachorro *inicCachorro(char *nome, int nivel);

void imprimeCachorro(Cachorro* c);

void atribuiNivelAgressividadeCachorro(Cachorro *c, int nivel);

char* getNomeCachorro(Cachorro* c);

int getNivelCachorro(Cachorro* c);

void liberaCachorro(Cachorro* c);

#endif
