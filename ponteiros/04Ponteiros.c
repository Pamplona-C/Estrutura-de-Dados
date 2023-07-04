#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*4) Desenvolva um programa em C que leia quatro números e armazene-os em um
vetor. Esse programa deve conter ponteiros para manusear o vetor e imprimir os seus
valores. Esse programa deve conter ponteiros também para apresentar o maior e o
menor número do vetor.*/

void maior_menor(int *p){

    int maior = 0, menor;

    for (int i = 0; i < 4; i++)
    {
        if (p[i] > maior)
        {
            maior = p[i];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (p[i] < menor)
        {
            menor = p[i];
        }
        
    }
    printf("O maior número é %d",maior);
    printf("\nO menor número é %d.",menor);
    
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int num[4];
    int *p = num;

    printf("Digite 4 números : \n");

    for (int i = 0; i < 4; i++)
    {
        scanf("%d\n",&p[i]);
    }

    system("clear");
    
    for (int i = 0; i < 4; i++)
    {
        printf("O valor %d esta armazenado na posição %p.\n",p[i],&p[i]);
    }

    maior_menor(num);
    

    return 0;
}