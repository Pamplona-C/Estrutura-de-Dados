#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//printar os numeros em ordem decrescente.

void ordena(int *p1, int *p2, int *p3){
    printf("Os números em ordem decrescente : ");
    if (*p1 > *p2)
    {
        if (*p1 > *p3)
        {
            printf("%d\n",*p1);
            if (*p3 > *p2)
            {
                printf("%d\n",*p3);
                printf("%d\n",*p2);
            }else
            {
                printf("%d\n",*p2);
                printf("%d\n",*p3);
            }
        }else
        {
            printf("%d\n",*p3);
            printf("%d\n",*p1);
            printf("%d\n",*p2);
        }
        
        
    }else
    {
        if (*p2 > *p3)
        {
            printf("%d\n",*p2);
            if (*p3 > *p1)
            {
                printf("%d\n",*p3);
                printf("%d\n",*p1);
            }else
            {
                printf("%d\n",*p1);
                printf("%d\n",*p3);
            }
            
            
        }else
        {
            printf("%d\n",*p3);
            printf("%d\n",*p2);
            printf("%d\n",*p1);
        }   
    }
}


int main(){

    system("clear");

    setlocale(LC_ALL, "Portuguese");

    int n1,n2,n3;
    int *p1 = &n1,*p2 = &n2,*p3 = &n3;

    printf("Digite 3 números em ordem aleatória \n");
    scanf("%d %d %d",&*p1,&*p2,&*p3);

    ordena(&n1,&n2,&n3);

    return 0;
}