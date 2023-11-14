#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

typedef struct {
    Person data[50];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, Person value) {
    if (stack->top < 50 - 1) {
        stack->data[++stack->top] = value;
    }
}

Person pop(Stack *stack) {
    Person emptyPerson = { "", 0 };
    
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    
    return emptyPerson;
}

void removeByName(Stack *stack, const char *nameToRemove) {
    Stack tempStack;
    initializeStack(&tempStack);

    while (stack->top >= 0) {
        Person atualPerson = pop(stack);
        if (strcmp(atualPerson.name, nameToRemove) != 0) {
            push(&tempStack, atualPerson);
        }
    }

    while (tempStack.top >= 0) {
        push(stack, pop(&tempStack));
    }
}

int main() {
    Stack personStack;
    initializeStack(&personStack);

    int numPersons;
    printf("Digite o número de pessoas: ");
    scanf("%d", &numPersons);

    for (int i = 0; i < numPersons; i++) {
        Person newPerson;
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", newPerson.name);
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &newPerson.age);

        push(&personStack, newPerson);
    }

    char nameToRemove[50];
    printf("Digite o nome da pessoa a ser removida: ");
    scanf("%s", nameToRemove);

    removeByName(&personStack, nameToRemove);

    printf("Pessoas restantes na pilha:\n");
    while (personStack.top >= 0) {
        Person atualPerson = pop(&personStack);
        printf("Nome: %s, Idade: %d\n", atualPerson.name, atualPerson.age);
    }

    return 0;
}
