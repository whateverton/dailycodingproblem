/*
#35 - Hard
This problem was asked by Google.

Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].

Date: 20/07/2020
*/
#ifdef VS_IDE
#include "helper.h"
#endif

// Alternative O(n log2 n)
void merge(char* buffer, int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    char *L, *R;

    L = (char*)malloc(sizeof(char) * n1);
    R = (char*)malloc(sizeof(char) * n2);

    for (i = 0; i < n1; i++)
        L[i] = buffer[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = buffer[meio + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = inicio; // Initial index of merged subarray 
    while (i <= n1 && j <= n2) {
        if (L[i] < R[j]) {
            buffer[k] = L[i];
            i++;
        }
        else {
            buffer[k] = R[j];
            j++;
        }
        k++;
    }

    while (i <= n1) {
        buffer[k] = L[i];
        i++;
        k++;
    }

    while (j <= n2) {
        buffer[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}


void mergeSort(char* buffer, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(buffer, inicio, meio);
        mergeSort(buffer, meio + 1, fim);
        merge(buffer, inicio, meio, fim);
    }
}


void orderRGB2(char* data, size_t size)
{
    mergeSort(data, 0, size - 1);
}

// ================================================

// O(n²)
void orderRGB(char *data, size_t size)
{
	if (size <= 1)
		return;

	for (size_t i = 1; i < size; ++i)
	{
		if (data[i - 1] < data[i])
		{
			// Swap in-place
			char temp = data[i - 1];
			data[i - 1] = data[i];
			data[i] = temp;
		}
	}

	orderRGB(data, size - 1);
}

#ifdef VS_IDE
void problem35()
#else
void main()
#endif
{
	char test[] = { 'G', 'B', 'R', 'R', 'B', 'R', 'G', 0};

	std::cout << "Before ordering: "<< test << std::endl;
	orderRGB(test, ARRAY_SIZE(test) - 1);
	std::cout << "After ordering: " << test << std::endl;
}
