#include <stdio.h>

void Selection_Sort(int *V, int N)      		// Vetor e tamanho
{
	int i, j, menor, troca;

	for(i=0; i<N-1; i++)
	{
		menor = i;
		for(j=i+1; j<N; j++)                    // procura o menor elemento em relação a i
		{
			if(V[j]<V[menor])
				menor = j;
		}
		if(i != menor)                          // troca os valores da posição atual com a menor
		{
			troca = V[i];
			V[i] = V[menor];
			V[menor] = troca;
		}
	}
}



int main()
{
    int vetorTeste[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    for(int i = 0; i < 9; i++)
        printf("%d \n", vetorTeste[i]);

    Selection_Sort(vetorTeste, 9);
    
    printf("\n");

    for(int i = 0; i < 9; i++)
        printf("%d \n", vetorTeste[i]);

    return 0;
}
