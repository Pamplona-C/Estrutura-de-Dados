#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int codigo;
    char nome[50];
    char laboratorio[50];
    float preco;
} Medicamento;


typedef struct {
    Medicamento medicamentos[10];
    int quantidade;
} Farmacia;


void cadastrarMedicamento(Farmacia *farmacia) {
    if (farmacia->quantidade < 10) {
        printf("Digite o código do medicamento: ");
        scanf("%d", &farmacia->medicamentos[farmacia->quantidade].codigo);
        printf("Digite o nome do medicamento: ");
        scanf("%s", farmacia->medicamentos[farmacia->quantidade].nome);
        printf("Digite o laboratório do medicamento: ");
        scanf("%s", farmacia->medicamentos[farmacia->quantidade].laboratorio);
        printf("Digite o preço do medicamento: ");
        scanf("%f", &farmacia->medicamentos[farmacia->quantidade].preco);

        farmacia->quantidade++;

        printf("Medicamento cadastrado com sucesso!\n");
    } else {
        printf("Limite de medicamentos atingido. Não é possível cadastrar mais.\n");
    }
}


void ordenarMedicamentos(Farmacia *farmacia) {
    for (int i = 0; i < farmacia->quantidade - 1; i++) {
        for (int j = 0; j < farmacia->quantidade - i - 1; j++) {
            if (farmacia->medicamentos[j].codigo > farmacia->medicamentos[j + 1].codigo) {
               
                Medicamento temp = farmacia->medicamentos[j];
                farmacia->medicamentos[j] = farmacia->medicamentos[j + 1];
                farmacia->medicamentos[j + 1] = temp;
            }
        }
    }
}


void buscarMedicamentoSequencial(Farmacia *farmacia, const char *nome) {
    for (int i = 0; i < farmacia->quantidade; i++) {
        if (strcmp(farmacia->medicamentos[i].nome, nome) == 0) {
            printf("Medicamento encontrado:\n");
            printf("Código: %d\n", farmacia->medicamentos[i].codigo);
            printf("Nome: %s\n", farmacia->medicamentos[i].nome);
            printf("Laboratório: %s\n", farmacia->medicamentos[i].laboratorio);
            printf("Preço: %.2f\n", farmacia->medicamentos[i].preco);
            return;
        }
    }

    printf("Medicamento não encontrado.\n");
}


void buscarMedicamentoBinaria(Farmacia *farmacia, int codigo) {
    int inicio = 0;
    int fim = farmacia->quantidade - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (farmacia->medicamentos[meio].codigo == codigo) {
            printf("Medicamento encontrado:\n");
            printf("Código: %d\n", farmacia->medicamentos[meio].codigo);
            printf("Nome: %s\n", farmacia->medicamentos[meio].nome);
            printf("Laboratório: %s\n", farmacia->medicamentos[meio].laboratorio);
            printf("Preço: %.2f\n", farmacia->medicamentos[meio].preco);
            return;
        } else if (farmacia->medicamentos[meio].codigo < codigo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    printf("Medicamento não encontrado.\n");
}

int main() {
    Farmacia farmacia;
    farmacia.quantidade = 0; 

    int opcao;

    while (1) {
        printf("-----FARMÁCIA-----\n");
        printf("1 - Cadastrar Medicamento\n");
        printf("2 - Buscar Medicamento (Sequencial)\n");
        printf("3 - Buscar Medicamento (Binária)\n");
        printf("4 - Sair\n");

        printf("Escolha a opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarMedicamento(&farmacia);
                ordenarMedicamentos(&farmacia);
                break;
            case 2:
                printf("Digite o nome do medicamento: ");
                char nomeBusca[50];
                scanf("%s", nomeBusca);
                buscarMedicamentoSequencial(&farmacia, nomeBusca);
                break;
            case 3:
                printf("Digite o código do medicamento: ");
                int codigoBusca;
                scanf("%d", &codigoBusca);
                buscarMedicamentoBinaria(&farmacia, codigoBusca);
                break;
            case 4:
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}
