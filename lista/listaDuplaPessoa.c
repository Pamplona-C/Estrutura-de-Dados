#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct {
    char nome[50];
    int cpf;
} Pessoa;

typedef struct Noh {
    Pessoa p;
    struct Noh* prox;
    struct Noh* ant;
} Noh;

struct Noh* criaNoh(char nome[], int cpf) {
    struct Noh* novoNoh = (struct Noh*)malloc(sizeof(struct Noh));

    if (novoNoh == NULL) {
        printf("Erro ao criar noh!\n");
        return NULL;
    } else {
        strcpy(novoNoh->p.nome, nome);
        novoNoh->p.cpf = cpf;
        novoNoh->prox = NULL;
        novoNoh->ant = NULL;
        return novoNoh;
    }
}

struct Noh* insereInicio(struct Noh* lista, char nome[], int cpf) {
    struct Noh* novoNOH = criaNoh(nome, cpf);
    novoNOH->prox = lista;
    
    if (lista != NULL) {
        lista->ant = novoNOH;
    }

    return novoNOH;
}

struct Noh* insereFim(struct Noh* lista, char nome[], int cpf) {
    struct Noh* novoNOH = criaNoh(nome,cpf);

    if (lista == NULL) {
        return novoNOH;
    }

    struct Noh* atual = lista;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novoNOH;
    novoNOH->ant = atual;

    return lista;
}

struct Noh* insereMeio(struct Noh* lista, char nome[], int cpf) {
    struct Noh* novoNOH = criaNoh(nome, cpf);

    if (lista == NULL) {
        return novoNOH;
    }

    if (lista->prox == NULL) {
        lista->prox = novoNOH;
        novoNOH->ant = lista;
    } else {
        novoNOH->prox = lista->prox;
        novoNOH->ant = lista;
        lista->prox->ant = novoNOH;
        lista->prox = novoNOH;
    }

    return lista;
}

struct Noh* removeMeio(struct Noh* lista) {
    if (lista == NULL) {
        return NULL;
    }

    if (lista->prox == NULL) {
        
        return lista;
    }

    struct Noh* meio = lista->prox;
    lista->prox = meio->prox;

    if (meio->prox != NULL) {
        meio->prox->ant = lista;
    }

    free(meio);
    return lista;
}

struct Noh* removeInicio(struct Noh* lista) {
    if (lista == NULL) {
        return NULL;
    }

    struct Noh* novoInicio = lista->prox;
    if (novoInicio != NULL) {
        novoInicio->ant = NULL;
    }
    
    free(lista);
    return novoInicio;
}

struct Noh* removeFim(struct Noh* lista) {
    if (lista == NULL) {
        return NULL;
    }

    struct Noh* atual = lista;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    if (atual->ant != NULL) {
        atual->ant->prox = NULL;
    } else {
        // Se o primeiro nó for o último, a lista ficará vazia.
        lista = NULL;
    }
    
    free(atual);
    return lista;
}

void imprimeLista(struct Noh* lista) {
    struct Noh* atual = lista;

    while (atual != NULL) {
        printf("Nome: %s, CPF: %d\n", atual->p.nome, atual->p.cpf);
        atual = atual->prox;
    }

    printf("\n");
}

int main() {
    struct Noh* lista = NULL;
    int opcao;
    char nome[50];
    long long int cpf;

    do {
        printf("Escolha uma operacao:\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Inserir no meio\n");
        printf("4 - Remover do inicio\n");
        printf("5 - Remover do fim\n");
        printf("6 - Remover do meio\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o Nome a ser inserido no inicio: ");
                scanf("%s", &nome);
                printf("Digite o CPF: ");
                scanf("%lld", &cpf);
                lista = insereInicio(lista, nome,cpf);
                break;
            case 2:
                printf("Digite o Nome a ser inserido no fim: ");
                scanf("%s", &nome);
                printf("Digite o CPF: ");
                scanf("%lld", &cpf);
                lista = insereFim(lista, nome, cpf);
                break;
            case 3:
                printf("Digite o Nome a ser inserido no meio: ");
                scanf("%s", &nome);
                printf("Digite o CPF: ");
                scanf("%lld", &cpf);
                lista = insereMeio(lista, nome, cpf);
                break;
            case 4:
                lista = removeInicio(lista);
                break;
            case 5:
                lista = removeFim(lista);
                break;
            case 6:
                lista = removeMeio(lista);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

        printf("Lista atual: \n");
        imprimeLista(lista);

    } while (opcao != 0);

    return 0;
}