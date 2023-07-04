#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//14 - Fazer um programa em C que solicita o total gasto pelo cliente de uma loja, imprime as opções de pagamento, solicita a opção desejada e imprime o valor das prestações (se houverem).

//A - Opção À vista com 10% de desconto.
//B - Opção em duas vezes (preço da etiqueta)
//C - Opção de 3 até 10 vezes com 3% de juros ao mês.(somente para compras acima de R$100,00)

int calc_parcelas(double v,int p,int j){

    if (p > 2)
    {
        for (int i = 0; i < p; i++)
        {
            printf("Parcela 0%d = %.2lf\n",i+1,v/p);
        }
        
        return 1;
    }

    
    for (int i = 0; i < 2; i++)
    {
       
        printf("Parcela 0%d = %.2lf\n",i+1,v/p);
    }
    
    return 0;

}

double calc_desconto(int v,double p){
    double result = 0.0;

    result = v - (v * (p/100));

    return result;
}


int main(){
    setlocale(LC_ALL, "Portuguese");

    double valor = 0.0;
    int opc = 0;

    do
    {   
        printf("Digite o valor da compra : ");
        scanf("%lf",&valor);
        if (valor <= 0.0)
        {
            printf("ERRO - Valor inválido.");
            printf("\nDigite novamente\n");
        }
        
    } while (valor <= 0.0);

    printf("\nEscolha uma das opcoes :\n");

    printf("01 - À vista com 10%% de desconto.\n");
    printf("02 - Em duas parcelas.\n");
    if (valor > 100)
    {
        printf("03 - Até 10x com 3%% ao mês.\n");
    }
    
    scanf("%d",&opc);
    switch (opc)
    {
    case 1:
        double result = calc_desconto(valor,10);
        printf("O valor com desconto de 10%% = R$%.2lf\n",result);
        break;
    
    case 2:
        calc_parcelas(valor,2,3);
        break;

    case 3:
        int qtd = 0;
        printf("\nQuantas parcelas : \n");
        scanf("%d",&qtd);
        calc_parcelas(valor,qtd,3);
    }
    
    


    return 0;
}