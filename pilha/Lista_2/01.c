/*Digamos que nosso alfabeto contém apenas as letras a, b e c. Qualquer string desse
conjunto tem a forma WcM, onde W é uma sequência das letras ab, e M é o inverso de
W. Por exemplo: aabababcbababaa. Escreva um programa que decida se uma
determinada string pertence ou não a forma WcM. Utilize uma estrutura de pilha para
resolver o problema.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{
    char string[50];
}frasePilha;

int topo = -1;
int topo2 = -1;
void incrementa_pilha(frasePilha f[50], int topo, char frase[50]){
    topo++;
    for (int i = 0; i <= strlen(frase); i++)
    {
        f[topo].string[i] = frase[i];
    }
    printf("%s",f);
}

int main(){

    system("clear");
    frasePilha f[50],f2[50];

    char frase[50];

    fgets(frase,50,stdin);

    //printf("O tamanho do vetor é %d\n",strlen(frase));
    //printf("%s",frase);

    incrementa_pilha(f, topo,frase);
    trocarPilha(f,f2);

    return 0;
}