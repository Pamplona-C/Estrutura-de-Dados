#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Pilha;

void push(Pilha *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Pilha cheia, não é possível adicionar itens. %d\n", value);
        return;
    }

    stack->top++;
    stack->data[stack->top] = value;
}

int pop(Pilha *stack) {
    if (stack->top == -1) {
        printf("Stack underflow: não é possível desempilhar elemento\n");
        return -1;
    }

    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

void peek(Pilha *stack) {
    if (stack->top == -1) {
        printf("A pilha está vazia\n");
        return -1;
    }

    printf("Elemento topo = %d.",stack->data[stack->top]);
}

int isEmpty(Pilha *stack) {
    return stack->top == -1;
}

void display(Pilha *stack) {
    if (isEmpty(stack)) {
        printf("A pilha está vazia.\n");
        return;
    }

    printf("Elementos na pilha: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    Pilha stack;
    stack.top = -1;

    setlocale(LC_ALL, "Portuguese");

    int esc = 0, x = 0;

    while (esc != 5) {
        printf("\n---PILHA---\n");
        if (stack.top < 0) {
            printf("Pilha Vazia.\n");
        } else {
            printf("Topo da Pilha = %d\n", stack.top);
            display(&stack);
        }

        printf("1 - INCREMENTAR PILHA.\n");
        printf("2 - DECREMENTAR PILHA.\n");
        printf("3 - VISUALIZAR ELEMENTOS DA PILHA.\n");
        printf("4 - VISUALIZAR ELEMENTO DO TOPO.\n");
        printf("5 - SAIR.\n");

        scanf("%d", &esc);

        switch (esc) {
            case 1:
                printf("Digite o valor a ser inserido na pilha:\n");
                scanf("%d", &x);
                push(&stack, x);
                break;

            case 2:
                if (!isEmpty(&stack)) {
                    int poppedValue = pop(&stack);
                    printf("Elemento desempilhado: %d\n", poppedValue);
                }
                break;

            case 3:
                display(&stack);
                break;
            
            case 4:
                peek(&stack);
                break;
        }
    }

    return 0;
}
