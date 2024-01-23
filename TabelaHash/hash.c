#include <stdio.h>
#include <stdlib.h>

//implementado o tratamento de colisão externo
//implementado a função de busca de chave na tabela

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;

unsigned int hash(int key) {

    return key % TABLE_SIZE;
}

void initializeHashTable(Node **hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

void insert(Node **hashTable, int key, int value) {
    unsigned int index = hash(key);

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node *current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printHashTable(Node **hashTable) {
    printf("Tabela Hash:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        Node *current = hashTable[i];
        while (current != NULL) {
            printf("(%d - %d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");
    }
}

Node* search(Node **hashTable, int key) {
    unsigned int index = hash(key);

    Node *current = hashTable[index];
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }

    return NULL;  
}

int main() {
    Node *hashTable[TABLE_SIZE];
    initializeHashTable(hashTable);

    insert(hashTable, 7,100);
    insert(hashTable, 42, 24);
    insert(hashTable, 17, 100);
    insert(hashTable, 8, 1);
    insert(hashTable, 99, 55);
    insert(hashTable, 23, 96);

    printHashTable(hashTable);

    int keyToSearch;
    printf("Digite a chave : \n");
    scanf("%d",&keyToSearch);

    Node *result = search(hashTable, keyToSearch);

    if (result != NULL) {
        printf("Chave %d encontrada. Valor: %d\n", keyToSearch, result->value);
    } else {
        printf("Chave %d não encontrada.\n", keyToSearch);
    }

    return 0;
}

