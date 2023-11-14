#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int codigo;
    float valor;
} Produto;

typedef struct {
    Produto produto[10];
} Vetor;

int buscarProdutoPorCodigo(Vetor *vetor, int codigo) {
    for (int i = 0; i < 10; ++i) {
        if (vetor->produto[i].codigo == codigo) {
            return i; 
        }
    }
    return -1;
}

int main() {
    Vetor vetor;
    int opcao;

    while(1){


        printf("-----CADASTRO DE PRODUTOS-----\n");
        printf("\n");
        printf("1 - CADASTRAR PRODUTO\n");
        printf("2 - BUSCAR SEQUENCIAL DE PRODUTO\n");
        printf("3 - SAIR\n");

        scanf("%d", &opcao);

        switch(opcao) {
            case 1:

                int posicao = 0;
                    while (posicao < 10 && vetor.produto[posicao].codigo != 0) {
                    posicao++;
                }

                printf("Digite as informações do produto:\n");
                printf("Nome: \n");
                scanf("%s", vetor.produto[posicao].nome); 
                printf("Codigo: \n");
                scanf("%d",&vetor.produto[posicao].codigo);
                printf("Valor: \n");
                scanf("%f", &vetor.produto[posicao].valor);
                break;
            
            case 2:
                printf("Digite o código do produto: ");
                int codigoBusca;
                scanf("%d", &codigoBusca);

                int posicaoEncontrada = buscarProdutoPorCodigo(&vetor, codigoBusca);
                if (posicaoEncontrada != -1) {
                    printf("Produto encontrado:\n");
                    printf("Nome: %s\n", vetor.produto[posicaoEncontrada].nome);
                    printf("Codigo: %d\n", vetor.produto[posicaoEncontrada].codigo);
                    printf("Valor: %.2f\n", vetor.produto[posicaoEncontrada].valor);
                } else {
                    printf("Produto não encontrado.\n");
                }
                break;

            case 3:
                return 0;

            default:
               printf("Opção inválida.\n");
        }

    }
    

    return 0;
}
