#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int chave;
} Registro;

int hashQuadratica2(int k, int i) {
    return (k + 2 * i + i * i) % TABLE_SIZE;
}

void inserirSondagemQuadratica2(Registro tabelaHash[], int chave) {
    int i = 0;
    int posicao;

    do {
        posicao = hashQuadratica2(chave, i);
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
    Registro tabelaHashQuadratica2[TABLE_SIZE] = {{0}};

    int chaves[] = {371, 121, 173, 203, 11, 24};
    int numChaves = sizeof(chaves) / sizeof(chaves[0]);

    for (int i = 0; i < numChaves; i++) {
        inserirSondagemQuadratica2(tabelaHashQuadratica2, chaves[i]);
    }

    printf("Tabela Hash com Sondagem Quadratica (Função 2):\n");
    imprimirTabelaHash(tabelaHashQuadratica2);

    return 0;
}
