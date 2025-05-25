#include "lista.h"
#include "stdlib.h"
#include "stdio.h"
struct Celula
{
    Produto *p;
    Celula *prox;
};

struct Lista
{
    Celula *prim;
    Celula *ult;
};

Lista *criaLista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->prim = NULL;
    l->ult = NULL;

    return l;
}

void InsereProdutoLista(Lista *l, Produto *prod)
{
    Celula *cel = (Celula *)malloc(sizeof(Celula));
    if (l->prim == NULL)
    {
        cel->p = prod;
        l->prim = cel;
        l->ult = cel;
        cel->prox = NULL;
    }
    else if (prod != NULL)
    {
        l->ult->prox = cel;
        l->ult = cel;
        cel->p = prod;
        cel->prox = NULL;
    }
    else
        free(cel);

    if (cel != NULL)
        printf("%s foi inserido\n", getNomeProduto(cel->p));
}

Produto *ApagaProdutoLista(Lista *p, char *nome)
{
    Produto *ret = NULL;
    Celula *bfr, *aft;
    aft = p->prim;
    bfr = p->prim;
    while (1)
    {
        if (comparaProduto(aft->p, nome) == 0)
        {
            if (aft == p->prim)
            {
                p->prim = p->prim->prox;
                ret = p->prim->p;
                free(aft);
                break;
            }

            else if (aft == p->ult)
            {
                bfr->prox = NULL;
                ret = aft->p;
                p->ult = bfr;
                free(aft);
                break;
            }
            else
            {
                ret = aft->p;
                bfr->prox = aft->prox;
                free(aft);
                break;
            }
        }

        else if (aft == p->ult)
        {
            break;
        }

        else
        {
            bfr = aft;
            aft = aft->prox;
        }
    }
    return ret;
}
void ImprimeLista(Lista *l)
{
    Celula *nav = l->prim;
    while (nav != NULL)
    {
        imprimeProduto(nav->p);
        nav = nav->prox;
    }
}
void liberaLista(Lista *p)
{
    Celula *bfr, *aft;
    bfr = p->prim;
    aft = p->prim;
    while (1)
    {
        bfr = aft;
        aft = bfr->prox;
        free(bfr);
        if (aft == p->ult)
        {
            free(aft);
            break;
        }
    }
    free(p);
}