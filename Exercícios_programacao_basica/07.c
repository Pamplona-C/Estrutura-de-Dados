#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>

//Dados dois vetores x e y, ambos com n elementos, determinar o produto escalar de cada vetor.

int calc_prod_escalar(int v1[5],int v2[5]){
    int result = 0;
    for (int i = 0; i < 5; i++)
    {
        result += (v1[i] * v2[i]) ;
        
    }
    
    return result;
}


int main(){

    system("clear");

    int v1[5],v2[5];

    printf("Digite os 5 elementos dos dois vetores : \n");


    for (int y = 1; y < 3; y++)
    {
        for (int i = 0; i < 5; i++)
        {
            printf("Digite o %dº valor do vetor v%d : ",i+1,y);
            if (y == 1)
            {
                scanf("%d",&v1[i]);
            }
            else
            {
                scanf("%d",&v2[i]);
            }
            
        }
        system("clear");
    }

    printf("Os valores digitados foram : \n");
    
    for (int z = 1; z < 3; z++)
    {
        printf("V%d = ",z);

        for (int i = 0; i < 5; i++)
        {
            if (z == 1)
            {
                printf("%d - ",v1[i]);
            }
            else
            {
                printf("%d - ",v2[i]);
            }
            
        }
        printf("\n");
        
    }

    system("clear");

    int result = calc_prod_escalar(v1,v2);

    printf("O produto escalar dos vetores V1 e V2 = %d\n",result);


    


    

    return 0;
}