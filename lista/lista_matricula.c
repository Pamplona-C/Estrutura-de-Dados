#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definir a estrutura de um nó da lista
typedef struct Aluno {
    char nome[50];
    int matricula;
    struct Aluno* proximo;
} Aluno;

typedef struct {
    Aluno* inicio;
} ListaAlunos;


Aluno* criaAluno(char nome[], int matricula) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    strcpy(novoAluno->nome, nome);
    novoAluno->matricula = matricula;
    novoAluno->proximo = NULL;
    return novoAluno;
}


void insereInicio(ListaAlunos* lista, char nome[], int matricula) {
    Aluno* novoAluno = criaAluno(nome, matricula);
    novoAluno->proximo = lista->inicio;
    lista->inicio = novoAluno;
}


void insereFim(ListaAlunos* lista, char nome[], int matricula) {
    Aluno* novoAluno = criaAluno(nome, matricula);
    
    if (lista->inicio == NULL) {
        lista->inicio = novoAluno;
    } else {
        Aluno* atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoAluno;
    }
}


void insereMeio(ListaAlunos* lista, char nome[], int matricula) {
    Aluno* novoAluno = criaAluno(nome, matricula);

    if (lista->inicio == NULL) {

        lista->inicio = novoAluno;
    } else {
        Aluno* primeiroAluno = lista->inicio;
        
        if (primeiroAluno->proximo == NULL) {

            primeiroAluno->proximo = novoAluno;
        } else {

            novoAluno->proximo = primeiroAluno->proximo;
            primeiroAluno->proximo = novoAluno;
        }
    }
}




void removeInicio(ListaAlunos* lista) {
    if (lista->inicio == NULL) {
        printf("A lista de alunos está vazia.\n");
        return;
    }
    
    Aluno* temp = lista->inicio;
    lista->inicio = temp->proximo;
    free(temp);
}




void removeFim(ListaAlunos* lista) {
    if (lista->inicio == NULL) {
        printf("A lista de alunos está vazia.\n");
        return;
    }
    
    if (lista->inicio->proximo == NULL) {

        free(lista->inicio);
        lista->inicio = NULL;
        return;
    }
    
    Aluno* anterior = NULL;
    Aluno* atual = lista->inicio;
    
    while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }
    
    anterior->proximo = NULL;
    free(atual);
}


void ordenaLista(ListaAlunos* lista) {
    if (lista->inicio == NULL || lista->inicio->proximo == NULL) {
        return;
    }

    Aluno* atual;
    Aluno* anterior;
    Aluno* chave;

    for (atual = lista->inicio; atual != NULL; atual = atual->proximo) {
        chave = atual;
        for (anterior = atual->proximo; anterior != NULL; anterior = anterior->proximo) {
            if (strcmp(chave->nome, anterior->nome) > 0) {
                chave = anterior;
            }
        }

        if (chave != atual) {
            char tempNome[50];
            int tempMatricula;

            strcpy(tempNome, atual->nome);
            tempMatricula = atual->matricula;

            strcpy(atual->nome, chave->nome);
            atual->matricula = chave->matricula;

            strcpy(chave->nome, tempNome);
            chave->matricula = tempMatricula;
        }
    }
}





void printListaAlunos(ListaAlunos* lista) {
    Aluno* atual = lista->inicio;
    printf("Lista de Alunos:\n");
    while (atual != NULL) {
        printf("Nome: %s, Matrícula: %d\n", atual->nome, atual->matricula);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    ListaAlunos lista;
    lista.inicio = NULL;

    int escolha;
    char nome[50];
    int matricula;

    insereInicio(&lista, "ana", 01);
    insereInicio(&lista, "bia", 02);
    insereInicio(&lista, "carlos", 03);
    insereInicio(&lista, "daniel", 04);


    while (1) {
        printf("Menu:\n");
        printf("1. Inserir aluno no início\n");
        printf("2. Inserir aluno no fim\n");
        printf("3. Inserir aluno no Meio\n");
        printf("4. Remover aluno do início\n");
        printf("5. Remover aluno do fim\n");
        printf("6. Visualizar lista de alunos\n");
        printf("7. Ordenar Lista\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o nome do aluno: ");
                scanf("%s", nome);
                printf("Digite a matrícula do aluno: ");
                scanf("%d", &matricula);
                insereInicio(&lista, nome, matricula);
                break;
            case 2:
                printf("Digite o nome do aluno: ");
                scanf("%s", nome);
                printf("Digite a matrícula do aluno: ");
                scanf("%d", &matricula);
                insereFim(&lista, nome, matricula);
                break;
            case 3:
                printf("Digite o nome do aluno: ");
                scanf("%s", nome);
                printf("Digite a matrícula do aluno: ");
                scanf("%d", &matricula);
                insereMeio(&lista, nome, matricula);
                break;
            case 4:
                removeInicio(&lista);
                break;
            case 5:
                removeFim(&lista);
                break;
            case 6:
                printListaAlunos(&lista);
                break;
            case 7:
                ordenaLista(&lista);
                break;
            case 8:

                while (lista.inicio != NULL) {
                    removeInicio(&lista);
                }
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
