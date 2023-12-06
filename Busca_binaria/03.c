#include <stdio.h>
#include <stdlib.h>


struct No {
    int chave;
    struct No* esquerda;
    struct No* direita;
    int altura;
};


int altura(struct No* no) {
    if (no == NULL) {
        return 0;
    }
    return no->altura;
}


int max(int a, int b) {
    return (a > b) ? a : b;
}


struct No* criarNo(int chave) {
    struct No* no = (struct No*)malloc(sizeof(struct No));
    no->chave = chave;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 1;  
    return no;
}


struct No* rotacaoDireita(struct No* y) {
    struct No* x = y->esquerda;
    struct No* T2 = x->direita;

   
    x->direita = y;
    y->esquerda = T2;


    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}


struct No* rotacaoEsquerda(struct No* x) {
    struct No* y = x->direita;
    struct No* T2 = y->esquerda;

    
    y->esquerda = x;
    x->direita = T2;

 
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}


int fatorBalanceamento(struct No* no) {
    if (no == NULL) {
        return 0;
    }
    return altura(no->esquerda) - altura(no->direita);
}


struct No* inserir(struct No* no, int chave) {

    if (no == NULL) {
        return criarNo(chave);
    }

    if (chave < no->chave) {
        no->esquerda = inserir(no->esquerda, chave);
    } else if (chave > no->chave) {
        no->direita = inserir(no->direita, chave);
    } else {
      
        return no;
    }


    no->altura = 1 + max(altura(no->esquerda), altura(no->direita));


    int balanceamento = fatorBalanceamento(no);


    if (balanceamento > 1 && chave < no->esquerda->chave) {
        return rotacaoDireita(no);
    }

   
    if (balanceamento < -1 && chave > no->direita->chave) {
        return rotacaoEsquerda(no);
    }

   
    if (balanceamento > 1 && chave > no->esquerda->chave) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

  
    if (balanceamento < -1 && chave < no->direita->chave) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

 
    return no;
}


void exibirFatoresBalanceamento(struct No* no) {
    if (no != NULL) {
        printf("Chave: %d, Fator de Balanceamento: %d\n", no->chave, fatorBalanceamento(no));
        exibirFatoresBalanceamento(no->esquerda);
        exibirFatoresBalanceamento(no->direita);
    }
}


void destruirArvore(struct No* no) {
    if (no != NULL) {
        destruirArvore(no->esquerda);
        destruirArvore(no->direita);
        free(no);
    }
}

int main() {
    struct No* raiz = NULL;

  
    int elementos[] = {30, 20, 40, 10, 25, 5};

    for (int i = 0; i < sizeof(elementos) / sizeof(elementos[0]); i++) {
        raiz = inserir(raiz, elementos[i]);
    }

    
    printf("Fatores de Balanceamento após a inserção:\n");
    exibirFatoresBalanceamento(raiz);

    
    destruirArvore(raiz);

    return 0;
}
