/*
** Função: Classificação de elementos de um vetor usando QuickSort
** Autor: David Ramalho Teixeira de Carvalho
** Data: 31/05/2024
** Observações: Este programa classifica os elementos de um vetor em ordem crescente usando o algoritmo QuickSort.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int vetor[], int baixo, int alto) {
    int pivo = vetor[(baixo + alto) / 2];
    int i = baixo;
    int j = alto;

    while (i <= j) {
        while (vetor[i] < pivo) {
            i++;
        }
        while (vetor[j] > pivo) {
            j--;
        }
        if (i <= j) {
            troca(&vetor[i], &vetor[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int indice_particao = particiona(vetor, baixo, alto);
        quicksort(vetor, baixo, indice_particao - 1);
        quicksort(vetor, indice_particao, alto);
    }
}

void imprime_vetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    srand(time(NULL));
    int tamanho = 10;
    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }

    printf("Vetor original:\n");
    imprime_vetor(vetor, tamanho);

    quicksort(vetor, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    imprime_vetor(vetor, tamanho);

    return 0;
}
