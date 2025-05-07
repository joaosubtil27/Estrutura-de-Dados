#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

void calc_esfera(float r, float *area, float *volume);
int raizes(float a, float b, float c, float *x1, float *x2);
int pares(int n, int *vet);
void inverte(int n, int *vet);
double avalia(double *poli, int grau, double x);

int main()
{
    int tipo;

    while (1)
    {

        printf("\nOpcoes:\n");
        printf("1 - Calcula Area e Volume\n");
        printf("2 - Calcula raizes de uma funcao quadratica\n");
        printf("3 - Informa a quantidade de pares em uma sequencia\n");
        printf("4 - Inverte uma sequencia\n");
        printf("5 - Avalia polinomios\n");
        printf("6 - Fim do programa\n");
        printf("Digite a opcao: ");
        scanf("%d", &tipo);

        if (tipo == 1)
        {

            float r, area, volume;

            printf("Digite o raio: ");
            scanf("%f", &r);
            if (r >= 0) // raio nao pode ser negativo
            {
                calc_esfera(r, &area, &volume);
                printf("\nArea: %.2f\n", area);
                printf("Volume: %.2f\n", volume);
            }
            else
                printf("\nValor invalido\n");
        }

        else if (tipo == 2)
        {

            float a, b, c, x1, x2;

            printf("Digite os coeficientes: ");
            scanf("%f %f %f", &a, &b, &c);
            if (a != 0) // termo independente do x^2 tem que ser diferente de 0 para ser uma quadratica
            {
                if (raizes(a, b, c, &x1, &x2) == 1) // verifica se existe alguma raiz real
                {

                    printf("\nTem raizes reais\n");
                    printf("x1 = %.2f, x2 = %.2f\n", x1, x2);
                }
                else
                    printf("\nNao tem raizes reais\n");
            }
            else
                printf("\nNao eh uma funcao quadratica\n");
        }

        else if (tipo == 3)
        {

            int n, *vet;

            printf("Digite a quantidade de termos: ");
            scanf("%d", &n);
            if (n >= 0)//quantidade de termos nao pode ser negativa
            {
                vet = (int *)malloc(n * sizeof(int));

                printf("Digite os termos: ");

                for (int i = 0; i < n; i++)
                {
                    scanf("%d", &vet[i]);
                }

                printf("\nQuantidade de pares: %d\n", pares(n, vet));
                free(vet);
            }
            else
                printf("\nValor invalido\n");
        }

        else if (tipo == 4)
        {
            int n, *vet;

            printf("Digite a quantidade de termos: ");
            scanf("%d", &n);
            if (n >= 0)//quantidade de termos nao pode ser negativa
            {
                vet = (int *)malloc(n * sizeof(int));

                printf("Digite os termos: ");

                for (int i = 0; i < n; i++)
                {
                    scanf("%d", &vet[i]);
                }

                printf("\nVetor original: ");
                for (int i = 0; i < n; i++)
                {
                    printf("%d ", vet[i]);
                }
                printf("\n");

                inverte(n, vet);

                printf("Vetor invertido: ");
                for (int i = 0; i < n; i++)
                {
                    printf("%d ", vet[i]);
                }
                printf("\n");
                free(vet);
            }
            else
                printf("\nValor invalido\n");
        }

        else if (tipo == 5)
        {
            double *poli, x;
            int grau;

            printf("\nDigite o grau do polinomio: ");
            scanf("%d", &grau);
            if (grau >= 0) //grau de uma funcao nao pode ser negativo
            {
                poli = (double *)malloc(grau * sizeof(double));

                printf("Digite os coeficentes ao contrario: ");  //requerido na especificacao

                for (int i = 0; i <= grau; i++)
                {
                    scanf("%lf", &poli[i]);
                }

                printf("Digite o valor de x: ");
                scanf("%lf", &x);

                printf("\nValor final: %.2f\n", avalia(poli, grau, x));
                free(poli);
            }
            else
                printf("\nValor invalido\n");
        }

        else if (tipo == 6)
        {
            printf("\nFim do programa\n");
            break;
        }

        else
        {
            printf("\nOpcao invalida\n");
        }
    }

    return 0;
}

void calc_esfera(float r, float *area, float *volume)
{
    *area = 4 * r * r * PI;
    *volume = (4 * r * r * r * PI) / 3;
}

int raizes(float a, float b, float c, float *x1, float *x2)
{
    int delta = b * b - (4 * a * c);

    if (delta > 0) // tem duas raizes diferentes
    {
        *x1 = (-b + sqrt(delta)) / 2 * a;
        *x2 = (-b - sqrt(delta)) / 2 * a;
        return 1;
    }

    else if (delta == 0) // duas raizes iguais
    {
        *x1 = (-b + sqrt(delta)) / 2 * a;
        *x2 = *x1;
        return 1;
    }

    else // nenhuma raiz real
        return 0;
}

int pares(int n, int *vet)
{
    int n_pares = 0;

    for (int i = 0; i < n; i++)
    {
        if (vet[i] % 2 == 0)
            n_pares++;
    }
    return n_pares;
}

void inverte(int n, int *vet)
{
    int troca;

    for (int i = 0; i < (n / 2); i++)
    {
        troca = vet[i];
        vet[i] = vet[n - i - 1];
        vet[n - i - 1] = troca;
    }
}
double avalia(double *poli, int grau, double x)
{
    double soma = 0;

    for (int i = 0; i <= grau; i++)
    {

        soma += poli[i] * pow(x, i);// soma em ordem crescente de potencia relacionada ao x
    }

    return soma;
}
