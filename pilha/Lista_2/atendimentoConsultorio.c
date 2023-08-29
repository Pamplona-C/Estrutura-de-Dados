#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
} Paciente;

typedef struct {
    Paciente dados[10];
    int inicio;
    int fim;
    int quantidade;
} FilaEspera;

void inicializaFila(FilaEspera *fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->quantidade = 0;
}

int filaVazia(FilaEspera *fila) {
    return fila->quantidade == 0;
}

int filaCheia(FilaEspera *fila) {
    return fila->quantidade == 01;
}

void enfileira(FilaEspera *fila, Paciente paciente) {
    if (!filaCheia(fila)) {
        fila->fim = (fila->fim + 1) % 10;
        fila->dados[fila->fim] = paciente;
        fila->quantidade++;
    } else {
        printf("A fila de espera está cheia!\n");
    }
}

Paciente desenfileira(FilaEspera *fila) {
    Paciente pacienteVazio = { "", -1 };
    
    if (!filaVazia(fila)) {
        Paciente paciente = fila->dados[fila->inicio];
        fila->inicio = (fila->inicio + 1) % 10;
        fila->quantidade--;
        return paciente;
    }
    
    printf("A fila de espera está vazia!\n");
    return pacienteVazio;
}

void chamaProximoPaciente(FilaEspera *fila) {
    if (!filaVazia(fila)) {
        Paciente paciente = desenfileira(fila);
        printf("Chamando paciente: %s (Idade: %d)\n", paciente.nome, paciente.idade);
    } else {
        printf("A fila de espera está vazia. Nenhum paciente para chamar.\n");
    }
}

int proximoPaciente(FilaEspera *fila) {
    if (!filaVazia(fila)) {
        return fila->dados[fila->inicio].idade;
    }
    return -1; // Retorna -1 se a fila estiver vazia
}

int pacientesNaFila(FilaEspera *fila) {
    return fila->quantidade;
}

void atendimentoPrioritario(FilaEspera *fila) {
    for (int i = 0; i < fila->quantidade - 1; i++) {
        for (int j = 0; j < fila->quantidade - i - 1; j++) {
            if (fila->dados[j].idade < fila->dados[j + 1].idade) {
                Paciente temp = fila->dados[j];
                fila->dados[j] = fila->dados[j + 1];
                fila->dados[j + 1] = temp;
            }
        }
    }
}

int main() {
    FilaEspera filaAtendimento;
    inicializaFila(&filaAtendimento);

    while (1) {
        printf("\n*** Gerenciamento de Atendimento ***\n");
        printf("1. Inserir paciente na fila de espera\n");
        printf("2. Chamar próximo paciente para atendimento\n");
        printf("3. Verificar se a fila de espera está cheia ou vazia\n");
        printf("4. Verificar a idade do próximo paciente a ser atendido\n");
        printf("5. Informar quantos pacientes existem na fila de espera\n");
        printf("6. Realizar atendimento prioritário\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        
        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (!filaCheia(&filaAtendimento)) {
                    Paciente novoPaciente;
                    printf("Digite o nome do paciente: ");
                    scanf("%s", novoPaciente.nome);
                    printf("Digite a idade do paciente: ");
                    scanf("%d", &novoPaciente.idade);
                    enfileira(&filaAtendimento, novoPaciente);
                } else {
                    printf("A fila de espera está cheia!\n");
                }
                break;
            case 2:
                chamaProximoPaciente(&filaAtendimento);
                break;
            case 3:
                if (filaVazia(&filaAtendimento)) {
                    printf("A fila de espera está vazia.\n");
                } else if (filaCheia(&filaAtendimento)) {
                    printf("A fila de espera está cheia.\n");
                } else {
                    printf("A fila de espera não está cheia nem vazia.\n");
                }
                break;
            case 4:
                if (!filaVazia(&filaAtendimento)) {
                    int idadeProximo = proximoPaciente(&filaAtendimento);
                    printf("Idade do próximo paciente a ser atendido: %d\n", idadeProximo);
                } else {
                    printf("A fila de espera está vazia!\n");
                }
                break;
            case 5:
                printf("Número de pacientes na fila de espera: %d\n", pacientesNaFila(&filaAtendimento));
                break;
            case 6:
                atendimentoPrioritario(&filaAtendimento);
                printf("Realizado atendimento prioritário.\n");
                break;
            case 7:
                printf("Encerrando o programa.\n");
                exit(0);
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
