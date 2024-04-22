#include <stdio.h>

void Insertion_Sort(int *V, int N)      		// Vetor e tamanho
{
	int i, j, aux;

	// O i varre para direita o j para esquerda
	// Eles vão permutando suas posiçõesd de acordo.
	for(i=1; i<N; i++) 
	{
		aux = V[i];
		for(j=i; (j>0) && (aux < V[j-1]); j--)
		{
			V[j] = V[j-1];
		}
		V[j] = aux;
	}
}



int main()
{
    int vetorTeste[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    for(int i = 0; i < 10; i++)
        printf("%d \n", vetorTeste[i]);

    Insertion_Sort(vetorTeste, 9);
    
    printf("\n");

    for(int i = 0; i < 10; i++)
        printf("%d \n", vetorTeste[i]);

    return 0;
}
