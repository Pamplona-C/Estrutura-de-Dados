#include <stdio.h>
#include <stdlib.h>

// Definir a estrutura de um nó da lista
typedef struct Noh {
    int valor;
    struct Noh* proximo;
} Noh;

typedef struct {
    Noh* inicio;
} Lista;


struct Noh* criaNoh(int valor) {
    struct Noh* novoNoh = (struct Noh*)malloc(sizeof(struct Noh));
    
    novoNoh->valor = valor;
    novoNoh->proximo = NULL;

    return novoNoh;
}

void insereFinal(struct Noh** head, int valor) {
    struct Noh* novoNOH = criaNoh(valor);

    if (*head == NULL) {
        *head = novoNOH;
    } else {
        struct Noh* atual = *head;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNOH;
    }
}

void insereInicio(struct Noh** head, int valor) {
    struct Noh* novoNOH = criaNoh(valor);
    novoNOH->proximo = *head;
    *head = novoNOH;
}

void printList(struct Noh* head) {
    struct Noh* atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}


int main() {
    struct Noh* lista = NULL;

    int escolha, valor;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no final\n");
        printf("3. Visualizar lista\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser inserido no início: ");
                scanf("%d", &valor);
                insereInicio(&lista, valor);
                break;
            case 2:
                printf("Digite o valor a ser inserido no final: ");
                scanf("%d", &valor);
                insereFinal(&lista, valor);
                break;
            case 3:
                printf("Lista Encadeada: ");
                printList(lista);
                break;
            case 4:
                // Libera a memória alocada para os nós
                while (lista != NULL) {
                    struct Noh* temp = lista;
                    lista = lista->proximo;
                    free(temp);
                }
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}