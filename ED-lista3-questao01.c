/*
** Função : Ordenação por seleção
** Autor : David Ramalho Teixeira de Carvalho
** Data : 30/05/2024
** Observações: Este programa ordena um vetor pré-definido usando o algoritmo de seleção e imprime a lista original e a lista ordenada.
*/

#include <stdio.h>

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i, j, min_idx, temp;

    printf("Lista original:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < size-1; i++) {
        min_idx = i;
        for (j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    printf("Lista ordenada:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
