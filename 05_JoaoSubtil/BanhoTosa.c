
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gato.h"
#include "Cachorro.h"
#include "BanhoTosa.h"
#include "Lista.h"

/*Tipo que define a loja de banho e tosa (tipo opaco)
 *Cada loja deve ter os seguintes atributos:
 * * Nome da loja
 * * Uma lista de animais (gatos e cachorros) agressivos
 * * Uma lista de animais (gatos e cachorros) mansos
 * */
struct banhotosa
{
    Lista *manso;
    Lista *bravo;
    char *nome;
};

/* Cria uma loja de banho e tosa, ainda vazia, com duas listas de animais vazias
 * inputs: nome da loja (char*). Esta função deve alocar dinamicamente o nome da loja.
 * output: loja alocada e vazia, com listas de animais ainda vazias
 * pre-condicao: nao tem
 * pos-condicao: loja alocada e vazia, com listas de animais criadas e vazias  */
BanhoTosa *inicBanhoTosa(char *nome)
{
    BanhoTosa *b = (BanhoTosa *)malloc(sizeof(BanhoTosa));
    b->nome = nome;
    b->bravo = criaLista();
    b->manso = criaLista();
    return b;
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
 * inputs: referência para a loja e a referência para o animal
 * output: nenhum
 * pre-condicao: loja alocada e animal alocado
 * pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraCachorro(BanhoTosa *loja, Cachorro *dog)
{

    if (getNivelCachorro(dog) == BRAVO)
    {
        adicionaLista(loja->bravo, dog, 'c');
    }
    else
        adicionaLista(loja->manso, dog, 'c');
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
 * inputs: referência para a loja e a referência para o animal
 * output: nenhum
 * pre-condicao: loja alocada e animal alocado
 * pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraGato(BanhoTosa *loja, Gato *cat)
{
    if (getNivelGato(cat) == BRAVO)
    {
        adicionaLista(loja->bravo, cat, 'g');
    }
    else
        adicionaLista(loja->manso, cat, 'g');
}

/* Essa função atualiza a situação de um gato na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
 * inputs: referência para a loja e a referência para o animal
 * output: nenhum
 * pre-condicao: loja alocada e animal alocado
 * pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoGato(BanhoTosa *loja, Gato *cat)
{
    int verif = 0;

    if (getNivelGato(cat) == MANSO)
    {
        Celula *aux = getPrim(loja->manso);
        while (aux != NULL)
        {
            if (getId(aux) == 'g' && strcmp(getNome(aux), getNomeGato(cat)) == 0)
            {
                verif = 1;
                break;
            }
            aux = getProx(aux);
        }
        if (verif == 0)
        {
            aux = getPrim(loja->bravo);
            while (aux != NULL)
            {
                if (getId(aux) == 'g' && strcmp(getNome(aux), getNomeGato(cat)) == 0)
                {
                    adicionaLista(loja->manso, (Gato*)getAnimal(aux), 'g');
                    removeLista(loja->bravo, getNome(aux), 'g');
                    verif = 1;
                    break;
                }
                aux = getProx(aux);
            }
        }
    }

    else if (getNivelGato(cat) == BRAVO)
    {
        Celula *aux = getPrim(loja->bravo);
        while (aux != NULL)
        {
            if (getId(aux) == 'g' && strcmp(getNome(aux), getNomeGato(cat)) == 0)
            {
                verif = 1;
                break;
            }
            aux = getProx(aux);
        }
        if (verif == 0)
        {
            aux = getPrim(loja->manso);
            while (aux != NULL)
            {
                if (getId(aux) == 'g' && strcmp(getNome(aux), getNomeGato(cat)) == 0)
                {
                    adicionaLista(loja->bravo, (Gato*)getAnimal(aux), 'g');
                    removeLista(loja->manso, getNome(aux), 'g');
                    verif = 1;
                    break;
                }
                aux = getProx(aux);
            }
        }
    }
}

/* Essa função atualiza a situação de um cachorro na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
 * inputs: referência para a loja e a referência para o animal
 * output: nenhum
 * pre-condicao: loja alocada e animal alocado
 * pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoCachorro(BanhoTosa *loja, Cachorro *dog)
{
    int verif = 0;

    if (getNivelCachorro(dog) == MANSO)
    {
        Celula *aux = getPrim(loja->manso);
        while (aux != NULL)
        {
            if (getId(aux) == 'c' && strcmp(getNome(aux), getNomeCachorro(dog)) == 0)
            {
                verif = 1;
                break;
            }
            aux = getProx(aux);
        }
        if (verif == 0)
        {
            aux = getPrim(loja->bravo);
            while (aux != NULL)
            {
                if (getId(aux) == 'c' && strcmp(getNome(aux), getNomeCachorro(dog)) == 0)
                {
                    adicionaLista(loja->manso, (Cachorro*)getAnimal(aux), 'c');
                    removeLista(loja->bravo, getNome(aux), 'c');
                    verif = 1;
                    break;
                }
                aux = getProx(aux);
            }
        }
    }

    else if (getNivelCachorro(dog) == BRAVO)
    {
        Celula *aux = getPrim(loja->bravo);
        while (aux != NULL)
        {
            if (getId(aux) == 'c' && strcmp(getNome(aux), getNomeCachorro(dog)) == 0)
            {
                verif = 1;
                break;
            }
            aux = getProx(aux);
        }
        if (verif == 0)
        {
            aux = getPrim(loja->manso);
            while (aux != NULL)
            {
                if (getId(aux) == 'c' && strcmp(getNome(aux), getNomeCachorro(dog)) == 0)
                {
                    adicionaLista(loja->bravo, (Cachorro*)getAnimal(aux), 'c');
                    removeLista(loja->manso, getNome(aux), 'c');
                    verif = 1;
                    break;
                }
                aux = getProx(aux);
            }
        }
    }
}

/* Imprime os dados da Loja (nome, e conteúdo das listas)
 * inputs: referencia para a loja
 * output: nenhum
 * pre-condicao: loja alocada
 * pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
void imprimeBanhoTosa(BanhoTosa *loja)
{
printf("Nome da loja: %s\n", loja->nome);
printf("Animais mansos:\n");
imprimeLista(loja->manso);
printf("\n\nAnimais bravos:\n");
imprimeLista(loja->bravo);
printf("\n\n");
}

/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor Gato: 30 reais, Valor Cachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(BanhoTosa *loja)
{
    int valor = 0;
    Celula *aux = getPrim(loja->manso);
    while (aux != NULL)
    {
        if (getId(aux) == 'c')
        {
            valor += 40;
        }
        else if (getId(aux) == 'g')
            valor += 30;
        aux = getProx(aux);
    }
    aux = getPrim(loja->bravo);
    while (aux != NULL)
    {
        if (getId(aux) == 'c')
        {
            valor += 45;
        }
        else if (getId(aux) == 'g')
            valor += 35;
        aux = getProx(aux);
    }
    return valor;
}

/* Libera toda a memória alocada
 * inputs: referencia para a loja
 * output: não tem
 * pre-condicao: loja alocada
 * pos-condicao: Toda a memória liberada, a não ser gatos e cachorros, que são responsabilidade do cliente. */
void liberaBanhoTosa(BanhoTosa *loja)
{
    liberaLista(loja->manso);
    liberaLista(loja->bravo);
    free(loja);
}
