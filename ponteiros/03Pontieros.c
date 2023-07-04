#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*3) Desenvolva um programa em C que leia seis números e os armazene em um vetor.
Esse programa deve conter ponteiros para manusear o vetor e imprimir seus valores.
O programa deve apresentar também o endereço de memória desses números.*/

int main(){

    int num[6];
    int *p = num;

    setlocale(LC_ALL, "Portuguese");
    printf("Digite 6 números : \n");

    for (int i = 0; i < 6; i++)
    {
        scanf("%d",&p[i]);
    }

    system("clear");

    for (int i = 0; i < 6; i++)
    {
        printf("O número %d está no endereço %p\n",p[i],&p[i]);
    }

    return 0;
}