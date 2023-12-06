 #include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *esq;
    struct nodo *dir;
} NO;

typedef NO *ARV;

int EMPTY(ARV a) {
    return (a == NULL);
}

ARV insere(ARV a, int b) {
    ARV nova;
    if (EMPTY(a)) {
        nova = (ARV)malloc(sizeof(NO));
        nova->esq = NULL;
        nova->dir = NULL;
        nova->info = b;
        printf("Insercao do numero %d na AB realizada!\n", b);
        return nova;
    } else {
        if (b > a->info)
            a->dir = insere(a->dir, b);
        else
            a->esq = insere(a->esq, b);
        return a;
    }
}

ARV procura(ARV a, int b) {
    if (EMPTY(a))
        return NULL;
    else if (a->info == b)
        return a;
    else if (b > a->info)
        return procura(a->dir, b);
    else
        return procura(a->esq, b);
}

void preOrdem(ARV a) {
    if (!EMPTY(a)) {
        printf("%d ", a->info);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

void posOrdem(ARV a) {
    if (!EMPTY(a)) {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%d ", a->info);
    }
}

int main() {
    ARV a = NULL;
    int opcao = 0;
    int num;

    while (opcao != 3) {
        system("cls");
        printf("\n\n----------------MENU PRINCIPAL----------------");
        printf("\n\n 1 - Inserir Novo Numero na AB");
        printf("\n 2 - Imprimir Arvore (Pre-Ordem)");
        printf("\n 3 - Imprimir Arvore (Pos-Ordem)");
        printf("\n 4 - Encerrar");
        printf("\n\n Opcao Escolhida: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("cls");
                printf("\nNovo Numero: ");
                scanf("%d", &num);
                a = insere(a, num);
                system("pause>>null");
                break;

            case 2:
                system("cls");
                printf("\nArvore (Pre-Ordem): ");
                preOrdem(a);
                printf("\n");
                system("pause>>null");
                break;

            case 3:
                system("cls");
                printf("\nArvore (Pos-Ordem): ");
                posOrdem(a);
                printf("\n");
                system("pause>>null");
                break;
        }
    }
    return 0;
}