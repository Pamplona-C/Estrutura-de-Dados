#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void swap(int lista[], int i, int j){
    int temp = lista[i];
    lista[i] = lista[j];
    lista[j]= temp;
}

int partition(int lista[],int left, int right){

    int range = right - left +1 ;
    int rand_pivot_index = (rand() % range) + left;
    
    swap(lista, left, rand_pivot_index);

    int pivot = lista[left];
    int i = left;

    for (int j = left + 1; j <= right; j++)
    {
        if (lista[j] <= pivot)
        {
            i++;
            swap(lista,i,j);
            
        }
    }
    swap(lista, left, i);
    
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

    srand(time(NULL));
    
    int lista[] = {96,85,73,45,32,10,1};

    int tam = sizeof(lista) / sizeof(lista[0]);

    printf("Tamanho do vetor : %d\n",tam);

    printf("Lista antes da Ordenação :");
    imprimirLista(lista,tam);

    printf("\n");


    quickSort(lista, 0, tam - 1);


    printf("Lista Ordenada :");
    imprimirLista(lista,tam);

    printf("\n");

    return 0;
}