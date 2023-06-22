#include <stdio.h>


//Dado um natural n, determine o número harmônico Hn .

double numeroHarmonico(int n) {
    double soma = 0.0;
    for (int i = 1; i <= n; i++) {
        soma += 1.0 / i;
    }
    return soma;
}

int main() {
    system("cls");

    int n;
    printf("Digite um valor para n: ");
    scanf("%d", &n);

    double resultado = numeroHarmonico(n);

    printf("O numero harmonico para n = %d e: %.4lf\n", n, resultado);

    return 0;
}
