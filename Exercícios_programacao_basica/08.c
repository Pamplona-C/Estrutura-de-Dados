#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>


//Escreva um algoritmo que solicite ao usuário a entrada de 5 números, e que exiba o somatório desses números na tela. Após exibir a soma, o programa deve mostrar também os números que o usuário digitou, um por linha.

int main(){

    int num[5];
    int soma = 0;

    printf("Digite 5 números : \n");

    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&num[i]);
        soma = soma + num[i];
    }

    system("clear");

    printf("\nA soma de todos os numeros inseridos = %d\n",soma);

    printf("Os numeros inseridos foram : \n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n",num[i]);
    }
    
    

    return 0;
}