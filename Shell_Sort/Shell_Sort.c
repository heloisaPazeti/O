// Heap Sort in C

#include <stdio.h>

void Shell_Sort(int *V, int N)
{
	int i, j, h, aux;
	h = 1;

	while(h < N/3)              // Calcula o h inicial
		h=3*h+1;

	while(h > 0)
	{
		for(i=h; i<N; i++)
		{
			aux = V[i];
			j=i;
			while(j>=h && aux < V[j-h])     // comapra os elementos com distância h
			{
				V[j] = V[j-h];
				j = j-h;
			}
			V[j] = aux;
		}
		h = (h-1)/3;                        // atualiza o valor de h
	}
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    Shell_Sort(arr, N);
    printf("Sorted array is\n");
    printArray(arr, N);
}