#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do processo
typedef struct Processo {
    int id;
    int tempoEspera;
    struct Processo *proximo;
} Processo;

// Função para inserir um novo processo na fila
void inserirProcesso(Processo **fila, int id, int tempoEspera) {
    Processo *novoProcesso = (Processo *)malloc(sizeof(Processo));
    if (novoProcesso != NULL) {
        novoProcesso->id = id;
        novoProcesso->tempoEspera = tempoEspera;
        novoProcesso->proximo = NULL;

        if (*fila == NULL) {
            *fila = novoProcesso;
        } else {
            Processo *atual = *fila;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novoProcesso;
        }
    } else {
        printf("Erro de alocação de memória!\n");
    }
}

// Função para remover o processo com o maior tempo de espera da fila
void removerMaiorTempoEspera(Processo **fila) {
    if (*fila != NULL) {
        Processo *maiorTempoEspera = *fila;
        Processo *anterior = NULL;
        Processo *atual = *fila;
        
        while (atual->proximo != NULL) {
            if (atual->proximo->tempoEspera > maiorTempoEspera->tempoEspera) {
                maiorTempoEspera = atual->proximo;
                anterior = atual;
            }
            atual = atual->proximo;
        }

        if (anterior != NULL) {
            anterior->proximo = maiorTempoEspera->proximo;
        } else {
            *fila = maiorTempoEspera->proximo;
        }

        free(maiorTempoEspera);
    } else {
        printf("A fila está vazia!\n");
    }
}

// Função para imprimir a fila de processos
void imprimirFila(Processo *fila) {
    printf("Fila de processos:\n");
    Processo *atual = fila;
    while (atual != NULL) {
        printf("ID: %d, Tempo de Espera: %d\n", atual->id, atual->tempoEspera);
        atual = atual->proximo;
    }
}

int main() {
    Processo *fila = NULL;

    inserirProcesso(&fila, 1, 5);
    inserirProcesso(&fila, 2, 8);
    inserirProcesso(&fila, 3, 3);

    imprimirFila(fila);

    removerMaiorTempoEspera(&fila);

    printf("\nApós remover o processo com maior tempo de espera:\n");
    imprimirFila(fila);

    return 0;
}
