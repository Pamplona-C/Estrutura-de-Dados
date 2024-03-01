#include <stdio.h>
#include <string.h>

#define MAX_ARQUIVOS 100

// Definição da estrutura de arquivo
typedef struct {
    int codigo;
    char tipo[50];
    char data[20];
    char texto[200];
} Arquivo;

// Função para inserir um novo arquivo
void inserirArquivo(Arquivo arquivos[], int *numArquivos) {
    if (*numArquivos < MAX_ARQUIVOS) {
        printf("Informe o código: ");
        scanf("%d", &arquivos[*numArquivos].codigo);

        printf("Informe o tipo: ");
        scanf("%s", arquivos[*numArquivos].tipo);

        printf("Informe a data: ");
        scanf("%s", arquivos[*numArquivos].data);

        printf("Informe o texto: ");
        scanf(" %[^\n]", arquivos[*numArquivos].texto);

        (*numArquivos)++;
        printf("Arquivo inserido com sucesso!\n");
    } else {
        printf("Não é possível adicionar mais arquivos. Limite atingido.\n");
    }
}

// Função para buscar arquivo por código usando busca sequencial
int buscarPorCodigoSequencial(const Arquivo arquivos[], int numArquivos, int codigo) {
    for (int i = 0; i < numArquivos; i++) {
        if (arquivos[i].codigo == codigo) {
            return i;  // Retorna o índice do arquivo encontrado
        }
    }
    return -1;  // Retorna -1 se não encontrar
}

// Função para buscar arquivo por tipo usando busca sequencial
void buscarPorTipoSequencial(const Arquivo arquivos[], int numArquivos, const char tipo[]) {
    int encontrados = 0;
    printf("Arquivos encontrados por tipo %s:\n", tipo);
    for (int i = 0; i < numArquivos; i++) {
        if (strcmp(arquivos[i].tipo, tipo) == 0) {
            printf("Código: %d, Tipo: %s, Data: %s, Texto: %s\n",
                   arquivos[i].codigo, arquivos[i].tipo, arquivos[i].data, arquivos[i].texto);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum arquivo encontrado para o tipo %s.\n", tipo);
    }
}

// Função para exibir todos os arquivos
void listarTodos(const Arquivo arquivos[], int numArquivos) {
    printf("Todos os arquivos:\n");
    for (int i = 0; i < numArquivos; i++) {
        printf("Código: %d, Tipo: %s, Data: %s, Texto: %s\n",
               arquivos[i].codigo, arquivos[i].tipo, arquivos[i].data, arquivos[i].texto);
    }
    if (numArquivos == 0) {
        printf("Nenhum arquivo encontrado.\n");
    }
}

int main() {
    Arquivo arquivos[MAX_ARQUIVOS];
    int numArquivos = 0;

    int opcao;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserir novo arquivo\n");
        printf("2. Buscar por código\n");
        printf("3. Buscar por tipo\n");
        printf("4. Listar todos os arquivos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirArquivo(arquivos, &numArquivos);
                break;
            case 2: {
                int codigo;
                printf("Informe o código para busca: ");
                scanf("%d", &codigo);
                int indice = buscarPorCodigoSequencial(arquivos, numArquivos, codigo);
                if (indice != -1) {
                    printf("Arquivo encontrado:\n");
                    printf("Código: %d, Tipo: %s, Data: %s, Texto: %s\n",
                           arquivos[indice].codigo, arquivos[indice].tipo, arquivos[indice].data, arquivos[indice].texto);
                } else {
                    printf("Arquivo não encontrado.\n");
                }
                break;
            }
            case 3: {
                char tipo[50];
                printf("Informe o tipo para busca: ");
                scanf("%s", tipo);
                buscarPorTipoSequencial(arquivos, numArquivos, tipo);
                break;
            }
            case 4:
                listarTodos(arquivos, numArquivos);
                break;
            case 0:
                printf("Saindo do programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
