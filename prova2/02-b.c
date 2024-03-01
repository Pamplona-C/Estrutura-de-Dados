#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int chave;
} Registro;

int hashQuadratica1(int k, int i) {
    return (k + i * 2) % TABLE_SIZE;
}

void inserirSondagemQuadratica1(Registro tabelaHash[], int chave) {
    int i = 0;
    int posicao;

    do {
        posicao = hashQuadratica1(chave, i);
        if (tabelaHash[posicao].chave == 0) {
            tabelaHash[posicao].chave = chave;
            return;
        }
        i++;
    } while (i < TABLE_SIZE);
}

void imprimirTabelaHash(Registro tabelaHash[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: %d\n", i, tabelaHash[i].chave);
    }
}

int main() {
    Registro tabelaHashQuadratica1[TABLE_SIZE] = {{0}};

    int chaves[] = {371, 121, 173, 203, 11, 24};
    int numChaves = sizeof(chaves) / sizeof(chaves[0]);

    for (int i = 0; i < numChaves; i++) {
        inserirSondagemQuadratica1(tabelaHashQuadratica1, chaves[i]);
    }

    printf("Tabela Hash com Sondagem Quadratica (Função 1):\n");
    imprimirTabelaHash(tabelaHashQuadratica1);

    return 0;
}
