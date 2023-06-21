#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

//Dada uma sequencia de números não nulos, imprimir seu quadrado.

int main(){
    int num[5],i = 0;

    printf("Digite uma sequencia de numeros nao nulos : \n");
    while (i < 5)
    {
        scanf("%d",&num[i]);
        if (num[i] == 0)
        {
            printf("ERRO - O numero digitado e um numero nulo ! Digite Novamente .\n");
            continue;
        }
        
        i++;
    }
    
    return 0;
}