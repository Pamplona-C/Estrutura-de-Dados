#include <stdio.h>
#include <stdlib.h>
#define ANO = 365

//Entrar com o dia e o mês de uma data e informar quantos dias se passaram desde o início do ano.Esqueça a questão dos anos bissextos e considere sempre que um mẽs possui 30 dias.

typedef struct{
    int dia;
    int mes;
}data;

void calcula_dias(data data){
    //int dias = 0;
    int meses = 30 * (data.mes - 1);
    int dias = meses + data.dia;
    printf("Se passaram %d dias desde o inicio do ano.",dias);
}

int main(){

    system("cls");

    data data;

    printf("Digite o dia e o mes :\n");
    printf("Dia = ");
    scanf("%d",&data.dia);
    printf("Mes = ");
    scanf("%d",&data.mes);
    calcula_dias(data);


    return 0;
}