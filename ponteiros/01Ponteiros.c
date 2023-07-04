#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void calc_soma(int *a, int *b){
    int soma = *a + *b;
    printf("\nA soma é %d\n",soma);
}

void calc_sub(int *a, int *b){
    int sub = *a-*b;
    printf("A subtração é %d\n",sub);
}

void calc_mult(int *a, int *b){
    int mult = *a * *b;
    printf("A multiplicação é %d\n",mult);
}

void calc_div(int *a, int *b){
    double div = (double) *a / *b;
    printf("A divisão é %.2lf\n",div);
}


int main(){

    system("clear");

    setlocale(LC_ALL, "Portuguese");

    int p1,p2;

    int *n1 = &p1,*n2 = &p2;

    printf("Digite dois números para ser calculado as operações básicas : \n");
    scanf("%d",&*n1);
    scanf("%d",&*n2);

    calc_soma(&p1,&p2);
    calc_sub(&p1,&p2);
    calc_mult(&p1,&p2);
    calc_div(&p1,&p2);

    return 0;
}