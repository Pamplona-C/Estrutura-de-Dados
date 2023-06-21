#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
 
    char nome[50];
    double salario,tvendas;
    
    
    scanf("%s\n",&nome);
    scanf("%f\n",&salario);
    scanf("%f\n",&tvendas);
    
    int salarioMes = tvendas*(15/100)+salario;
    
    printf("TOTAL = R$ %0.2f",salarioMes);
    
    return 0;
}