#include <stdio.h>

void bubbleSort(int *V, int  N )        //*V = vetor, N = tamanho do vetor
{
    int i, continua = 1, aux, fim=N;     

    while(continua!=0)
    {
        continua = 0;
        for(i=0; i<fim-1; i++)      // Percorre N-1 do vetor
        {
            if(V[i]>V[i+1])         // Se o número anterior for maior que o posterior
            {
                aux = V[i];         // Swap Values
                V[i] = V[i+1];
                V[i+1] = aux;
                continua = i;       // Quando chegar ao final (fim - 1) = i = 0
            }
        }

        fim--;                      // Decremento para diminuir o valor
    }
}


int main()
{
    int vetorTeste[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    for(int i = 0; i < 10; i++)
        printf("%d \n", vetorTeste[i]);

    bubbleSort(vetorTeste, 9);
    
    printf("\n");

    for(int i = 0; i < 10; i++)
        printf("%d \n", vetorTeste[i]);

    return 0;
}
