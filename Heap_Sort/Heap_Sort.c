#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Heap_Sort(int *V, int N);
void Create_Heap(int *V, int inicio, int final);

void Heap_Sort(int *V, int N)
{
	int i, aux;
	for(i=(N-1)/2; i>=0; i--) // cria heap a partir dos dados fornecidos 
	{
		Create_Heap(V, i, N-1);
	}
	for(i=N-1; i>=1; i--) // coloca o maior elemento da heap na sua posição correspondente no array e reconstrói a heap
	{
		aux=V[0];
		V[0]=V[i];
		V[i]=aux;
		Create_Heap(V, 0, i-1);
	}
}

void Create_Heap(int *V, int inicio, int final)
{
	int aux = V[inicio];
    int i = 0;
	int j = 2*inicio+1;
	while(j<=final)
	{
		if(j<final) // verifica qual dos filhos de um mesmo pai é o maior
		{
			if(V[j]<V[j+1])
			{
				j=j+1;
			}
		}
		if(aux<V[j]) // caso o filho seja maior que o pai, o filho se torna o pai (os elementos são trocados de posição
		{
			V[i] = V[j];
			i=j;
			j=2*i+1;
		}
		else
		{
			j=final+1;
		}
	}
	V[i]=aux; // antigo pai ocupa o lugar do último filho analisado
}

int main()
{
    int tamanho = 9;
    int vetorTeste[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    for(int i = 0; i < 9; i++)
        printf("%d \n", vetorTeste[i]);

    Heap_Sort(vetorTeste, tamanho);
    
    printf("\n");

    for(int i = 0; i < 9; i++)
        printf("%d \n", vetorTeste[i]);

    return 0;
}
