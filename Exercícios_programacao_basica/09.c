#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>

//Escreva um algoritmo para ler o nome e a idade de uma pessoa, e exibir quantos dias de vida ela possui. Considere sempre anos completos, e que um ano possui 365 dias. Ex: uma pessoa com 19 anos possui 6935 dias de vida; veja um exemplo de saída: MARIA, VOCÊ JÁ VIVEU 6935 DIAS.

typedef struct {
    char nome[50];
    int idade;
}ficha;

void calc_dias(ficha pessoa){
    int year = 365;
    int dias = pessoa.idade * year;

    printf("%s voce ja viveu %d dias.\n",pessoa.nome,dias);
}


int main(){

    system("clear");

    ficha pessoa;
    
    printf("Digite seu nome : ");
    scanf("%s",&pessoa.nome);
    printf("\n");
    printf("DIgite sua idade : ");
    scanf("%d",&pessoa.idade);

    calc_dias(pessoa);

    return 0;
}