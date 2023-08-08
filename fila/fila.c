#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Cria item fila
typedef struct{
    int item;
}filaItem;


int fim = -1;
int inicio = 0;

void enfileirar(filaItem f[5], int valor){
    fim++;
    f[fim].item = valor;
}

void desenfileirar(filaItem f[5]){
    f[inicio].item = 0;
    inicio++;
}

void consultaFila(filaItem f[5]){
    printf("Valor que esta no inicio = %d\n",f[inicio].item);
}

int main(){
    system("clear");//no windows troque o "clear" por "cls" 
    setlocale(LC_ALL, "Portuguese");

    //declara a pilha
    
    filaItem f[5];
    int esc = 0,x = 0;
    
    while (esc != 3)
    {
        printf("\n---FILA---\n");
        if (fim < 0)
        {
            printf("Fila Vazia.\n");
        }else
        printf("Inicio fila = %d\n",inicio);
        if (fim >= 0)
        {
            printf("Final fila = %d\n",fim);
        }
        
        printf("1 - INCREMENTAR FILA.\n");
        printf("2 - DECREMENTAR FILA.\n");
        printf("3 - CONSULTAR VALOR INICIO.\n");
        printf("4 - SAIR\n");

        scanf("%d",&esc);

        switch (esc)
        {
        case 1:
            if (fim >= 4)
            {
                printf("\nNão é possível adicionar items na Fila.\n");
                break;
            }
            
            printf("Digite o valor a ser inserido na Fila:\n");
            scanf("%d",&x);
            enfileirar(f,x);
            //printf("\nTopo = %d\n",topo);
            break;
        
        case 2:
            if (fim < 0)
            {
                printf("\nA Fila ja esta vazia.\n");
                break;
            }
            
            desenfileirar(f);
            //printf("\nTopo = %d\n",topo);
            break;

        case 3:
            consultaFila(f);
            break;

        case 4:
            return 0;
            break;
        }
    }
    
    return 0;
}