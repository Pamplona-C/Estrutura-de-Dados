#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>

//Dado um número inteiro positivo n, imprimir os n primeiros naturais ímpares.

int main(){

    int num;

    printf("Digite um numero inteiro positivo : ");
    scanf("%d",&num);

    printf("Esses sao os numeros naturais impares ate %d : ",num);

    for ( int i = 0; i <= num; i++)
    {
        if (i % 2 != 0)
        {
            printf("%d, ",i);
        }
        
    }
    

    return 0;
}