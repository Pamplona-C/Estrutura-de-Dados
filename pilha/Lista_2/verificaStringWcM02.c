#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Definição da estrutura de pilha
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// Função para inicializar a pilha
void initializeStack(Stack *stack) {
    stack->top = -1;
}

// Função para empilhar um elemento na pilha
void push(Stack *stack, char value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    }
}

// Função para desempilhar um elemento da pilha
char pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return '\0'; // Retorna '\0' se a pilha estiver vazia
}

// Função para verificar se uma string está na forma WcM
int isWcM(const char *str) {
    Stack stack;
    initializeStack(&stack);

    int len = strlen(str);
    int i;
    
    for (i = 0; i < len / 2; i++) {
        if (str[i] != 'c') {
            push(&stack, str[i]);
        } else {
            break;
        }
    }

    for (i++; i < len; i++) {
        char top = pop(&stack);
        if (top != str[i]) {
            return 0; // Não está na forma WcM
        }
    }

    return 1; // Está na forma WcM
}

int main() {
    char str[MAX_SIZE];
    printf("Digite a string: ");
    scanf("%s", str);

    if (isWcM(str)) {
        printf("A string está na forma WcM.\n");
    } else {
        printf("A string não está na forma WcM.\n");
    }

    return 0;
}
