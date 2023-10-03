#include <stdio.h>
#include <stdlib.h>

struct Noh {
    int valor;
    struct Noh* proximo;
};

typedef struct Noh Noh;

Noh* criaNoh(int valor) {
    Noh* novoNoh = (Noh*)malloc(sizeof(Noh));
    novoNoh->valor = valor;
    novoNoh->proximo = NULL;
    return novoNoh;
}

void insereInicio(Noh** head, int valor) {
    Noh* novoNoh = criaNoh(valor);
    novoNoh->proximo = *head;
    *head = novoNoh;
}

void printList(Noh* head) {
    Noh* atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

Noh* inverteLista(Noh* head) {
    Noh* prev = NULL;
    Noh* atual = head;
    Noh* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = prev;
        prev = atual;
        atual = proximo;
    }

    return prev;
}

int main() {
    Noh* lista = NULL;

    int escolha, valor;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no final\n");
        printf("3. Inverter a lista\n");
        printf("4. Visualizar lista\n");
        printf("5. Sair\n");
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
                insereInicio(&lista, valor);
                break;
            case 3:
                lista = inverteLista(lista);
                break;
            case 4:
                printf("Lista Encadeada: ");
                printList(lista);
                break;
            case 5:
                // Libera a memória alocada para os nós
                while (lista != NULL) {
                    Noh* temp = lista;
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
