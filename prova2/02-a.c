#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chave;
} Registro;

int hashLinear(int k, int i) {
    return (k + i) % 10;
}

void inserirSondagemLinear(Registro tabelaHash[], int chave) {
    int i = 0;
    int posicao;

    do {
        posicao = hashLinear(chave, i);
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
    Registro tabelaHashLinear[10] = {{0}};

    int chaves[] = {371, 121, 173, 203, 11, 24};
    int numChaves = sizeof(chaves) / sizeof(chaves[0]);

    for (int i = 0; i < numChaves; i++) {
        inserirSondagemLinear(tabelaHashLinear, chaves[i]);
    }

    printf("Tabela Hash com Sondagem Linear:\n");
    imprimirTabelaHash(tabelaHashLinear);

    return 0;
}
