#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de casamento de padrões - Força Bruta
int buscaForcaBruta(char *texto, char *padrao) {
    int ocorrencias = 0;
    int m = strlen(texto);
    int n = strlen(padrao);

    for (int i = 0; i <= m - n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (texto[i + j] != padrao[j]) {
                break;
            }
        }

        if (j == n) {
            ocorrencias++;
        }
    }

    return ocorrencias;
}

// Função de casamento de padrões - BMH (Boyer-Moore-Horspool)
int buscaBMH(char *texto, char *padrao) {
    int ocorrencias = 0;
    int m = strlen(texto);
    int n = strlen(padrao);
    int tabela[256]; // Tabela de deslocamento

    for (int i = 0; i < 256; i++) {
        tabela[i] = n; // Inicializa a tabela com o comprimento do padrão
    }

    for (int i = 0; i < n - 1; i++) {
        tabela[padrao[i]] = n - 1 - i;
    }

    int i = 0;
    while (i <= m - n) {
        int j = n - 1;
        while (j >= 0 && texto[i + j] == padrao[j]) {
            j--;
        }

        if (j < 0) {
            ocorrencias++;
            i += tabela[texto[i + n - 1]];
        } else {
            i += tabela[texto[i + n - 1]];
        }
    }

    return ocorrencias;
}

// Função de casamento de padrões - KMP (Knuth-Morris-Pratt)
int buscaKMP(char *texto, char *padrao) {
    int ocorrencias = 0;
    int m = strlen(texto);
    int n = strlen(padrao);
    int *pi = (int *)malloc(sizeof(int) * n);

    // Construção da tabela de prefixo e sufixo
    int len = 0;
    pi[0] = 0;
    int i = 1;

    while (i < n) {
        if (padrao[i] == padrao[len]) {
            len++;
            pi[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = pi[len - 1];
            } else {
                pi[i] = 0;
                i++;
            }
        }
    }

    i = 0;
    int j = 0;
    while (i < m) {
        if (padrao[j] == texto[i]) {
            j++;
            i++;
        }

        if (j == n) {
            ocorrencias++;
            j = pi[j - 1];
        } else if (i < m && padrao[j] != texto[i]) {
            if (j != 0) {
                j = pi[j - 1];
            } else {
                i++;
            }
        }
    }

    free(pi);
    return ocorrencias;
}

int main() {
    char nomeArquivo[100];
    char palavra[100];

    printf("Informe o nome do arquivo (com a extensao .txt): ");
    scanf("%s", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("Informe a palavra que deseja buscar no arquivo: ");
    scanf("%s", palavra);

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    char *texto = (char *)malloc(tamanho + 1);
    fread(texto, 1, tamanho, arquivo);
    texto[tamanho] = '\0';

    fclose(arquivo);

    int ocorrenciasForcaBruta = buscaForcaBruta(texto, palavra);
    int ocorrenciasBMH = buscaBMH(texto, palavra);
    int ocorrenciasKMP = buscaKMP(texto, palavra);

    printf("\nResultados:\n");
    printf("Forca Bruta: %d ocorrencia(s)\n", ocorrenciasForcaBruta);
    printf("BMH: %d ocorrencia(s)\n", ocorrenciasBMH);
    printf("KMP: %d ocorrencia(s)\n", ocorrenciasKMP);

    free(texto);

    return 0;
}
