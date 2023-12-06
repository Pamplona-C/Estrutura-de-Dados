#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


int removerDuplicatas(int vetor[], int tamanho) {
    if (tamanho == 0 || tamanho == 1)
        return tamanho;

    int *temp = (int *)malloc(tamanho * sizeof(int));
    int i, j = 0;

    qsort(vetor, tamanho, sizeof(int), comparar);

    for (i = 0; i < tamanho - 1; i++) {
        if (vetor[i] != vetor[i + 1]) {
            temp[j++] = vetor[i];
        }
    }

    temp[j++] = vetor[tamanho - 1];

    for (i = 0; i < j; i++) {
        vetor[i] = temp[i];
    }

    free(temp);

    return j;
}


bool buscarBinaria(int vetor[], int tamanho, int chave) {
    int inicio = 0, fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == chave) {
            return true; 
        }

        if (vetor[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return false;
}

int main() {
    int vetor[500];

    for (int i = 0; i < 500; i++) {
        vetor[i] = rand();
    }

    int tamanhoSemDuplicatas = removerDuplicatas(vetor, 500);


    qsort(vetor, tamanhoSemDuplicatas, sizeof(int), comparar);


    int chave;
    printf("Digite um valor para buscar: ");
    scanf("%d", &chave);

    if (buscarBinaria(vetor, tamanhoSemDuplicatas, chave)) {
        printf("Valor encontrado!\n");
    } else {
        printf("Valor não encontrado.\n");
    }

    return 0;
}
