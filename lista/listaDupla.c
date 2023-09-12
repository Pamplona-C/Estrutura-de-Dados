#include <stdio.h>
#include <stdlib.h>

typedef struct Noh{
    int valor;
    struct Noh* prox;
    struct Noh* ant;
}Noh;

struct Noh* criaNoh(int valor) {
    struct Noh* novoNoh = (struct Noh*)malloc(sizeof(struct Noh));

    if (novoNoh == NULL)
    {
        printf("Erro ao criar noh!\n");
        return NULL;
    }else{

        novoNoh->valor = valor;
        novoNoh->prox = NULL;
        novoNoh->ant = NULL;

        return novoNoh;

    } 
}

struct Noh* insereInicio(struct Noh lista, int valor) {

    struct Noh* novoNOH = criaNoh(valor);
    *novoNOH->prox = lista;
    lista.ant = novoNOH;

    return novoNOH;
}

int main(){

    struct Noh* lista = NULL;


    return 0;
}

