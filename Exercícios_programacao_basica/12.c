#include <stdio.h>
#include <stdlib.h>

//Fazer um programa em C que pergunte um valor em graus fahrenheit e imprime no video o correspondente em graus celsius usando as formulas que seguem. 
//A) Usar uma variável double para ler o valor em Fahrenheit e a fórumla C=(f-32.0) * (5.0/9.0).
//B) Usar uma variável int para ler o valor fahrenheit e a fórmula C=(f-32)*(5/9).


int main(){
    //A
    system("clear");
    double temp = 0;

    printf("Digite uma temperatura em graus :");
    scanf("%lf",&temp);
    temp = (temp - 32.0) * (5.0/9.0);

    printf("A temperatura em Celsius e euqivalente a = %.1lfº",temp);

    


    return 0;
}