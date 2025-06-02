#include "lista.h"
#include "stdlib.h"
#include "stdio.h"

struct Lista
{
    Lista *aft;
    Lista *bfr;
    Produto *p;
};

Lista *criaLista()
{

    return NULL;
}

Lista *InsereProdutoLista(Lista *l, Produto *prod)
{
    Lista *cel = (Lista *)malloc(sizeof(Lista));
    if (prod != NULL)
    {
        cel->p = prod;
        cel->aft = l;
        cel->bfr = NULL;

        if (l != NULL)
            l->bfr = cel;
    }
    else
        free(cel);

    if (cel != NULL)
        printf("%s foi inserido\n", getNomeProduto(cel->p));

    return cel;
}

Lista *ApagaProdutoLista(Lista *p, char *nome)
{
    Lista *ret = p;
    Lista *aux = p;
    while (1)
    {
        if (comparaProduto(aux->p, nome) == 0)
        {
            if (aux->bfr == NULL && aux->aft == NULL)
            {
                printf("ENTREI1\n");
                printf("%s foi removido\n", getNomeProduto(aux->p));
                free(aux);
                return NULL;
                break;
            }

            else if (aux->aft == NULL)
            {
                printf("ENTREI2\n");
                aux->bfr->aft = NULL;
                printf("%s foi removido\n", getNomeProduto(aux->p));
                free(aux);
                break;
            }
            else if (aux->bfr == NULL)
            {
                printf("ENTREI4\n");
                ret = aux->aft;
                aux->aft->bfr = NULL;

                printf("%s foi removido\n", getNomeProduto(aux->p));
                free(aux);
                break;
            }
            else
            {
                printf("ENTREI3\n");
                aux->aft->bfr = aux->bfr;
                aux->bfr->aft = aux->aft;
                printf("%s foi removido\n", getNomeProduto(aux->p));
                free(aux);
                break;
            }
        }

        else if (aux->aft == NULL)
        {
            printf("Produto nao encontrado\n");
            break;
        }

        else
        {
            aux = aux->aft;
        }
    }

    return ret;
}
void ImprimeLista(Lista *l)
{
    Lista *nav = l;
    while (nav != NULL)
    {
        imprimeProduto(nav->p);
        nav = nav->aft;
    }
}
void liberaLista(Lista *p)
{
    Lista *lib = p, *aux = p;
    while (aux != NULL)
    {
        lib = aux;
        aux = aux->aft;
        free(lib);
    }
}