#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int lista[], int i, int j){
    int temp = lista[i];
    lista[i] = lista[j];
    lista[j]= temp;
}

int numeroAleatorio(int vetor[], int tamanho){
    if (tamanho <= 0)
    {
        printf("ERRO - VETOR VAZIO");
        return (EXIT_FAILURE);
    }
    srand(time(NULL));

    int indiceAleatorio = rand() % tamanho;

    return vetor[indiceAleatorio];
}

int partition(int lista[],int left, int right){

    int indiceAleatorio = left + rand() % (right - left + 1);

    int pivot = lista[indiceAleatorio];
    

    int i = left;
    

    for (int j = left; j <= right; j++)
    {
        if (lista[j] <= pivot)
        {
            swap(lista,i,j);
            i++;
        }
    }
    
    return i;
}

void quickSort(int lista[], int left, int right){
    if (left < right)
    {
        int index_pivot = partition(lista, left, right);
        quickSort(lista, left, index_pivot-1);
        quickSort(lista, index_pivot+1, right);
    }
    
}

void imprimirLista(int lista[], int tam){
    for (int i = 0; i < tam; i++)
    {
        printf("%d  ",lista[i]);
    }
    printf("\n");
    
}

int main(){
    int lista[] = {1,2,3,4,5,10,96,5};

    int tam = sizeof(lista) / sizeof(lista[0]);

    printf("Lista antes da Ordenação :");
    imprimirLista(lista,tam);

    quickSort(lista,0,tam);

    printf("Lista Ordenada :");
    imprimirLista(lista,tam);

    return 0;
}