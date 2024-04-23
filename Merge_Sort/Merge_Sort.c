#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Merge(int *array, int, int, int);

void Merge_Sort(int *V, int inicio, int fim)
{
	int meio;
	if(inicio<fim)
	{
		meio = floor((inicio+fim)/2);       // Determina o meio do vetor
		Merge_Sort(V, inicio, meio);        // Chama a função para a primeira metade
		Merge_Sort(V, meio+1, fim);         // Chama a função para a segunda metade
		Merge(V, inicio, meio, fim);        // Combina as duas metades de forma ordenada
	}
}

void Merge(int *V, int inicio, int meio, int fim)
{
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1=0, fim2=0;
	tamanho = fim-inicio+1;
	p1 = inicio;                                    // P1 percorre a primeira metade de V
	p2 = meio+1;                                    // P2 percorre a segunda metade de V
	temp = (int *) malloc(tamanho*sizeof(int));     // Vetor temporário em que será feita a ordenação
	if(temp != NULL)
	{
		for(i=0; i<tamanho; i++)
		{
			if(!fim1 && !fim2)                      // Encerra quando fim1 = 1 ou fim2 = 1
			{
				if(V[p1]<V[p2])                     // Se V[p1] < V[p2]
					temp[i]=V[p1++];                // Temp[i] = V[p1]; p1++
				else
					temp[i]=V[p2++];                // Temp[i] = V[p2]; p2++
				if(p1>meio)                         // Primeira metade do vetor foi percorrida totalmente
					fim1=1;
				if(p2>fim)                          // Segunda metade do vetor foi percorrida totalmente 
					fim2=1;
			}
			else
			{
				if(!fim1)                           // Copia o restante de p1 caso p2 acabe
					temp[i]=V[p1++];
				else                                // Copia o restante de p2 caso p1 acabe
					temp[i]=V[p2++];
			}
		}

		for(j=0, k=inicio; j<tamanho; j++, k++)     // Copia os dados do vetor auxiliar para o original
			V[k]=temp[j];
	}
	free(temp);                                     // esvazia o vetor temporário
}


int main()
{
    int fim = 9;
    int vetorTeste[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    for(int i = 0; i < 9; i++)
        printf("%d \n", vetorTeste[i]);

    Merge_Sort(vetorTeste, 0, fim);
    
    printf("\n");

    for(int i = 0; i < 9; i++)
        printf("%d \n", vetorTeste[i]);

    return 0;
}
