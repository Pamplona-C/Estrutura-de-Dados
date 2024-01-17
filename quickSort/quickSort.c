#include <stdio.h>
#include <stdlib.h>

void swap(int lista[], int i, int j) {
    int temp = lista[i];
    lista[i] = lista[j];
    lista[j] = temp;
}


int partition(int lista[], int left, int right) {

    int pivot = lista[left];
    int i = left;

    for (int j = left + 1; j <= right; j++) {
        if (lista[j] <= pivot) {
            i++;
            swap(lista, i, j);
        }
    }
    swap(lista, left, i);
    
    return i;
}



void quickSort(int lista[], int left, int right) {
    if (left < right) {
        int index_pivot = partition(lista, left, right);
        quickSort(lista, left, index_pivot - 1);
        quickSort(lista, index_pivot + 1, right);
    }
}

void imprimirLista(int lista[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int lista[] = {3, 8, 7, 10, 23, 2, 1, 77, 8};

    int tam = sizeof(lista) / sizeof(lista[0]);

    quickSort(lista, 0, tam - 1);

    imprimirLista(lista, tam);

    return 0;
}
