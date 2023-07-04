#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*6) Faça um programa em C que receba uma frase do usuário e mostre a frase, palavra
por palavra, uma em cada linha diferente. Esse programa deve conter ponteiros na
para manusear a string. A frase deve possuir no máximo 60 caracteres.*/

void mostrarPalavras(char *frase) {
    while (*frase != '\0') {
        // Ignorar espaços no início da palavra
        while (*frase == ' ') {
            frase++;
        }

        // Exibir a palavra atual
        while (*frase != '\0' && *frase != ' ') {
            printf("%c", *frase);
            frase++;
        }

        printf("\n");
    }
}

int main() {
    char frase[60];

    printf("Digite uma frase (máximo de %d caracteres): ", 60 - 1);
    fgets(frase, 60, stdin);

    // Remover o caractere de nova linha (\n) no final da frase, se presente
    size_t len = strlen(frase);
    if (frase[len - 1] == '\n') {
        frase[len - 1] = '\0';
    }

    printf("Palavras da frase:\n");
    mostrarPalavras(frase);

    return 0;
}
