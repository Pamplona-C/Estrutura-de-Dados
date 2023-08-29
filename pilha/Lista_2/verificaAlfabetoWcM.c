#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char string[50];
    int topo;
} Pilha;

int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int pilhaCheia(Pilha *pilha) {
    return pilha->topo == 49; // O índice máximo é 49, uma vez que o índice 50 armazena o caractere nulo.
}

void inicializaPilha(Pilha *pilha) {
    pilha->topo = -1;
}

void push(Pilha *pilha, char string) {
    if (pilhaCheia(pilha)) {
        printf("Pilha Cheia.\n");
        return;
    }

    pilha->topo++;
    pilha->string[pilha->topo] = string;
    pilha->string[pilha->topo + 1] = '\0';
}

char pop(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia\n");
        return '\0';
    }
    char c = pilha->string[pilha->topo];
    pilha->topo--;
    return c;
}

void tranfereDado(Pilha *pilhaOrigem, Pilha *pilhaDestino) {
    while (pilhaOrigem->topo >= 0 && pilhaOrigem->string[pilhaOrigem->topo] != 'c') {
        char c = pop(pilhaOrigem);
        push(pilhaDestino, c);
    }
}


int main(){
    Pilha pilha1, pilha2;

    char string[] = "aabababcbababaa";

    inicializaPilha(&pilha1);
    inicializaPilha(&pilha2);

    for (int i = 0; string[i] != '\0'; i++) {
        push(&pilha1, string[i]);
    }

    tranfereDado(&pilha1, &pilha2);

    printf("String na pilha2: %s\n", pilha2.string);
    printf("Topo pilha1 = %d.\n",pilha1.topo);
    printf("Topo pilha2 = %d.\n",pilha2.topo);

    return 0;
}
