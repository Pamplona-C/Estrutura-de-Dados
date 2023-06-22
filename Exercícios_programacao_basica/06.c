#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>

//Dada a sequencia de n números, imprimi-la na ordem inversa à da leitura.


int main(){

    system("cls");

    int num[5];

    printf("Digite uma sequencia de 5 numeros : ");

    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&num[i]);
    }

    system("cls");

    printf("A sequencia de numeros :");

    for (int i = 0; i < 5; i++)
    {
        printf(" %d - ",num[i]);
        
    }


    printf("\nA sequencia na ordem inversa : ");

    for (int i = 4; i >= 0; i--)
    {
        printf(" %d - ",num[i]);
    }
    
    

    return 0;
}