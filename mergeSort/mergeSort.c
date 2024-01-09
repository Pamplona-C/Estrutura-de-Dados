#include <stdio.h>
#include <stdlib.h>

void mergeSort(int lista[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;

     
        mergeSort(lista, esq, meio);
        mergeSort(lista, meio + 1, dir);

  
        merge(lista, esq, meio, dir);
    }
}

void merge(int lista[], int esq, int meio, int dir) {
    int tamanho_esq = meio - esq + 1;
    int tamanho_dir = dir - meio;

    int lista_esq[tamanho_esq];
    int lista_dir[tamanho_dir];


    for (int i = 0; i < tamanho_esq; i++) {
        lista_esq[i] = lista[esq + i];
    }
    for (int j = 0; j < tamanho_dir; j++) {
        lista_dir[j] = lista[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = esq;

 
    while (i < tamanho_esq && j < tamanho_dir) {
        if (lista_esq[i] <= lista_dir[j]) {
            lista[k] = lista_esq[i];
            i++;
        } else {
            lista[k] = lista_dir[j];
            j++;
        }
        k++;
    }

    
    while (i < tamanho_esq) {
        lista[k] = lista_esq[i];
        i++;
        k++;
    }

 
    while (j < tamanho_dir) {
        lista[k] = lista_dir[j];
        j++;
        k++;
    }
}

int main() {
    int lista[] = {20, 10, 5, 80, 95, 100, 25, 1};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    printf("Array antes da ordenacao:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    mergeSort(lista, 0, tamanho - 1);

    printf("Array depois da ordenacao:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    return 0;
}
