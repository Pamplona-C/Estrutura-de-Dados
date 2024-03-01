#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct {
    int chave;
    char cpf[12];
    char nome[50];
    char info[100];
} Registro;

typedef struct {
    Registro *registro;
    struct NodoHash *proximo;
} NodoHash;

int calcularHash(int chave) {
    return chave % TABLE_SIZE;
}

void inserirRegistro(NodoHash *tabelaHash[], Registro *registro) {
    int hash = calcularHash(registro->chave);

    NodoHash *novoNodo = malloc(sizeof(NodoHash));
    novoNodo->registro = registro;
    novoNodo->proximo = tabelaHash[hash];
    tabelaHash[hash] = novoNodo;

    FILE *arquivo = fopen("registros.txt", "a");
    fprintf(arquivo, "Chave: %d | CPF: %s | Nome: %s | Info: %s\n", registro->chave, registro->cpf, registro->nome, registro->info);
    fclose(arquivo);
}

Registro *buscarRegistro(NodoHash *tabelaHash[], int chave) {
    int hash = calcularHash(chave);
    NodoHash *atual = tabelaHash[hash];

    while (atual != NULL) {
        if (atual->registro->chave == chave) {
            return atual->registro;
        }
        atual = atual->proximo;
    }

    return NULL;
}

int main() {
    NodoHash *tabelaHash[TABLE_SIZE] = {NULL};

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar Registro\n");
        printf("2 - Buscar Registro\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                {
                    Registro *novoRegistro = malloc(sizeof(Registro));

                    printf("Chave: ");
                    scanf("%d", &novoRegistro->chave);

                    printf("CPF: ");
                    scanf("%s", novoRegistro->cpf);

                    printf("Nome: ");
                    scanf(" %[^\n]s", novoRegistro->nome);  // Lê espaços em branco também

                    printf("Informacoes: ");
                    scanf(" %[^\n]s", novoRegistro->info);  // Lê espaços em branco também

                    inserirRegistro(tabelaHash, novoRegistro);

                    printf("Registro cadastrado com sucesso!\n");
                }
                break;
            case 2:
                {
                    int chave;
                    printf("Digite a chave do registro a ser buscado: ");
                    scanf("%d", &chave);

                    Registro *encontrado = buscarRegistro(tabelaHash, chave);

                    if (encontrado != NULL) {
                        printf("\nRegistro Encontrado:\n");
                        printf("Chave: %d\n", encontrado->chave);
                        printf("CPF: %s\n", encontrado->cpf);
                        printf("Nome: %s\n", encontrado->nome);
                        printf("Informacoes: %s\n", encontrado->info);
                    } else {
                        printf("\nRegistro nao encontrado.\n");
                    }
                }
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    for (int i = 0; i < TABLE_SIZE; i++) {
        NodoHash *atual = tabelaHash[i];
        while (atual != NULL) {
            NodoHash *proximo = atual->proximo;
            free(atual->registro);
            free(atual);
            atual = proximo;
        }
    }

    return 0;
}
