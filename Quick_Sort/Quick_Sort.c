#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Hoare_Partition(int A[], int startIndex, int endIndex);
void Quick_Sort(int A[], int startIndex, int endIndex);
void Swap(int A[], int i, int j);

void Quick_Sort(int A[], int startIndex, int endIndex)
{
    if (startIndex < endIndex)                              // SE NÃO FOSSE O CODIGO DEVERIA SER INVERTIDO
    {
        int q = Hoare_Partition(A, startIndex, endIndex);    // PEGA O INDEX EM QUE SE ENCONTRAM
        Quick_Sort(A, startIndex, q - 1);                    // FAZ DE NOVO PARA UM MENOR QUE O INDEX DE ENCONTRO
        Quick_Sort(A, q + 1, endIndex);                      // FAZ DE NOVO PARA UM MAIOR QUE O INDEX DE ENCONTRO
    }
}

int Hoare_Partition(int A[], int startIndex, int endIndex)
{
    int pivo = A[startIndex];               // ESCOLHE ARBITRARIAMENTE O PIVO
    int i = startIndex + 1;                 // startIndex É APÓS O PIVO
    int j = endIndex;                       // ESCOLHE endIndex

    while (i <= j)                          // ENQUANTO NÃO SE ATRAVESSAM
    {
        while (i <= j && A[i] <= pivo)      // AVANÇA I ATÉ ENCONTRAR VALOR MAIOR/IGUAL QUE PIVO OU PASSAR J
            i++;

        while (i <= j && A[j] > pivo)       // VOLTA J ATÉ ENCONTRAR VALOR MENOR QUE PIVO OU PASSAR I
            j--;

        if (i < j)                          // SE J FOR MENOR ELES TROCAM DE LUGAR
            Swap(A, i, j);
    }

    Swap(A, startIndex, j);                 // TROCAM I E J DE LUGAR
    return j;
}

void Swap(int A[], int i, int j)                            // TROCA VALORES DE DOIS INDEX
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}


int main()
{
    int fim = 9;
    int vetorTeste[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    for(int i = 0; i < 9; i++)
        printf("%d \n", vetorTeste[i]);

    Quick_Sort(vetorTeste, 0, fim);
    
    printf("\n");

    for(int i = 0; i < 9; i++)
        printf("%d \n", vetorTeste[i]);

    return 0;
}
