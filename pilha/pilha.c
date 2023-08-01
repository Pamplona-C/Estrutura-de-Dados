#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//declara item
typedef struct{
    int item;
}pilhaItem;

//inicializa a pilha
int topo = -1;

//função incrementar pilha
void incrementaPilha(pilhaItem p[5],int item){
    if (topo >= 4)
    {
        printf("Não é possível adicionar items na pilha.");
        return;
    }
    topo++;
    p[topo].item = item;
}

void decrementa(pilhaItem p[5]){
    p[topo].item = 0;
    topo--;
}



int main(){
    system("clear");//no windows troque o "clear" por "cls" 
    setlocale(LC_ALL, "Portuguese");

    //declara a pilha
    
    pilhaItem p[5];
    int esc = 0,x = 0;
    
    while (esc != 3)
    {
        printf("\n---PILHA---\n");
        if (topo < 0)
        {
            printf("Pilha Vazia.\n");
        }else
        printf("Topo Pilha = %d\n",topo);
        
        printf("1 - INCREMENTAR PILHA.\n");
        printf("2 - DECREMENTAR PILHA.\n");
        printf("3 - SAIR\n");

        scanf("%d",&esc);

        switch (esc)
        {
        case 1:
            if (topo >= 4)
            {
                printf("\nNão é possível adicionar items na pilha.\n");
                break;
            }
            
            printf("Digite o valor a ser inserido na pilha:\n");
            scanf("%d",&x);
            incrementaPilha(p,x);
            //printf("\nTopo = %d\n",topo);
            break;
        
        case 2:
            if (topo < 0)
            {
                printf("\nA pilha ja esta vazia.\n");
                break;
            }
            
            decrementa(p);
            //printf("\nTopo = %d\n",topo);
            break;
        }
    }
    
    return 0;
}