#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[50];
    int id;
} Aviao;

typedef struct {
    Aviao dados[10];
    int inicio;
    int fim;
    int quantidade;
} Fila;

void inicializaFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->quantidade = 0;
}

int filaVazia(Fila *fila) {
    return fila->quantidade == 0;
}

int filaCheia(Fila *fila) {
    return fila->quantidade == 10;
}

void enfileira(Fila *fila, Aviao aviao) {
    if (!filaCheia(fila)) {
        fila->fim = (fila->fim + 1) % 10;
        fila->dados[fila->fim] = aviao;
        fila->quantidade++;
        printf("Um novo avião entrou na Fila de espera !.\n");
    } else {
        printf("A fila de espera está cheia!\n");
    }
}

Aviao desenfileira(Fila *fila) {
    Aviao aviaoVazio = { "", -1 };
    
    if (!filaVazia(fila)) {
        Aviao aviao = fila->dados[fila->inicio];
        fila->inicio = (fila->inicio + 1) % 10;
        fila->quantidade--;
        return aviao;
    }
    
    printf("A fila de espera está vazia!\n");
    return aviaoVazio;
}

void listaAvioesEspera(Fila *fila) {
    printf("Número de aviões aguardando na fila: %d\n", fila->quantidade);
}

void autorizaDecolagem(Fila *fila) {
    if (!filaVazia(fila)) {
        Aviao aviao = desenfileira(fila);
        printf("Autorizando a decolagem do avião %s (ID: %d)\n", aviao.nome, aviao.id);
    } else {
        printf("A fila de espera está vazia. Nenhum avião para decolagem.\n");
    }
}

void listaTodosAvioes(Fila *fila) {
    if (!filaVazia(fila)) {
        printf("Aviões na fila de espera:\n");
        int i = fila->inicio;
        int contador = 1;
        
        while (contador <= fila->quantidade) {
            printf("%d. %s (ID: %d)\n", contador, fila->dados[i].nome, fila->dados[i].id);
            i = (i + 1) % 10;
            contador++;
        }
    } else {
        printf("A fila de espera está vazia!\n");
    }
}

void listaPrimeiroAviao(Fila *fila) {
    if (!filaVazia(fila)) {
        Aviao aviao = fila->dados[fila->inicio];
        printf("Primeiro avião na fila de espera:\n");
        printf("Nome: %s\nID: %d\n", aviao.nome, aviao.id);
    } else {
        printf("A fila de espera está vazia!\n");
    }
}

void inverterFila(Fila *fila) {
    if (!filaVazia(fila)) {
        Aviao avioes[10];
        int i = fila->inicio;
        int contador = 0;

        while (contador < fila->quantidade) {
            avioes[contador] = fila->dados[i];
            i = (i + 1) % 10;
            contador++;
        }

        i = fila->inicio;
        for (int j = contador - 1; j >= 0; j--) {
            fila->dados[i] = avioes[j];
            i = (i + 1) % 10;
        }

        printf("Fila invertida!\n");
    } else {
        printf("A fila de espera está vazia!\n");
    }
}




int main() {
    system("cls");
    Fila filaAvioes;
    inicializaFila(&filaAvioes);

    while (1) {
        printf("\n*** Controle de Pista de Decolagem ***\n");
        printf("1. Listar o número de aviões aguardando na fila\n");
        printf("2. Autorizar a decolagem do primeiro avião da fila\n");
        printf("3. Adicionar um avião à fila de espera\n");
        printf("4. Listar todos os aviões na fila de espera\n");
        printf("5. Listar as características do primeiro avião da fila\n");
        printf("7. Inverter Fila.\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        
        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                listaAvioesEspera(&filaAvioes);
                break;
            case 2:
                autorizaDecolagem(&filaAvioes);
                break;
            case 3:
                if (!filaCheia(&filaAvioes)) {
                    Aviao novoAviao;
                    printf("Digite o nome do avião: ");
                    scanf("%s", novoAviao.nome);
                    printf("Digite o ID do avião: ");
                    scanf("%d", &novoAviao.id);
                    enfileira(&filaAvioes, novoAviao);
                } else {
                    printf("A fila de espera está cheia!\n");
                }
                break;
            case 4:
                listaTodosAvioes(&filaAvioes);
                break;
            case 5:
                listaPrimeiroAviao(&filaAvioes);
                break;
            case 6:
                printf("Encerrando o programa.\n");
                exit(0);
            case 7:
                inverterFila(&filaAvioes);
                break;  
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
