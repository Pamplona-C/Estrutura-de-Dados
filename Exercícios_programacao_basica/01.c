#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>

//Dada uma sequencia de números não nulos, imprimir seu quadrado.

int main(){
    int num[5],i = 0;

    printf("Digite 5 numeros nao nulos : \n");
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

    system("cls");

     printf("Os numeros digitados foram : ");
    for ( i = 0; i < 5; i++)
    {
        printf(" %d ",num[i]);
    }

    printf("\n");

    int result[5];

    for ( i = 0; i < 5; i++)
    {
        result[i] = num[i] * num[i];
    }
    
    printf("Os valores elevados ao quadrado : ");
    for ( i = 0; i < 5; i++)
    {
        printf("%d, ",result[i]);
    }
    
    
    
    
    return 0;
}