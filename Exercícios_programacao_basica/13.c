#include <stdlib.h>
#include <stdio.h>

//13 - Fazer uma função que calcula o fatorial de um número. Implementar uma função recursiva e uma versão com laço.

int calc_fatorial(int n){

    printf("O fatoria de %d = ",n);

    for (int i = n; i > 1; i--)
    {
        n = n*(i-1);
    }
    printf("%d\n",n);
    return 0;
    
}

int calc_fatorialRec( int y){

    if (y == 0)
    {
        printf("Fatorial de 0 = 1");
        return 1;
        
    }else{
        return  y * calc_fatorialRec(y-1);
    }
}


int main(){
    int cont = 0;
    do
    {
        printf("Calculo de fatorial\n");
        printf("Selecione qual metodo usar : ");
        printf("\n01-Laço");
        printf("\n02-Recursiva\n");
        scanf("%d",&cont);

        if ((cont != 1) && (cont != 2))
        {
            system("clear");
            printf("\nERRO - O numero digitado nao esta entre as opcoes.");
            printf("\nDigite novamente.\n");
        }
        

    } while ((cont != 1) && (cont != 2));
    
    
    

    switch (cont)
    {
    case 1:
        system("clear");

        int n = 0;

        printf("Digite um numero para calcular o fatorial : ");
        scanf("%d",&n);
        calc_fatorial(n);
        break;
    
    case 2:

        system("clear");
        int y;
        int result = 0;
        printf("Digite um numero para calcular o fatorial :");
        scanf("%d",&y);
        result = calc_fatorialRec(y);

        printf("\nO fatorial de %d = %d.",y,result);
        break;
    }

    

    return 0;
}

