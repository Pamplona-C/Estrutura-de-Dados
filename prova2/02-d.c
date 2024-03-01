#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chave;
} Registro;

int hashDuplo(int k, int i) {
    int h1 = k % 10;
    int h2 = 7 - (k % 7);
    return (h1 + i * h2) % 10;
}

void inserirHashDuplo(Registro tabelaHash[], int chave) {
    int i = 0;
    int posicao;

    do {
        posicao = hashDuplo(chave, i);
        if (tabelaHash[posicao].chave == 0) {
            tabelaHash[posicao].chave = chave;
            return;
        }
        i++;
    } while (i < 10);
}

void imprimirTabelaHash(Registro tabelaHash[]) {
    for (int i = 0; i < 10; i++) {
        printf("%d: %d\n", i, tabelaHash[i].chave);
    }
}

int main() {
    Registro tabelaHashDuplo[10] = {{0}};

    int chaves[] = {371, 121, 173, 203, 11, 24};
    int numChaves = sizeof(chaves) / sizeof(chaves[0]);

    for (int i = 0; i < numChaves; i++) {
        inserirHashDuplo(tabelaHashDuplo, chaves[i]);
    }

    printf("Tabela Hash com Hash Duplo:\n");
    imprimirTabelaHash(tabelaHashDuplo);

    return 0;
}
