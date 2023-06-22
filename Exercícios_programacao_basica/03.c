#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>

//Dado um número inteiro positivo n, calcular a soma dos n primeiros números inteiros positivos.

int main(){

    int num = 0,soma = 0;
    
    while (num == 0)
    {
        printf("Digite um numero inteiro positivo : ");
        scanf("%d",&num);
        
    }

    for (int i = 0; i <= num; i++)
    {
        soma = soma + i;
    }

    printf("A soma dos numeros inteiros positivos ate %d = %d",num,soma);

    return 0;
}