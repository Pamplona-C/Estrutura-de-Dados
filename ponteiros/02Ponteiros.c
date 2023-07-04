#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//printar os numeros em ordem decrescente.

void ordena(int *x, int *y, int *z){

    int aux = 0;

    if(*x > *y){
        aux = *x;
        *x = *y;
        *y = aux;
    }

    if(*y > *z){
        aux = *y;
        *y = *z;
        *z = aux;
    }

    if(*x > *y){
        aux = *x;
        *x = *y;
        *y = aux;
    }
}

int main(){

    int n1, n2, n3;
    int *p1 = &n1, *p2 = &n2, *p3 = &n3;

    printf("Entre com 3 valores inteiros: ");
    scanf("%d %d %d", p1, p2, p3);

    ordena(p1, p2, p3);

    printf("\nA ordenacao eh: %d %d %d", *p1, *p2, *p3);
    printf("\nEndereco de memoria dos numeros eh: %d %d %d\n", p1, p2, p3);

    return 0;
}