#include <stdio.h>
#include <stdlib.h>

void buscaPadrao(int cadeia[], int tamCadeia, int padrao[], int tamPadrao, int *posicaoPrimeira, int *ocorrencias){
    *posicaoPrimeira = -1; 

    for (int i = 0; i <= (tamCadeia - tamPadrao); i++)
    {
        int j = 0;
        while (j < tamPadrao && cadeia[i+j] == padrao[j])
        {
            j = j+1;
            if (j == tamPadrao)
            {
                (*ocorrencias)++; 

                if (*posicaoPrimeira == -1) {
                    *posicaoPrimeira = i;
                }
            }
        }
    }
}

int main(){
    int padrao[] = {2, 1};
    int cadeia[] = {8, 5, 7, 2, 1, 3, 2, 1, 3, 5, 9, 6, 4, 2, 1};

    int tamPadrao = sizeof(padrao)/sizeof(padrao[0]);
    int tamCadeia = sizeof(cadeia)/sizeof(cadeia[0]);

    printf("Tamanho do vetor Padrao: %d\n", tamPadrao);
    printf("Tamanho do vetor Cadeia: %d\n", tamCadeia);

    int posicaoPrimeira = -1; 
    int ocorrencias = 0; 

    buscaPadrao(cadeia, tamCadeia, padrao, tamPadrao, &posicaoPrimeira, &ocorrencias);

    if (ocorrencias > 0) {
        printf("Padrao encontrado na posicao: %d\n", posicaoPrimeira);
        printf("Total de ocorrencias: %d\n", ocorrencias);
    } else {
        printf("Padrao nao encontrado na cadeia.\n");
    }

    return 0;
}
