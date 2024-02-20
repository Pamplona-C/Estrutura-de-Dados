#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefixoSufixo(char *padrao, int M, int *maiorPrefixoSufixo) {
    int len = 0;  // comprimento do sufixo atualmente correspondido
    int i;

    maiorPrefixoSufixo[0] = 0;  // maiorPrefixoSufixo[0] sempre é 0

    for (i = 1; i < M; ) {
        if (padrao[i] == padrao[len]) {
            len++;
            maiorPrefixoSufixo[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = maiorPrefixoSufixo[len - 1];
            } else {
                maiorPrefixoSufixo[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *txt, char *padrao) {
    int N = strlen(txt);//é o comprimento da string de texto 
    int M = strlen(padrao);//é o comprimento da string de padrao

    // Construir o array maiorPrefixoSufixo
    int *maiorPrefixoSufixo = (int *)malloc(sizeof(int) * M);
    prefixoSufixo(padrao, M, maiorPrefixoSufixo);

    int i = 0;  // índice para txt[]
    int j = 0;  // índice para padrao[]

    while (i < N) {
        if (padrao[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Padrão encontrado na posição %d\n", i - j);
            j = maiorPrefixoSufixo[j - 1];
        } else if (i < N && padrao[j] != txt[i]) {
            if (j != 0)
                j = maiorPrefixoSufixo[j - 1];
            else
                i++;
        }
    }

    free(maiorPrefixoSufixo);  
}

int main() {
    char txt[] = "ABABDABAABCBCADECDABABCABAB";
    char padrao[] = "ABABCABAB";
    printf("Texto: %s\n", txt);
    printf("Padrão: %s\n", padrao);
    printf("Resultados da busca:\n");
    KMPSearch(txt, padrao);
    return 0;
}
