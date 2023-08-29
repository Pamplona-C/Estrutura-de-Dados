#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100

typedef struct {
    char dados[TAM_MAX];
    int topo;
} Pilha;

void inicializaPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int pilhaCheia(Pilha *pilha) {
    return pilha->topo == TAM_MAX - 1;
}

void push(Pilha *pilha, char elemento) {
    if (!pilhaCheia(pilha)) {
        pilha->topo++;
        pilha->dados[pilha->topo] = elemento;
    }
}

char pop(Pilha *pilha) {
    if (!pilhaVazia(pilha)) {
        char elemento = pilha->dados[pilha->topo];
        pilha->topo--;
        return elemento;
    }
    return '\0'; // Retorna caractere nulo se a pilha estiver vazia
}

int verificaPalindromo(char *cadeia) {
    Pilha pilha;
    inicializaPilha(&pilha);
    
    int tamanho = strlen(cadeia);
    int i;

    for (i = 0; i < tamanho / 2; i++) {
        push(&pilha, cadeia[i]);
    }

    if (tamanho % 2 == 1) {
        i++;
    }

    while (cadeia[i] != '\0') {
        if (pop(&pilha) != cadeia[i]) {
            return 0; // Não é palíndromo
        }
        i++;
    }

    if (pilhaVazia(&pilha)) {
        return 1; // É palíndromo
    } else {
        return 0; // Não é palíndromo
    }
}

int main() {
    char cadeia[TAM_MAX];
    printf("Digite uma cadeia de caracteres: ");
    scanf("%s", cadeia);

    if (verificaPalindromo(cadeia)) {
        printf("A cadeia é um palíndromo.\n");
    } else {
        printf("A cadeia não é um palíndromo.\n");
    }

    return 0;
}
