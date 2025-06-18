//
//  posto.h
//  PostoSaude
//
//  Created by Patricia Dockhorn Costa on 14/07/22.
//

// Define o limite entre positivo e negativo
// Amostras com carga viral >= LIMETE_CARGA_VIRAL são consideradas POSITIVAS
// Amostras com carga viral < LIMETE_CARGA_VIRAL são consideradas NEGATIVAS
#define LIMITE_CARGA_VIRAL 500

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "posto.h"
#include "fila.h"
/*Tipo que define um Posto de Saúde (tipo opaco)
 *Um posto deve ter os seguintes atributos:
 * * Nome do Posto
 * * Uma FILA de amostras para exame não processadas
 * * Uma FILA de amostras processadas com resultado POSITIVO
 * * Uma FILA de amostras processadas com resultado NEGATIVO
 * */
struct posto
{
    char *nome;
    Fila *espera;
    Fila *pos;
    Fila *neg;
};

/* Cria um posto de saúde, ainda vazio, com as 3 filas, vazias
 * inputs: nome do posto de saúde.
 * output: posto alocado e vazio, com filas de amostras ainda vazias
 * pre-condicao: nao tem
 * pos-condicao: posto alocado e vazio, com filas de amostras alocadas e vazias
 */
Posto *inicPosto(char *nome)
{
    Posto *p = (Posto *)malloc(sizeof(Posto));
    p->espera = criaFila();
    p->neg = criaFila();
    p->pos = criaFila();
    p->nome = strdup(nome);

    return p;
}

/* Imprime os dados do Posto no seguinte formato:

 Dados do Posto: <nome do posto>
 Amostras não processadas
 <fila de amostras não processadas - do início ao fim>

 Amostras com resultados positivos
 <fila de amostras positivas - do início ao fim>

 Amostra com resultados negativos
 <fila de amostras negativas - do início ao fim>

* inputs: referencia para o posto
* output: nenhum
* pre-condicao: posto alocado
* pos-condicao: dados do posto não são alterados
 */
void imprimePosto(Posto *posto)
{
    printf("Dados do Posto: %s\n", posto->nome);
    printf("Amostras não processadas\n");
    imprimeFila(posto->espera);
    printf("\nAmostras com resultados positivos\n");
    imprimeFila(posto->pos);
    printf("\nAmostra com resultados negativos\n");
    imprimeFila(posto->neg);
}

/* Simula a realização de uma coleta de material para teste
 * A função deve criar uma amostra e fazer as devidas atribuições à amostra
 * Deve-se inserir a amostra na fila de "não processados"
 * ATENÇÃO: se a pessoa for idosa (idade>=60), ela deve ir para o início da fila de não processados
 * inputs: referência para o posto de saúde, o nome do dono da coleta e a idade da pessa
 * output: nenhum
 * pre-condicao: posto válido, nome da pessoa válido
 * pos-condicao: Amostra alocada e inserida na fila de amostras não processadas
 */
void realizaColeta(Posto *posto, char *pessoa, int idade)
{
    Amostra *a = inicAmostra(pessoa, idade);
    //imprimeAmostra(a);
    adicionaFila(posto->espera, a);
    //imprimeFila(posto->espera);
}

/* Essa função simula o processamento (testagem) das amostras e atualiza os resultados nas amostras. Deve-se usar a constante LIMITE_CARGA_VIRAL para definir positivo e negativo.
 * inputs: referência do posto de saúde.
 * output: nenhum
 * pre-condicao: posto válido
 * pos-condicao: amostras foram devidamente processadas; fila de amostras não processadas deve ficar vazia; fila de amostras positivas deve conter as amostras que testaram positivo (idosos na frente); fila de amostras negativas deve conter as amostras que testaram negativo (idosos na frente).
 */
void processaLoteAmostras(Posto *posto)
{
}

/* Libera toda a memória alocada para o posto de saúde
 * inputs: referência do posto de saúde.
 * output: nenhum
 * pre-condicao: posto válido
 * pos-condicao: Memória para a string nome liberada; memória para as 3 filas liberada, memoria do posto liberada
 */
void liberaPosto(Posto *posto)
{
    liberaFila(posto->espera);
    liberaFila(posto->neg);
    liberaFila(posto->pos);
    free(posto->nome);
    free(posto);
}
