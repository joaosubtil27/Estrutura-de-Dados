#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *nome;
    float preco;

} produto;

typedef struct
{ 
    produto *prod;
    int qnt;

} item_estoque;

typedef struct
{
    float valor;
    item_estoque *item;

} estoque;

typedef struct
{
  char *nome;
  estoque *est;  
} filial;

typedef struct
{
    char *nome;
    filial *filiais;
    float est_total;
    int qnt_filiais;

} supermercado;


char *leLinha();

supermercado* buscaSupermercado(char* nome);
filial* buscaFilial(supermercado* s, char* nome);
produto* buscaProduto (char* nome);

float estoqueFilial (filial *f);
float estoqueSupermercado (supermercado *s);

void imprimeFilial(filial f);


int main()
{   
    int op;

    produto *prod = (produto**)malloc(sizeof(produto*));
    int qnt_prod=0;

    supermercado *sup = (supermercado**)malloc(sizeof(supermercado*));
    int qnt_sup=0;



    while(1){
    printf("\nMenu:\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Cadastrar supermercado\n");
    printf("3 - Cadastrar filial\n");
    printf("4 - Cadastrar produto na filial\n");
    printf("5 - Estoque filial\n");
    printf("6 - Estoque supermercado\n");
    printf("7 - Relatorio final\n");
    printf("8 - Encerrar programa\n");
    
    scanf("%d\n", &op);

    if(op == 1){

        qnt_prod++;
        prod = realloc(prod, qnt_prod*sizeof(produto));

        printf("\nInsira o nome:");
        prod[qnt_prod-1].nome = leLinha();

        printf("\nInsira o valor:");
        scanf("%f\n", &prod[qnt_prod-1].preco);

    }
    else if(op == 2){

        qnt_sup++;
        sup = realloc(sup, qnt_sup*sizeof(sup));

        printf("\nInsira o nome:");
        sup[qnt_sup-1].nome = leLinha();

        sup[qnt_sup].est_total = 0;
        sup[qnt_sup].qnt_filiais = 0;

    }
    else if(op == 3){

        
    }
    else if(op == 4){
        
    }
    else if(op == 5){

        printf("Insira o nome do supermercado:");
        char *nome_sup = leLinha();

        printf("Insira o nome da filial:");
        char *nome_fil = leLinha();
        
        printf("%.2f\n", estoqueFilial(buscaFilial(buscaSupermercado(nome_sup), nome_fil)));
      
    }
    else if(op == 6){

        printf("Insira o nome do supermercado:");
        char *nome_sup = leLinha();
        
        printf("%.2f\n", estoqueSupermercado(buscaSupermercado(nome_sup)));
    
    }
    else if(op == 7){
        printf("\n----------------------\n");
        for(int i=0; i<qnt_sup; i++){
            printf("Nome: %s,Estoque Total: %.2f\n",sup[i].nome, sup[i].est_total);
            for(int j=0; j<sup[i].qnt_filiais; j++){
                imprimeFilial(sup[i].filiais[j]);
            }
            printf("\n----------------------\n");
        }
    }
    else if(op == 8){
        break;
    }
    else{
        printf("Valor invalido!\n");
    }
     
    }
}

char *leLinha(){

    char temp[100];
    scanf("%99[^\n]", temp);
    char *str = strdup(temp);
    return str;

}
