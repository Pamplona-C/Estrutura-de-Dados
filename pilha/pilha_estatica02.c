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
        printf("Pilha cheia, não é possível adicionar items. %d\n", value);
        return;
    }

    stack->top++;
    stack->data[stack->top] = value;
    display(stack);
}

int pop(Pilha *stack) {
    if (stack->top == -1) {
        printf("Stack underflow: cannot pop element\n");
        return -1;
    }

    int value = stack->data[stack->top];
    stack->top--;
    display(stack);
    return value;
}


int peek(Pilha *stack) {  //visualiza o topo da pilha
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }

    return stack->data[stack->top];
}

int isEmpty(Pilha* stack) {
    return stack->top == -1;
}

void display(Pilha* stack) {
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
    Pilha stack; //declara a pilha
    stack.top = -1; 

    system("clear");//no windows troque o "clear" por "cls" 
    setlocale(LC_ALL, "Portuguese");
    
    int esc = 0,x = 0;
    
    while (esc != 3)
    {
        printf("\n---PILHA---\n");
        if (stack.top < 0)
        {
            printf("Pilha Vazia.\n");
        }else
        printf("Topo Pilha = %d\n",stack.top);
        
        printf("1 - INCREMENTAR PILHA.\n");
        printf("2 - DECREMENTAR PILHA.\n");
        printf("3 - SAIR\n");

        scanf("%d",&esc);

        switch (esc)
        {
        case 1:
            printf("Digite o valor a ser inserido na pilha:\n");
            scanf("%d",&x);
            push(&stack,x);
            //printf("\nTopo = %d\n",topo);
            break;
        
        case 2:
            pop(&stack);
            //printf("\nTopo = %d\n",topo);
            break;
        }
    }
    
    return 0;
}
