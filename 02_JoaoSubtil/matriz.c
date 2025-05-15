#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

// Tipo matriz (tipo opaco)
// Estrutura interna do tipo deve ser definida na implementacao do TAD
struct matriz
{
    int rows;
    int cols;
    int **matriz;
};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz *inicializaMatriz(int nlinhas, int ncolunas)
{
    if (nlinhas > 0 && ncolunas > 0)
    {
        Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
        mat->rows = nlinhas;
        mat->cols = ncolunas;
        mat->matriz = (int **)malloc(nlinhas*sizeof(int *));
        for (int i = 0; i < nlinhas; i++)
        {
            mat->matriz[i] = (int *)malloc(ncolunas * sizeof(int));
        }

        return mat;
    }
    else
        return NULL;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento(Matriz *mat, int linha, int coluna, int elem)
{
    mat->matriz[linha][coluna] = elem;
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a colunaall: debug_compile clean debug_run
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: mat nao eh modificada
 */
int recuperaElemento(Matriz *mat, int linha, int coluna)
{
    return mat->matriz[linha][coluna];
}

/*Retorna o numero de colunas da matriz mat
 * inputs: a matriz
 * output: o numero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNColunas(Matriz *mat)
{
    return mat->cols;
}

/*Retorna o numero de linhas da matriz mat
 * inputs: a matriz
 * output: o numero de linhas da matriz
#endif
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNLinhas(Matriz *mat)
{
    return mat->rows;
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada e matriz transposta existe
 */
Matriz *transposta(Matriz *mat)
{

    Matriz *transp = inicializaMatriz(mat->cols, mat->rows);
    for (int i = 0; i < mat->rows; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        {
            transp->matriz[j][i] = mat->matriz[i][j];
        }
    }
    return transp;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicacao
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1 correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 nao sao modificadas e a matriz multiplicacao existe
 */
Matriz *multiplicacao(Matriz *mat1, Matriz *mat2)
{
    int indice_cols2 = 0;
    int indice_rows1 = 0;
    Matriz *prod = inicializaMatriz(mat1->rows, mat2->cols);

    for (int i = 0; i < mat1->rows; i++)
    {
        for (int j = 0; j < mat2->cols; j++)
        {
            modificaElemento(prod, i, j, 0);
        }
    }

    imprimeMatriz(mat1);
    printf("\n\n");
    imprimeMatriz(mat2);
    printf("\n\n");

    while (indice_rows1 < mat1->rows && indice_cols2 < mat2->cols)
    {
        for (int j = 0; j < mat1->cols; j++)
        {
            prod->matriz[indice_rows1][indice_cols2] += mat1->matriz[indice_rows1][j] * mat2->matriz[j][indice_cols2];
        }
        indice_cols2++;
        if (indice_cols2 == mat2->cols)
        {
            indice_rows1++;
            indice_cols2 = 0;
        }
    }

    return prod;
}

/*Imprime a matriz completa
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz *mat)
{
    for (int i = 0; i < mat->rows; i++)
    {
        imprimeLinha(mat, i);
        printf("\n");
    }
}

/*Imprime apenas uma linha da matriz
 * inputs: matriz mat e o indice da linha
 * output: nenhum
 * pre-condicao: matriz mat existe e indice eh valido na matriz
 * pos-condicao: nenhuma
 */
void imprimeLinha(Matriz *mat, int indice)
{
    for (int j = 0; j < mat->cols; j++)
    {
        printf("%d ", mat->matriz[indice][j]);
    }
}

/*Libera toda a memoria alocada para a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: memoria ocupada por linhas e colunas liberada!
 */
void destroiMatriz(Matriz *mat)
{
    for (int i = 0; i < mat->rows; i++)
    {
        free(mat->matriz[i]);
    }
    free(mat->matriz);
    free(mat);
}
