#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*5) Faça um programa em C que receba uma frase qualquer fornecida pelo usuário,
que calcule e mostre quantos caracteres essa frase possui. Esse programa deve conter
ponteiros para manusear a string. A frase deve possuir no máximo 50 caracteres.*/

int main(){

    char frase[50];
    char *p = &frase;

    printf("Digite uma frase : \n");
    fgets(frase, 50, stdin);

    printf("%s",frase);


    return 0;
}