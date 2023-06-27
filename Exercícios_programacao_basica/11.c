#include <stdio.h>
#include <stdlib.h>

//Fazer um programa em C que imprime uma tabela com a tabuada de 1 a 9.

int main()
{
    system("cls");

    printf("Tabuada de 1 a 9 :\n");

    for (int i = 1; i < 10; i++)
    {
        for (int y = 1; y < 10; y++)
        {
            printf("%d x %d = %d\n",i,y,(i * y));
        }
    }
    return 0;
}
