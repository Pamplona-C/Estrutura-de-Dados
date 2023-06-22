#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>

//Uma pessoa aplicou um capital de x taoqueis a juros mensais de z durante 1 ano.Determinar o montante de cada mês durante este período.

double calc_juros_simples(double x, double z, int meses) {
    double juros = x * (z/100) * meses;
    return juros;
}


int main() {
    system("cls");

    double x = 0, z = 0, juros = 0;
    int meses = 0;

    printf("\nDigite o capital a ser aplicado: ");
    scanf("%lf", &x);

    printf("\nDigite a taxa de juros a ser calculada (`%%`): ");
    scanf("%lf", &z);

    printf("\nDigite o tempo a ser calculado o juros (quantidade de meses): ");
    scanf("%d", &meses);

    juros = calc_juros_simples(x, z, meses);

    printf("O valor principal = %.2lf\n",x);
    printf("A taxa de juros a ser calculada = %.1lf\n",z);
    printf("O tempo a ser calculado o juros = %d\n",meses);

    printf("O valor do juros no decorrer de %d meses = R$%.2lf\n",meses,juros);
    printf("O valor principal somado aos juros = R$%.2lf",(x + juros));

    return 0;
}
